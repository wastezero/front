/* Http requests */
type error = Protocol_v1_t.error;

let decodeError: Atdgen_codec_runtime.Json.t => error =
  Atd.decode(Protocol_v1_bs.read_error);

type state('data) = [ | `Loading | `Error(error) | `Data('data)];

type action('data) = [ | `Fetch | `Fetched('data) | `Failed(error)];

type grid('data) = Atd.Grid_wrap.t('data);

type params = {
  filter: list((string, Js.Json.t)),
  paginate: Paginate.t,
};

let processResponse = (decode, resp: Fetch.Response.t) =>
  Js.Promise.(
    Fetch.Response.json(resp)
    |> then_(json =>
         if (Fetch.Response.ok(resp)) {
           Ok(json |> decode) |> resolve;
         } else {
           switch (json |> decodeError) {
           | error =>
             Js.log2("req error", error);
             Error(error) |> resolve;
           | exception exn =>
             Js.log2("req exn", exn);
             reject(exn);
           };
         }
       )
    |> catch(err => {
         Js.log2("response parse error", err);
         let error: Protocol_v1_t.error = {
           status: 1,
           message: "Unexpected server error",
           errors: [],
         };
         resolve(Error(error));
       })
  );

let get:
  (~headers: 'a=?, ~decode: Js.Json.t => 't, string) =>
  Js.Promise.t(result('t, error)) =
  (~headers as _=?, ~decode, url) => {
    HttpClient.get(url) |> Js.Promise.then_(processResponse(decode));
  };

let post:
  (~headers: 'a=?, ~decode: Js.Json.t => 't, string, Js.Json.t) =>
  Js.Promise.t(result('t, error)) =
  (~headers=?, ~decode, url, payload) => {
    HttpClient.post(~headers?, url, payload)
    |> Js.Promise.then_(processResponse(decode));
  };

let put:
  (~headers: 'a=?, ~decode: Js.Json.t => 't, string, Js.Json.t) =>
  Js.Promise.t(result('t, error)) =
  (~headers=?, ~decode, url, payload) => {
    HttpClient.put(~headers?, url, payload)
    |> Js.Promise.then_(processResponse(decode));
  };
let useGrid = (~url: string, ~params=?, ~decode, ()) => {
  let (state, dispatch) =
    ReactUpdate.useReducer(`Loading, (action, _) => {
      switch (action) {
      | `Fetch =>
        ReactUpdate.UpdateWithSideEffects(
          `Loading,
          ({send}) => {
            open Js.Promise;
            let uri =
              switch (params) {
              | Some({filter, paginate}) =>
                let query =
                  Js.Dict.fromList([
                    ("filter", Js.Json.object_(Js.Dict.fromList(filter))),
                    ("paginate", paginate |> Paginate.encode),
                  ])
                  |> BsQs.stringify;

                {j|$(url)?$(query)|j};
              | None => url
              };
            Js.log2("uri", uri);

            get(~decode, uri)
            |> then_(result =>
                 switch (result) {
                 | Ok(data) => send(`Fetched(data)) |> resolve
                 | Error(err) => send(`Failed(err)) |> resolve
                 }
               )
            |> ignore;
            None;
          },
        )
      | `Fetched(data) => Update(`Data(data))
      | `Failed(err) => Update(`Error(err))
      }
    });

  React.useEffect1(
    () => {
      dispatch(`Fetch);
      None;
    },
    [|params|],
  );

  state;
};

let useFetch = (~url: string, ~decode, ()) => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | `Fetch => `Loading
        | `Fetched(data) => `Data(data)
        | `Failed(err) => `Error(err)
        },
      `Loading,
    );

  React.useEffect1(
    () => {
      dispatch(`Fetch);
      None;
    },
    [|url|],
  );

  React.useEffect1(
    () => {
      open Js.Promise;
      switch (state) {
      | `Loading =>
        get(~decode, url)
        |> then_(result =>
             switch (result) {
             | Ok(data) => dispatch(`Fetched(data)) |> resolve
             | Error(err) => dispatch(`Failed(err)) |> resolve
             }
           )
        |> ignore
      | _ => ()
      };

      None;
    },
    [|state|],
  );

  state;
};

let useParams = (~filters, ~limit=?, ()) => {
  open Paginate;
  let justInitialized = React.useRef(true);

  let (pageUrlParam, setPageUrlParam) = Route.useParamValue("page");
  let pageInitialValue =
    pageUrlParam |> Belt.Option.mapWithDefault(_, 1, int_of_string);

  let (params, setParams) =
    React.useState(() =>
      {
        filter: filters,
        paginate: {
          page: pageInitialValue,
          limit,
        },
      }
    );

  let (isLastPage, setIsLastPage) = React.useState(() => false);
  let setIsLastPage = value => setIsLastPage(_ => value);

  React.useEffect1(
    () => {
      if (!justInitialized.current) {
        setParams(_ =>
          {
            filter: filters,
            paginate: {
              ...params.paginate,
              page: 1,
            },
          }
        );
        setPageUrlParam(Some(1 |> string_of_int));
      };
      justInitialized.current = false;
      None;
    },
    [|filters|],
  );

  let onSearch = searchText => {
    let filters = filters @ [("query", searchText |> Js.Json.string)];
    setParams(_ => {...params, filter: filters});
  };

  let onPaginate = page => {
    setParams(_ => {
                     ...params,
                     paginate: {
                       ...params.paginate,
                       page,
                     },
                   });
    setPageUrlParam(Some(page |> string_of_int));
  };

  (params, onSearch, onPaginate, isLastPage, setIsLastPage);
};

let useUrlFilters = (~filters) => {
  let (filters, setFilters) = React.useState(() => filters);

  React.useEffect1(
    () => {
      setFilters(_ => filters);
      None;
    },
    [|filters|],
  );

  let updateFilter = (name, value) => {
    let filtersPopedName =
      filters |> Belt.List.keep(_, ((filterName, _)) => filterName != name);
    setFilters(_ => filtersPopedName @ [(name, Js.Json.string(value))]);
  };

  (filters, updateFilter);
};

let useFilters = ((name1, value1), (name2, value2)) => {
  let fieldsToFilterList = () => {
    let list =
      [(name1, value1), (name2, value2)]
      |> Belt.List.keepMap(_, ((name, value)) =>
           Belt.Option.map(value, value => (name, Js.Json.string(value)))
         );
    list;
  };
  let (filters, setFilters) = React.useState(() => fieldsToFilterList());

  React.useEffect2(
    () => {
      setFilters(_ => fieldsToFilterList());
      None;
    },
    (value1, value2),
  );

  (filters, setFilters);
};

let useFilters2 = ((name1, value1), (name2, value2)) => {
  let justInitialized = React.useRef(true);
  let fieldsToFilterList = () => {
    let list =
      [(name1, value1), (name2, value2)]
      |> Belt.List.keepMap(_, ((name, value)) =>
           Belt.Option.map(value, value => (name, Js.Json.string(value)))
         );
    list;
  };
  let (filters, setFilters) = React.useState(() => fieldsToFilterList());

  React.useEffect2(
    () => {
      if (!justInitialized.current) {
        setFilters(_ => fieldsToFilterList());
      };
      justInitialized.current = false;
      None;
    },
    (value1, value2),
  );

  (filters, setFilters);
};
