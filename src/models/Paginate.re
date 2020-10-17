type t = {
  page: int,
  limit: option(int),
};

let encode: t => Js.Json.t =
  paginate =>
    switch (paginate.limit) {
    | Some(limit) =>
      Json.Encode.(
        object_([("page", paginate.page |> int), ("limit", limit |> int)])
      )
    | None => Js.Json.null
    };

let toTuple = paginate => {
  ("paginate", paginate |> encode);
};

let default = {page: 1, limit: None};
