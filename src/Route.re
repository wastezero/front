open Belt;

type identityCtx =
  | UserCtx
  | MerchantCtx
  | AgentCtx
  | OperatorCtx;

type listState =
  | List
  | Create
  | ItemView(int)
  | ItemEdit(int);

type register =
  | Choose
  | Restaurant
  | Manager;

type auth =
  | Login
  | Register(register);

type t =
  /* Pages */
  | Auth(auth)
  | Account
  | NotFound;

let isProtected =
  fun
  | Auth(Login) => false
  | _ => true;

let toString = route => {
  let _getListStateUrl = (baseUrl, state: listState) =>
    switch (state) {
    | List => baseUrl
    | Create => baseUrl ++ "/" ++ "create"
    | ItemView(id) => baseUrl ++ "/" ++ string_of_int(id)
    | ItemEdit(id) => baseUrl ++ "/" ++ string_of_int(id) ++ "/edit"
    };

  switch (route) {
  | Auth(auth) =>
    switch (auth) {
    | Login => "/login"
    | Register(register) =>
      switch (register) {
      | Choose => "/register"
      | Restaurant => "/register/restaurant"
      | Manager => "/register/manager"
      }
    }
  | Account => "/account"
  | NotFound => "/404"
  };
};

let toAbsoluteString = route => {
  let cfg = Config.getConfig();
  cfg.app_url ++ toString(route);
};

let ofUrl = (url: ReasonReact.Router.url) => {
  switch (url.path) {
  | ["login"] => Auth(Login)
  | ["register", ...rest] =>
    let register =
      switch (rest) {
      | ["restaurant"] => Restaurant
      | ["manager"] => Manager
      | _ => Choose
      };
    Auth(Register(register));
  | _ => Account
  };
};

let getRouterUrl = uri => {
  let path =
    uri
    |> Js.String.substr(~from=1)
    |> Js.String.split("/")
    |> List.fromArray;

  {ReasonReact.Router.path, hash: "", search: ""};
};

let prepareServerUrl = serverUrl =>
  Option.mapWithDefault(serverUrl, None, url => Some(getRouterUrl(url)));

let useUrl = () => {
  let state = Config.getState();
  let serverUrl = prepareServerUrl(state.serverUrl);

  ReasonReact.Router.useUrl(~serverUrl?, ());
};

// let contextRoute = (~ctx, ~account: int, route: account) => {
//   switch (ctx) {
//   | UserCtx => Account(account, route)
//   | AdminCtx => Admin(Account(account, route))
//   };
// };

let navigateTo = (page: t) => {
  ReasonReactRouter.push(page |> toString);
};

// let navigateWithContextTo = (~ctx, ~account: int, route: account) => {
//   let page = contextRoute(~ctx, ~account, route);
//   navigateTo(page);
// };

/**
 * Updates the browser location without triggering router dispatcher
 */
let updateBrowserLocation = url => {
  open Webapi.Dom;
  open History;

  let title =
    Webapi.Dom.document |> Document.unsafeAsHtmlDocument |> HtmlDocument.title;

  pushState(state(history), title, url, history);
};

let urlWithParams = (~url, params: list((string, string))) => {
  let url = url |> toString;
  let params =
    params
    |> List.map(_, ((name, value)) => name ++ "=" ++ value)
    |> List.toArray
    |> Js.Array.joinWith("&", _);

  url ++ "?" ++ params;
};

let setUrlParams = (params: list((string, string))) => {
  let url = [%raw {|location.href.replace(location.search, '')|}];
  let params =
    params
    |> List.map(_, ((name, value)) => name ++ "=" ++ value)
    |> List.toArray
    |> Js.Array.joinWith("&", _);

  let url = url ++ "?" ++ params;
  ReasonReactRouter.push(url);
};

let getParamValue = (~url: option(ReasonReact.Router.url)=?, param, ()) => {
  let locationSearch = [%raw {|location.search|}];
  let searchParams =
    switch (url) {
    | Some(url) => Webapi.Url.URLSearchParams.make(url.search)
    | None => Webapi.Url.URLSearchParams.make(locationSearch)
    };

  let value = Webapi.Url.URLSearchParams.get(param, searchParams);
  value;
};

let useParamValue = paramName => {
  let (value, setValue) = React.useState(() => getParamValue(paramName, ()));
  let handleValueChange = value => {
    let searchParams =
      Webapi.Url.URLSearchParams.make([%raw {|location.search|}]);
    let keys =
      List.fromArray(
        Js.Array.from(Webapi.Url.URLSearchParams.keys(searchParams)),
      );
    let params =
      keys
      |> List.keepMap(_, key => {
           key == paramName
             ? None
             : (
               switch (getParamValue(key, ())) {
               | Some(value) => Some((key, value))
               | None => None
               }
             )
         });
    let params =
      switch (value) {
      | Some(value) => params @ [(paramName, value)]
      | None => params
      };
    setUrlParams(params);
    setValue(_ => value);
  };

  (value, handleValueChange);
};

let dispatchPopStateEvent = () => {
  let _ = Webapi.Dom.(Window.dispatchEvent(Event.make("popState"), window));
  ();
};
