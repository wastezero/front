(* Auto-generated from "Protocol_v1.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type user_profile = { id: int }

type pagination = { limit: int; page: int }

type error = { status: int; message: string; errors: string list }

type decimal = Decimal.t

type datetime = DateTime.t

type cfg = {
  app_url: string;
  cms_api_url: string;
  app_env: string;
  ym_key: string;
  analytics_key: string
}

type auth_profile = { id: int }

type auth_credentials = { email: string; password: string; remember: bool }

type app_state = {
  ctx: string;
  serverUrl: string option;
  user: user_profile option;
  prefetched: bool;
  deviceType: string
}
