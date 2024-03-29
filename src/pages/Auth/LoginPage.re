open Models;
open Wis;

[@bs.module "assets/images/logo.png"] external logoUrl: string = "default";

[@react.component]
let make = () => {
  let (user, dispatch) = Auth.UserContext.useUser();
  let (_, dispatchToasts) = Toast.ToastsContext.useToasts();
  let (_, dispatchCtx) = Auth.CtxContext.useCtx();
  let url = Route.useUrl();

  let handleRouteNavigation = () => {
    let return_to = Route.getParamValue(~url, "return_to", ());
    switch (user) {
    | Authorized(user) =>
      let name = user.name;
      switch (return_to) {
      | Some(uri) => ReasonReactRouter.push(uri)
      | None =>
        dispatchToasts(
          Add({
            id: Toast.generateId(),
            text: {j|Welcome back, $name|j},
            kind: `success,
            subtext: {j|We are happy to see you again|j},
            onClick: () => (),
          }),
        );
        Route.navigateTo(Account(Home));
      };
    | Loading => ()
    | Guest => ()
    };
  };

  // let (passwordHidden, setPasswordHidden) = React.useState(() => true);

  let form = Form.useForm(~submit=AuthService.signin);

  let email = Form.useField(~form, ~initialValue="", value => Ok(value));
  let password = Form.useField(~form, ~initialValue="", value => Ok(value));

  let onSubmitForm = (credentials: AuthService.login_credentials) => {
    Js.Promise.(
      form.submit(credentials)
      |> then_(result => {
           let () =
             switch (result) {
             | Ok((profile: UserProfile.t)) =>
               dispatch(
                 Auth.UserAuthenticated(
                   profile,
                   () => {
                     Config.saveUserToken(
                       Some(profile.authentication_token),
                     );
                     // TODO Redirect to intended route instead of Home
                     handleRouteNavigation();
                   },
                 ),
               )
             | Error((err: Request.error)) =>
               dispatchToasts(
                 Add({
                   id: Toast.generateId(),
                   text: err.message,
                   subtext: err.message,
                   kind: `warning,
                   onClick: () => (),
                 }),
               )
             };
           resolve(result);
         })
    )
    |> ignore;
  };
  <div
    className="min-h-screen bg-gray-50 flex flex-col justify-center py-12 sm:px-6 lg:px-8">
    <div className="sm:mx-auto sm:w-full sm:max-w-md">
      // <img className="mx-auto h-12 w-auto" src=logoUrl alt="Workflow" />

        <h2
          className="text-center text-3xl leading-9 font-extrabold text-gray-900">
          {React.string({j|WasteZero|j})}
        </h2>
      </div>
    <div className="mt-8 sm:mx-auto sm:w-full sm:max-w-md">
      <div className="bg-white py-8 px-4 shadow sm:rounded-lg sm:px-10">
        <h3
          className="text-left text-2xl leading-6 font-extrabold text-gray-900">
          {React.string({j|Sign in to your account|j})}
        </h3>
        <form
          onSubmit={ev => {
            onSubmitForm({email: email.value, password: password.value});
            ReactEvent.Synthetic.preventDefault(
              ReactEvent.toSyntheticEvent(ev),
            );
          }}
          method="POST"
          className="mt-4">
          <div>
            <label
              htmlFor="email"
              className="block text-sm font-medium leading-5 text-gray-700">
              {React.string({j|Email address|j})}
            </label>
            <div className="mt-1 rounded-md shadow-sm">
              <Input
                type_="email"
                required=true
                className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md placeholder-gray-400 focus:outline-none focus:shadow-outline-blue focus:border-blue-300 transition duration-150 ease-in-out sm:text-sm sm:leading-5"
                value={email.value}
                onChange={value => email.onChange(value)}
              />
            </div>
          </div>
          <div className="mt-6">
            <label
              htmlFor="password"
              className="block text-sm font-medium leading-5 text-gray-700">
              {React.string({j|Password|j})}
            </label>
            <div className="mt-1 rounded-md shadow-sm">
              <Input
                value={password.value}
                onChange={value => password.onChange(value)}
                type_="password"
                required=true
                className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md placeholder-gray-400 focus:outline-none focus:shadow-outline-blue focus:border-blue-300 transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              />
            </div>
          </div>
          <div className="mt-6 flex items-center justify-between">
            <div className="flex items-center">
              <input
                id="remember_me"
                type_="checkbox"
                className="form-checkbox h-4 w-4 text-indigo-600 transition duration-150 ease-in-out"
              />
              <label
                htmlFor="remember_me"
                className="ml-2 block text-sm leading-5 text-gray-900">
                {React.string({j|Remember me|j})}
              </label>
            </div>
            <div className="text-sm leading-5">
              <a
                href="#"
                className="font-medium text-indigo-600 hover:text-indigo-500 focus:outline-none focus:underline transition ease-in-out duration-150">
                {React.string({j|Forgot your password?|j})}
              </a>
            </div>
          </div>
          <div className="mt-6">
            <span className="block w-full rounded-md shadow-sm">
              <Button
                type_="submit"
                disabled={form.isSubmitting}
                state={form.isSubmitting ? `Loading : `Default}
                className="w-full flex justify-center py-2 px-4 border border-transparent text-sm font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition duration-150 ease-in-out">
                {React.string({j|Sign in|j})}
              </Button>
            </span>
          </div>
          <p
            className="mt-2 text-center text-sm leading-5 text-gray-600 max-w">
            {React.string({j|Or|j})}
            <Link
              route={Route.Auth(Register(Choose))}
              className="font-medium text-indigo-600 hover:text-indigo-500 focus:outline-none focus:underline transition ease-in-out duration-150">
              {React.string({j| register here|j})}
            </Link>
          </p>
        </form>
        <div className="mt-6">
          <div className="relative">
            <div className="absolute inset-0 flex items-center">
              <div className="w-full border-t border-gray-300" />
            </div>
            <div className="relative flex justify-center text-sm leading-5">
              <span className="px-2 bg-white text-gray-500">
                {React.string({j|© WasteZero - 2020|j})}
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>;
};
