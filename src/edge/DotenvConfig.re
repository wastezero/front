open Belt;

let init = () =>
  Dotenv.config(
    ~options=
      Dotenv.configInput(
        ~path=Node.Path.resolve(".", ".env"),
        ~encoding="utf-8",
        (),
      ),
    (),
  );

let env: Js.Dict.t('a) = Node.Process.process##env;

let get = (~default="", key): string =>
  Js.Dict.get(env, key) |> Option.getWithDefault(_, default);

let getInt = (~default=0, key): int =>
  Js.Dict.get(env, key) |> Option.mapWithDefault(_, default, int_of_string);

let getBool = (~default=false, key): bool =>
  Js.Dict.get(env, key)
  |> Option.mapWithDefault(_, default, value =>
       value == "true" || value == "1"
     );

let makeClientConfig: unit => Config.cfg =
  () => {
    app_url: get("APP_URL"),
    cms_api_url: get("CMS_API_URL"),
    app_env: get("APP_ENV"),
    ym_key: get("YANDEX_METRIKA_KEY"),
    analytics_key: get("ANALYTICS_KEY"),
  };
