let getCtx = url =>
  if (Js.String.startsWith("/admin", url)) {
    "admin";
  } else {
    "user";
  };

let getServerUrl =
  fun
  | ""
  | "/" => None
  | url => Some(url);

let make = () => {
  // Prepare middleware, initialize app config
  ();

  (next, req: Express.Request.t, res) => {
    let url = Express.Request.path(req) |> Route.getRouterUrl;
    Js.log2("Edge : Router", url.path);
    let route = Route.ofUrl(url);
    switch (route) {
    | Route.NotFound =>
      Express.Response.sendStatus(Express.Response.StatusCode.NotFound, res)
    | _ => next(Express.Next.middleware, res)
    };
  };
};

let middleware = () => make() |> Express.Middleware.from;
