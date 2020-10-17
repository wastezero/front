open Belt;

[%raw "require('isomorphic-fetch')"];

[@bs.module "ua-parser-js"] external uaParser: 'a => 'b = "default";

let make = (~cfg, ~manifest, ~chunksClient, ~html, ()) => {
  // Prepare middleware, initialize app config
  let serializedConfig = Render.serializeClientConfig(cfg);
  Global.setConfig(Global.global, Global.fromJson(serializedConfig));

  (_next, req: Express.Request.t, res) => {
    let ua = Express.Request.get("user-agent", req) |> uaParser;

    let deviceType =
      Js.Dict.get(ua, "device")
      |> Option.mapWithDefault(_, None, device => Js.Dict.get(device, "type"));

    let uri = Express.Request.path(req);

    let authzCookie =
      Express.Request.cookies(req)
      |> Option.mapWithDefault(_, None, cookies =>
           Js.Dict.get(cookies, "ipsys-token")
         )
      |> Option.mapWithDefault(_, None, token =>
           Some(Json.Decode.string(token))
         );

    let serverUrl = EdgeRouter.getServerUrl(uri);
    let ctx = EdgeRouter.getCtx(uri);

    let userPromise =
      switch (authzCookie) {
      | Some(token) =>
        let headers =
          Fetch.Headers.makeWithInit(
            Fetch.HeadersInit.make({"Cookie": {j|ipsys-token=$(token)|j}}),
          );

        Js.Promise.(
          Auth.fetchUserProfile(~headers, 0)
          |> then_(result => {
               let user =
                 Result.mapWithDefault(result, None, user => Some(user));

               resolve(user);
             })
        );

      | None => Js.Promise.resolve(None)
      };

    Js.Promise.(
      userPromise
      |> then_(user => {
           let state: Config.state = {
             serverUrl,
             ctx,
             user,
             prefetched: true,
             deviceType:
               switch (deviceType) {
               | Some(d) => Js.Nullable.isNullable(d) ? "" : d
               | None => ""
               },
           };

           let serializedState = Render.serializeState(state);
           Global.setState(Global.global, Global.fromJson(serializedState));

           let rendered =
             Render.app(
               ~deviceType,
               ~cfg,
               ~state,
               ~manifest,
               ~chunksClient,
               ~html,
             );

           Express.Response.sendString(rendered, res) |> resolve;
         })
    );
  };
};
