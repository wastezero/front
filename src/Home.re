open Auth;

[@react.component]
let make = () => {
  let (user, _) = UserContext.useUser();

  let url = Route.useUrl();
  let route = Route.ofUrl(url);

  let (ctx, dispatchCtx) = Auth.CtxContext.useCtx();

  React.useEffect2(
    () => {
      switch (user) {
      | Guest =>
        switch (route) {
        | Auth(_) => ()
        | _ => ReasonReact.Router.push(Route.toString(Auth(Login)))
        }
      | Loading => ()
      | Authorized((user: Models.UserProfile.t)) =>
        dispatchCtx(CtxChanged(Auth.getInitialCtx(user.role)));
        switch (route) {
        | Auth(_) => ReasonReact.Router.push(Route.toString(Account(Home)))
        | _ => ()
        };
      };

      None;
    },
    (user, route),
  );

  switch (user) {
  | Loading => <LoadingSpinner />
  | Guest =>
    switch (route) {
    | Auth(Register(Choose)) => <RegistrationChoosePage />
    | Auth(Register(Restaurant)) => <RegistrationRestaurantPage />
    | Auth(Register(Manager)) => <RegistrationManagerPage />
    | Auth(Login)
    | _ => <LoginPage />
    }
  | Authorized(_) =>
    switch (ctx) {
    | Route.ClientCtx =>
      React.string({j|you don't have access to this platform|j})
    | _ =>
      switch (route) {
      | Auth(Login) => <LoginPage />
      | Auth(Register(Choose)) => <RegistrationChoosePage />
      | Auth(Register(Restaurant)) => <RegistrationRestaurantPage />
      | Auth(Register(Manager)) => <RegistrationManagerPage />
      | Account(page) => <HomePage page />
      | NotFound => React.string("404")
      }
    }
  };
};
