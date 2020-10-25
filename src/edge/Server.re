[@bs.module "cookie-parser"] external cookieParser: unit => 'a = "default";

[@bs.module "https"]
external createSecureServer: ('a, 'c) => 'b = "createServer";

// [@bs.module "./bin/mocker.js"] [@bs.module "mocker"]
// external mocker: (string, string, Express.Middleware.f) => 'a = "default";

// let isDevelopment = DotenvConfig.getBool("IS_DEVELOPMENT");
[@bs.val] external isDevelopment: bool = "process.env.IS_DEVELOPMENT";

DotenvConfig.init();

if (isDevelopment) {
  %raw
  "process.env['NODE_TLS_REJECT_UNAUTHORIZED'] = 0";
};

let cfg = DotenvConfig.makeClientConfig();
let basePath = isDevelopment ? "./dist" : "./";
let publicPath = Node.Path.join2(basePath, "public");

Js.log2("trying to get port value...");
let port = DotenvConfig.getInt(~default=7443, "PORT");
Js.log2("port = ", port);
let app = Express.express();

Express.App.disable(app, ~name="x-powered-by");

Express.App.use(app, cookieParser());

Express.App.use(
  app,
  Express.Static.defaultOptions()
  |> Express.Static.make(publicPath)
  |> Express.Static.asMiddleware,
);

if (isDevelopment) {
  // TODO Create bucklescript bindings
  //  .use('/api/v1', (req, res) => {
  //    mocker('/api/v1', 'tests/fixtures/api')(req, res);
  //  })
  ()
};

// Proxy API requests
Express.App.useOnPath(app, ~path="/api", ApiProxy.make(~prefix="/api", ()));

let manifest = ServerManifest.manifest(basePath);
let chunksClient = ServerManifest.chunksClient(basePath);

let html = ServerManifest.html(basePath);

let router = EdgeRouter.middleware();

let auth = EdgeAuth.middleware();

let edge = Edge.make(~cfg, ~manifest, ~chunksClient, ~html, ());

Express.App.getWithMany(
  app,
  ~path="*",
  [|auth, router, Express.PromiseMiddleware.from(edge)|],
);

let server =
  isDevelopment
    ? createSecureServer(
        {
          "key": Node.Fs.readFileSync("server.key", `binary),
          "cert": Node.Fs.readFileSync("server.cert", `binary),
        },
        app,
      )
    : app;

Express.App.listen(
  server,
  ~port,
  ~hostname="0.0.0.0",
  ~onListen=_ => {Js.log("Edge started on port " ++ string_of_int(port))},
  (),
);
