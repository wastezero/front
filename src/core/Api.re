module Endpoints = {
  let resource = (~base, ~account, ~id=?, ()) => {
    let account = string_of_int(account);
    let baseUri = {j|/api/v1/accounts/$account/$base|j};

    switch (id) {
    | Some(id) =>
      let id = string_of_int(id);
      {j|$baseUri/$id|j};
    | None => baseUri
    };
  };

  module Crm = {
    let tickets = (~id=?, ()) => {
      let baseUri = {j|/api/v1/crm/tickets|j};
      switch (id) {
      | Some(id) =>
        let id = string_of_int(id);
        {j|$baseUri/$id|j};
      | None => baseUri
      };
    };

    let accounts = (~id=?, ()) => {
      let baseUri = {j|/api/v1/crm/accounts|j};
      switch (id) {
      | Some(id) =>
        let id = string_of_int(id);
        {j|$baseUri/$id|j};
      | None => baseUri
      };
    };

    let accountTickets = (~account, ~id=?, ()) => {
      let baseUri = {j|/api/v1/accounts/$account/crm/tickets|j};
      switch (id) {
      | Some(id) =>
        let id = string_of_int(id);
        {j|$baseUri/$id|j};
      | None => baseUri
      };
    };
  };

  let items = resource(~base="items");

  let warehouses = resource(~base="sklad/warehouses");

  module Kassa = {
    let kkms = resource(~base="kassa/kkms");
    let reports = resource(~base="kassa/reports");

    let sales = resource(~base="kassa/sales");
  };
};
