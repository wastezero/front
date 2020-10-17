let%private serializeClientConfig: Config.cfg => Js.Json.t =
  Atd.encode(Protocol_v1_bs.write_cfg);

let%private serializeState: Config.state => Js.Json.t =
  Atd.encode(Protocol_v1_bs.write_app_state);

let withInjectedViewport = (~scale: float, html) => {
  let width = scale === 1.0 ? "device-width" : "1216";

  let injected =
    html
    |> Js.String.replace(
         "<!-- viewport -->",
         {j|<meta name="viewport" content="width=$width, initial-scale=$scale" />|j},
       );

  injected;
};

let withInjectedConfig = (~cfg: Config.cfg, html) => {
  let config = cfg |> serializeClientConfig |> Json.stringify;

  let injected =
    html
    |> Js.String.replace(
         "<!-- cfg -->",
         {j|<script>window.__CFG__ = $(config);</script>|j},
       );

  injected;
};

let withInjectedState = (~state: Config.state, html) => {
  let state = state |> serializeState |> Json.stringify;

  let injected =
    html
    |> Js.String.replace(
         "<!-- state -->",
         {j|<script>window.__STATE__ = $(state);</script>|j},
       );

  injected;
};

let inject = (~cfg: Config.cfg, ~url: string, ~prefetched=false, html) => {
  let ctx = EdgeRouter.getCtx(url);
  let serverUrl = EdgeRouter.getServerUrl(url);

  let state: Config.state = {
    serverUrl,
    ctx,
    user: None,
    prefetched,
    deviceType: "desktop",
  };

  html |> withInjectedConfig(~cfg) |> withInjectedState(~state);
};
