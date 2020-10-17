[@bs.module "http-proxy-middleware"]
external createProxyMiddleware: (string, 'a) => Express.Middleware.t =
  "createProxyMiddleware";

let relayRequestHeaders:
  (
    /* NodeJs.Http.ClientRequest.t */ Express.Request.t,
    Express.Request.t,
    Express.Response.t
  ) =>
  unit = [%raw
  {|
  function (proxyReq, req, _res) {
    Object.keys(req.headers).forEach(function (key) {
      if (key !== 'host') {
        proxyReq.setHeader(key, req.headers[key]);
      }
    });
  }|}
];

let relayResponseHeaders:
  (
    /* NodeJs.Http.IncomingMessage.t */ Express.Response.t,
    Express.Request.t,
    Express.Response.t
  ) =>
  unit = [%raw
  {|
  function (proxyRes, _req, res) {
    Object.keys(proxyRes.headers).forEach(function (key) {
      res.append(key, proxyRes.headers[key]);
    });
  }|}
];

let make: (~prefix: string, unit) => Express.Middleware.t =
  (~prefix, ()) => {
    // Prepare middleware
    createProxyMiddleware(
      prefix,
      {
        "target": DotenvConfig.get("API_PROXY_URL"),
        "changeOrigin": true,
        "cookieDomainRewrite": DotenvConfig.get("APP_ORIGIN_DOMAIN"),
        "secure": false,
        "pathRewrite": {
          "^/api/v1": "/v1",
        },
        "onProxyReq": relayRequestHeaders,
        "onProxyRes": relayResponseHeaders,
      },
    );
  };
