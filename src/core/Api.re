module Endpoints = {
  let resource = (~base, ~id=?, ()) => {
    let baseUri = {j|/api/v1/$base|j};
    switch (id) {
    | Some(id) =>
      let id = string_of_int(id);
      {j|$baseUri/$id|j};
    | None => baseUri
    };
  };

  let contracts = resource(~base="emoney/contracts");
};
