/* Http requests */
type error = Protocol_v1_t.error;
let decodeError: Atdgen_codec_runtime.Json.t => error =
  Atd.decode(Protocol_v1_bs.read_error);

type state('data) = [ | `Loading | `Error(error) | `Data('data)];

type action('data) = [ | `Fetch | `Fetched('data) | `Failed(error)];

type params = {
  filter: list((string, Js.Json.t)),
  params: option(list((string, Js.Json.t))),
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
  (
    ~headers: 'a=?,
    ~responseHandler: (Js.Json.t => 't, Fetch.response) =>
                      Js.Promise.t(result('t, error))
                        =?,
    ~decode: Js.Json.t => 't,
    string
  ) =>
  Js.Promise.t(result('t, error)) =
  (~headers=?, ~responseHandler=?, ~decode, url) => {
    let responseHandler =
      Belt.Option.getWithDefault(responseHandler, processResponse);

    HttpClient.get(~headers?, url)
    |> Js.Promise.then_(responseHandler(decode));
  };

let post:
  (
    ~headers: 'a=?,
    ~responseHandler: (Js.Json.t => 't, Fetch.response) =>
                      Js.Promise.t(result('t, error))
                        =?,
    ~decode: Js.Json.t => 't,
    string,
    Js.Json.t
  ) =>
  Js.Promise.t(result('t, error)) =
  (~headers=?, ~responseHandler=?, ~decode, url, payload) => {
    let responseHandler =
      Belt.Option.getWithDefault(responseHandler, processResponse);
    HttpClient.post(~headers?, url, payload)
    |> Js.Promise.then_(responseHandler(decode));
  };

let put:
  (
    ~headers: 'a=?,
    ~responseHandler: (Js.Json.t => 't, Fetch.response) =>
                      Js.Promise.t(result('t, error))
                        =?,
    ~decode: Js.Json.t => 't,
    string,
    Js.Json.t
  ) =>
  Js.Promise.t(result('t, error)) =
  (~headers=?, ~responseHandler=?, ~decode, url, payload) => {
    let responseHandler =
      Belt.Option.getWithDefault(responseHandler, processResponse);

    HttpClient.put(~headers?, url, payload)
    |> Js.Promise.then_(responseHandler(decode));
  };

let useGrid = (~headers: 'a=?, ~url: string, ~params=?, ~decode, ()) => {
  let justInitialized = React.useRef(true);
  let routeUrl = Route.useUrl();

  let (page, setPage) = React.useState(() => 1);

  let (state, dispatch) =
    ReactUpdate.useReducer(`Loading, (action, _) => {
      switch (action) {
      | `Fetch =>
        ReactUpdate.UpdateWithSideEffects(
          `Loading,
          ({send}) => {
            open Js.Promise;
            let uri = {
              let urlParams = [
                ("page", Js.Json.number(page |> float_of_int)),
              ];
              switch (params) {
              | Some({filter, params}) =>
                let query =
                  Js.Dict.fromList(
                    urlParams
                    @ [
                      ("filter", Js.Json.object_(Js.Dict.fromList(filter))),
                      ...Belt.Option.mapWithDefault(params, [], params =>
                           params
                         ),
                    ],
                  )
                  |> BsQs.stringify;

                {j|$(url)?$(query)|j};
              | None =>
                let query = Js.Dict.fromList(urlParams) |> BsQs.stringify;

                {j|$(url)?$(query)|j};
              };
            };
            Js.log2("uri", uri);

            get(~headers?, ~decode, uri)
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

  let onPaginate = (action: Paginate.action) => {
    let page =
      switch (action) {
      | Next => page + 1
      | Previous => page - 1
      };
    setPage(_ => page);
  };

  React.useEffect1(
    () => {
      if (!justInitialized.current) {
        dispatch(`Fetch);
      };
      None;
    },
    [|params|],
  );

  React.useEffect1(
    () => {
      dispatch(`Fetch);
      justInitialized.current = false;
      None;
    },
    [|page|],
  );

  (state, page, onPaginate);
};

let useFetch = (~url: string, ~decode, ~headers=?, ~params=?, ()) => {
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
        let uri =
          switch (params) {
          | Some(params) =>
            let query = Js.Dict.fromList(params) |> BsQs.stringify;

            {j|$(url)?$(query)|j};
          | None => url
          };
        Js.log2("uri", uri);
        get(~headers?, ~decode, uri)
        |> then_(result =>
             switch (result) {
             | Ok(data) => dispatch(`Fetched(data)) |> resolve
             | Error(err) => dispatch(`Failed(err)) |> resolve
             }
           )
        |> ignore;
      | _ => ()
      };

      None;
    },
    [|state|],
  );

  state;
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
