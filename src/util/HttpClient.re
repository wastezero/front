open Belt;

external initHeaders: Fetch.Headers.t => Fetch.HeadersInit.t = "%identity";

let addDefaultHeaders = (headers: Fetch.Headers.t) => {
  open Fetch.Headers;

  append("Content-Type", "application/json", headers);
  append("Accept", "application/json", headers);

  headers;
};

let get = (~headers as _=?, url) => {
  // let headers = Option.getWithDefault(headers, defaultHeaders);

  let cfg = Config.getConfig();

  Fetch.fetchWithInit(
    cfg.app_url ++ url,
    Fetch.RequestInit.make(
      ~method_=Get,
      // ~headers=Fetch.HeadersInit.make(headers),
      (),
    ),
  );
};

let post = (~headers=?, url: string, payload) => {
  let cfg = Config.getConfig();

  let headers =
    Option.getWithDefault(headers, Fetch.Headers.make) |> addDefaultHeaders;

  let promise =
    Fetch.fetchWithInit(
      cfg.app_url ++ url,
      Fetch.RequestInit.make(
        ~method_=Post,
        ~headers=initHeaders(headers),
        ~body=Fetch.BodyInit.make(Js.Json.stringify(payload)),
        ~credentials=Include,
        (),
      ),
    );

  // Js.Promise.(
  //   promise
  //   |> then_(Fetch.Response.text)
  //   |> then_(body => {
  //        Js.log2("resp", body);
  //        promise;
  //      })
  // );
  promise;
};

let put = (~headers=?, url: string, payload) => {
  let cfg = Config.getConfig();

  let headers =
    Option.getWithDefault(headers, Fetch.Headers.make) |> addDefaultHeaders;

  Fetch.fetchWithInit(
    cfg.app_url ++ url,
    Fetch.RequestInit.make(
      ~method_=Put,
      ~headers=initHeaders(headers),
      ~body=Fetch.BodyInit.make(Js.Json.stringify(payload)),
      (),
    ),
  );
};
