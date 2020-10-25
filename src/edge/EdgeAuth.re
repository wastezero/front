let make = () => {
  // Prepare middleware, initialize app config
  ();
  (next, _req: Express.Request.t, res) => {
    /*
     let authzCookie =
       Express.Request.cookies(req)
       |> Option.mapWithDefault(_, None, cookies =>
            Js.Dict.get(cookies, "ipsys-token-insecure")
          )
       |> Option.mapWithDefault(_, None, token =>
            Some(Json.Decode.string(token))
          );

     let url = Express.Request.path(req) |> Route.getRouterUrl;
     let route = Route.ofUrl(url);

     switch (authzCookie) {
     | None =>
       Route.isProtected(route)
         ? Express.Response.redirect(
             Route.urlWithParams(
               ~url=Auth(Login),
               [("return_to", route |> Route.toString)],
             ),
             res,
           )
         : next(Express.Next.middleware, res)
     | Some(_) =>
       switch (route) {
       | Auth(Login) =>
         Express.Response.redirect(Route.Account(Home) |> Route.toString, res)
       | _ => next(Express.Next.middleware, res)
       }
     };
     */
    next(
      Express.Next.middleware,
      res,
    );
  };
};

let middleware = () => make() |> Express.Middleware.from;
