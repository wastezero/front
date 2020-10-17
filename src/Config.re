open Belt;

// Up to 4 digits after `.`
Big.setDP(4);
// ROUND_HALF_UP
Big.setRM(1);

type cfg = Protocol_v1_t.cfg;
type state = Protocol_v1_t.app_state;

let%private defaultCfg: cfg = {
  app_url: "",
  cms_api_url: "",
  app_env: "local",
  ym_key: "",
  analytics_key: "",
};
let%private defaultState: state = {
  serverUrl: None,
  ctx: "user",
  user: None,
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

let svcCashWithdrawal = 1;
