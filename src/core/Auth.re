open Models;

type user =
  | Guest
  | Loading
  | Authorized(UserProfile.t);

type action =
  | UserRequested
  | UserReady(UserProfile.t)
  | UserAuthenticated(UserProfile.t, unit => unit)
  | UserSignedOut(unit => unit);

type ctx = Route.identityCtx;

type ctxAction =
  | CtxChanged(ctx);

type credentials = Protocol_v1_t.auth_credentials;
type credentials_wrapper = Protocol_v1_t.auth_credentials_wrapper;

let signin: credentials => Js.Promise.t(result(UserProfile.t, Request.error)) =
  form => {
    let payload: credentials_wrapper = {user: form};
    let decode = UserProfile.decode;

    Request.post(
      ~decode,
      "/api/v1/sign_in",
      payload |> Atd.encode(Protocol_v1_bs.write_auth_credentials_wrapper),
    );
  };

let fetchUserProfile = (~headers=?, _userId) => {
  // let payload = Atd.encode(Protocol_v1_bs.write_auth_profile, {id: userId});
  Request.post(
    ~headers?,
    ~decode=UserProfile.decode,
    "/api/v1/user/profile",
    Js.Json.null,
  );
};

module UserContext = {
  type dispatch = action => unit;
  type contextValue = (user, dispatch);

  let initValue: contextValue = (Guest, _ => ignore());

  let context = React.createContext(initValue);

  let useUser = () => React.useContext(context);
};

module UserProvider = {
  let make = React.Context.provider(UserContext.context);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

module CtxContext = {
  type dispatch = ctxAction => unit;
  type contextValue = (ctx, dispatch);

  let initValue: contextValue = (ManagerCtx, _ => ignore());

  let context = React.createContext(initValue);

  let useCtx = () => React.useContext(context);
};

module CtxProvider = {
  let make = React.Context.provider(CtxContext.context);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

let getInitialUser = (~prefetched, user) =>
  switch (user) {
  | Some(usr) => Authorized(usr)
  | None => prefetched ? Guest : Loading
  };

let getInitialCtx = ctx =>
  switch (ctx) {
  | _ => Route.ManagerCtx
  };

let useAuthContext = initialUser => {
  let (user, dispatchAuth) =
    ReactUpdate.useReducer(initialUser, (action, _) => {
      switch (action) {
      | UserRequested =>
        ReactUpdate.UpdateWithSideEffects(
          Loading,
          ({send}) => {
            open Js.Promise;

            fetchUserProfile(0)
            |> then_(result => {
                 switch (result) {
                 | Ok(profile) => send(UserReady(profile)) |> resolve
                 | Error(err) =>
                   // TODO Handle errors properly
                   Js.log2("user loading failure", err);
                   resolve();
                 }
               })
            |> ignore;

            None;
          },
        )
      | UserReady(profile) =>
        ReactUpdate.UpdateWithSideEffects(
          Authorized(profile),
          _ => {
            // Do nothing maybe?
            ();

            None;
          },
        )
      | UserAuthenticated(profile, onSignedIn) =>
        ReactUpdate.UpdateWithSideEffects(
          Authorized(profile),
          _ => {
            onSignedIn();

            None;
          },
        )
      | UserSignedOut(onSignedOut) =>
        ReactUpdate.UpdateWithSideEffects(
          Guest,
          _ => {
            onSignedOut();
            None;
          },
        )
      }
    });

  React.useEffect0(() => {
    if (user == Loading) {
      dispatchAuth(UserRequested);
    };

    None;
  });

  (user, dispatchAuth);
};

let useCtxContext = initialCtx => {
  let (ctx, dispatch) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | CtxChanged(ctx) => ctx
        },
      initialCtx,
    );

  (ctx, dispatch);
};
