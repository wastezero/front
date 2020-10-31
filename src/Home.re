open Auth;

[@react.component]
let make = () => {
  let (user, _) = UserContext.useUser();

  let url = Route.useUrl();
  let route = Route.ofUrl(url);

  React.useEffect2(
    () => {
      switch (user) {
      | Guest =>
        switch (route) {
        | Auth(_) => ()
        | _ => ReasonReact.Router.push(Route.toString(Auth(Login)))
        }
      | Loading => ()
      | Authorized((_user: Models.UserProfile.t)) =>
        switch (route) {
        | Auth(_) => ReasonReact.Router.push(Route.toString(Account(Home)))
        | _ => ()
        }
      };

      None;
    },
    (user, route),
  );

  switch (user) {
  | Loading => React.string("Loading")
  | _ =>
    switch (route) {
    | Auth(Login) => <LoginPage />
    | Auth(Register(Choose)) => <RegistrationChoosePage />
    | Auth(Register(Restaurant)) => <RegistrationRestaurantPage />
    | Auth(Register(Manager)) => <RegistrationManagerPage />
    | Account(page) => <HomePage page />
    | NotFound => React.string("404")
    }
  };
};
