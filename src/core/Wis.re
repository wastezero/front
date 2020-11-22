open Models;
open Api;

module AuthService = {
  type login_credentials = Protocol_v1_t.login_credentials;
  type login_credentials_wrapper = Protocol_v1_t.login_credentials_wrapper;
  let signin:
    login_credentials => Js.Promise.t(result(UserProfile.t, Request.error)) =
    form => {
      let payload: login_credentials_wrapper = {user: form};
      let decode = UserProfile.decode;

      Request.post(
        ~decode,
        "/api/v1/login",
        payload |> Atd.encode(Protocol_v1_bs.write_login_credentials_wrapper),
      );
    };

  type manager_registration_form = Protocol_v1_t.manager_registration_form;
  type manager_registration_form_wrapper = Protocol_v1_t.manager_registration_form_wrapper;

  let registerManager:
    manager_registration_form =>
    Js.Promise.t(result(Protocol_v1_t.registration_response, Request.error)) =
    form => {
      let payload: manager_registration_form_wrapper = {user: form};
      let decode = Atd.decode(Protocol_v1_bs.read_registration_response);

      Request.post(
        ~decode,
        "/api/v1/sign_up",
        payload
        |> Atd.encode(Protocol_v1_bs.write_manager_registration_form_wrapper),
      );
    };

  type restaurant_registration_form = Protocol_v1_t.restaurant_registration_form;
  type restaurant_registration_form_wrapper = Protocol_v1_t.restaurant_registration_form_wrapper;

  let registerRestaurant:
    restaurant_registration_form =>
    Js.Promise.t(result(Protocol_v1_t.registration_response, Request.error)) =
    form => {
      let payload: restaurant_registration_form_wrapper = {user: form};
      let decode = Atd.decode(Protocol_v1_bs.read_registration_response);

      Request.post(
        ~decode,
        "/api/v1/sign_up",
        payload
        |> Atd.encode(
             Protocol_v1_bs.write_restaurant_registration_form_wrapper,
           ),
      );
    };

  module BranchService = {
    let%private endpoint = "registration/branches";

    let grid = (~params=?, ()) => {
      let url = Endpoints.resource(~base=endpoint, ());

      Request.useGrid(~url, ~decode=Branch.grid, ~params?, ());
    };
  };

  module RestaurantService = {
    let%private endpoint = "registration/restaurants";

    let grid = (~params=?, ()) => {
      let url = Endpoints.resource(~base=endpoint, ());

      Request.useGrid(~url, ~decode=Restaurant.grid, ~params?, ());
    };
  };
};

module RestaurantService = {
  type t = Protocol_v1_t.restaurant;

  let%private endpoint = "admin_panel/restaurants";

  let grid = (~params=?, ()) => {
    let url = Endpoints.resource(~base=endpoint, ());

    Request.useGrid(~url, ~decode=Restaurant.grid, ~params?, ());
  };

  let view = id => {
    let url = Endpoints.resource(~base=endpoint, ~id, ());
    Request.useFetch(~url, ~decode=Restaurant.decode, ());
  };
};

module BranchService = {
  type t = Protocol_v1_t.branch;

  let%private endpoint = "admin_panel/branches";

  let grid = (~params=?, ()) => {
    let url = Endpoints.resource(~base=endpoint, ());

    Request.useGrid(~url, ~decode=Branch.grid, ~params?, ());
  };

  let view = id => {
    let url = Endpoints.resource(~base=endpoint, ~id, ());
    Request.useFetch(~url, ~decode=Branch.decode, ());
  };
};
