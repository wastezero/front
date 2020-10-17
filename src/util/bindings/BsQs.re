[@bs.module "qs"] external parse: string => Js.Dict.t(Js.Json.t) = "parse";
[@bs.module "qs"]
external stringify: Js.Dict.t(Js.Json.t) => string = "stringify";
