[@bs.val] external isDev: bool = "process.env.IS_DEVELOPMENT";
let basePath = isDev ? "./dist" : "./";

let serializeClientConfig: Config.cfg => Js.Json.t =
  Atd.encode(Protocol_v1_bs.write_cfg);

let serializeState: Config.state => Js.Json.t =
  Atd.encode(Protocol_v1_bs.write_app_state);

let app =
    (
      ~deviceType,
      ~cfg: Config.cfg,
      ~state: Config.state,
      ~manifest as _,
      ~chunksClient,
      ~html,
    ) => {
  let extractorClient =
    LoadableComponents.chunkExtractor({stats: chunksClient});

  let route =
    switch (state.serverUrl) {
    | Some(url) => url |> Route.getRouterUrl |> Route.ofUrl
    | None => Route.Account(Home)
    };

  let scale =
    switch (route) {
    | Account(Home) => 1.0
    | _ =>
      switch (deviceType) {
      | Some("mobile") => 0.296
      | Some("tablet") => 0.632
      | _ => 1.0
      }
    };

  let html =
    html
    |> ClientRender.withInjectedViewport(~scale)
    |> ClientRender.withInjectedConfig(~cfg)
    |> ClientRender.withInjectedState(~state);

  let htmlHydrated = {
    /**
       * Collect js bundles from webpack manifest
       */

    let jsx =
      LoadableComponents.collectChunks(<App state />, extractorClient);

    let renderedApp = ReactDOMServerRe.renderToString(jsx);

    let extracted = renderedApp;
    // let extractedIds = Js.Array.joinWith(" ", extracted##ids);
    // let extractedCss = extracted##css;
    // let extractedHtml = extracted##html;

    let hydrated =
      html
      // |> Js.String.replace("<!-- style -->", styles)
      |> Js.String.replace(
           "<!-- script -->",
           LoadableComponents.getScriptTags(extractorClient),
         )
      |> Js.String.replace(
           "<div id=\"root\"></div>",
           {j|<div id="root">$extracted</div>|j},
         );

    hydrated;
  };

  htmlHydrated;
};
