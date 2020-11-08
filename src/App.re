open Auth;
open Toast;

[@react.component]
let make = (~state: Config.state) => {
  let _cfg = Config.getConfig();
  let initialUser = getInitialUser(~prefetched=state.prefetched, state.user);
  let initialCtx =
    getInitialCtx(
      Belt.Option.mapWithDefault(state.user, "client", user => user.role),
    );

  let (user, dispatchAuth) = useAuthContext(initialUser);
  let (ctx, dispatchCtx) = useCtxContext(initialCtx);
  let (toasts, dispatchToasts) = useToastsContext([]);

  <ToastsProvider value=(toasts, dispatchToasts)>
    <UserProvider value=(user, dispatchAuth)>
      <CtxProvider value=(ctx, dispatchCtx)> <Home /> </CtxProvider>
    </UserProvider>
    <ToastsContainer />
  </ToastsProvider>;
};
