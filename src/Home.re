open Auth;

[@react.component]
let make = () => {
  let (user, _) = UserContext.useUser();
  let (_ctx, _dispatchCtx) = CtxContext.useCtx();

  let url = Route.useUrl();
  let route = Route.ofUrl(url);

  // React.useEffect2(
  //   () => {
  //     switch (user) {
  //     | Guest =>
  //       switch (route) {
  //       | Account => ()
  //       | Login => ()
  //       // Guests can only see Login (Register/Reset) page and must be redirected for anything else
  //       | _ => ReasonReact.Router.push(Route.toString(Login))
  //       }
  //     | Loading => ()
  //     // Authenticated happens once when a user signs in
  //     | Authenticated((_user: Models.UserProfile.t))
  //     // Authorized happens on every initial page load
  //     | Authorized((_user: Models.UserProfile.t)) =>
  //       switch (route) {
  //       | Login
  //       | _ => ()
  //       }
  //     };

  //     switch (route) {
  //     | Account => dispatchCtx(CtxChanged(OperatorCtx))
  //     | _ => dispatchCtx(CtxChanged(UserCtx))
  //     };

  //     None;
  //   },
  //   (user, route),
  // );

  switch (user) {
  | Loading => React.string("Loading")
  | _ =>
    switch (route) {
    | Login => <LoginPage />
    | Register => <RegistrationPage />
    | _ => <HomePage />
    }
  };
};
