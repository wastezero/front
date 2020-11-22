open Belt;

// Up to 4 digits after `.`
Big.setDP(4);
// ROUND_HALF_UP
Big.setRM(1);

type cfg = Protocol_v1_t.cfg;
type state = Protocol_v1_t.app_state;

let serializeState: state => Js.Json.t =
  Atd.encode(Protocol_v1_bs.write_app_state);

let%private defaultCfg: cfg = {
  app_url: "",
  cms_api_url: "",
  app_env: "local",
  ym_key: "",
  analytics_key: "",
};
let%private defaultState: state = {
  serverUrl: None,
  user: None,
  token: None,
  prefetched: true,
  deviceType: "",
};

let getConfig = () => {
  Option.getWithDefault([%external __CFG__], defaultCfg);
};

let getState = () => {
  Option.mapWithDefault(
    [%external __STATE__], defaultState, (serialized: Js.Json.t) => {
    Protocol_v1_bs.read_app_state(serialized)
  });
};

let svcCardWithdrawal = 1;
let svcCashWithdrawal = 2;

let saveUserToken = payload => {
  switch (payload) {
  | Some(userId) =>
    Cookie.set(Cookie.document, "user-token-insecure=" ++ userId)
  | None => Cookie.set(Cookie.document, "")
  };

  let serializedState = serializeState({...getState(), token: payload});
  Global.setState(Global.global, Global.fromJson(serializedState));
};

let removeUserToken = () => {
  Cookie.set(
    Cookie.document,
    "user-token-insecure=; expires = Thu, 01 Jan 1970 00:00:00 GMT",
  );
};
