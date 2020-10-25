open Belt;

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
      ~manifest,
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
    | Account(_) => 1.0
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

  let htmlHydrated =
    switch (manifest) {
    | Some(decoded) =>
      /**
       * Collect js bundles from webpack manifest
       */
      let manifestKeys = Js.Dict.keys(decoded) |> List.fromArray;

      // let scripts =
      //   manifestKeys
      //   |> List.keep(_, js => Js.String.endsWith(".js", js))
      //   |> List.keepMap(_, js => Js.Dict.get(decoded, js))
      //   |> List.map(_, js => {j|<script src="/$js" async defer></script>|j})
      //   |> String.concat("");

      let jsx =
        LoadableComponents.collectChunks(<App state />, extractorClient);

      let renderedApp = ReactDOMServerRe.renderToString(jsx);

      let styles =
        manifestKeys
        |> List.keep(_, css => Js.String.endsWith(".css", css))
        |> List.keepMap(_, css => Js.Dict.get(decoded, css))
        |> List.map(_, css => {j|<link rel="stylesheet" href="/$css">|j})
        |> String.concat("");

      let hydrated =
        html
        |> Js.String.replace("<!-- style -->", styles)
        // |> Js.String.replace("<!-- script -->", scripts)
        |> Js.String.replace(
             "<!-- script -->",
             LoadableComponents.getScriptTags(extractorClient),
           )
        |> Js.String.replace(
             "<div id=\"root\"></div>",
             {j|<div id="root">$renderedApp</div>|j},
           );

      hydrated;
    | None => html
    };

  htmlHydrated;
};
