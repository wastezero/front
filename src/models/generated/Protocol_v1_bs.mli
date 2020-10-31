(* Auto-generated from "Protocol_v1.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type user_profile = Protocol_v1_t.user_profile = {
  id: int;
  authentication_token: string;
  email: string
}

type pagination = Protocol_v1_t.pagination = { limit: int; page: int }

type error = Protocol_v1_t.error = {
  status: int;
  message: string;
  errors: string list
}

type decimal = Protocol_v1_t.decimal

type datetime = Protocol_v1_t.datetime

type cfg = Protocol_v1_t.cfg = {
  app_url: string;
  cms_api_url: string;
  app_env: string;
  ym_key: string;
  analytics_key: string
}

type auth_profile = Protocol_v1_t.auth_profile = {
  id: int;
  authentication_token: string;
  email: string
}

type auth_credentials = Protocol_v1_t.auth_credentials = {
  email: string;
  password: string
}

type auth_credentials_wrapper = Protocol_v1_t.auth_credentials_wrapper = {
  user: auth_credentials
}

type app_state = Protocol_v1_t.app_state = {
  ctx: string;
  serverUrl: string option;
  user: user_profile option;
  prefetched: bool;
  deviceType: string
}

val read_user_profile :  user_profile Atdgen_codec_runtime.Decode.t

val write_user_profile :  user_profile Atdgen_codec_runtime.Encode.t

val read_pagination :  pagination Atdgen_codec_runtime.Decode.t

val write_pagination :  pagination Atdgen_codec_runtime.Encode.t

val read_error :  error Atdgen_codec_runtime.Decode.t

val write_error :  error Atdgen_codec_runtime.Encode.t

val read_decimal :  decimal Atdgen_codec_runtime.Decode.t

val write_decimal :  decimal Atdgen_codec_runtime.Encode.t

val read_datetime :  datetime Atdgen_codec_runtime.Decode.t

val write_datetime :  datetime Atdgen_codec_runtime.Encode.t

val read_cfg :  cfg Atdgen_codec_runtime.Decode.t

val write_cfg :  cfg Atdgen_codec_runtime.Encode.t

val read_auth_profile :  auth_profile Atdgen_codec_runtime.Decode.t

val write_auth_profile :  auth_profile Atdgen_codec_runtime.Encode.t

val read_auth_credentials :  auth_credentials Atdgen_codec_runtime.Decode.t

val write_auth_credentials :  auth_credentials Atdgen_codec_runtime.Encode.t

val read_auth_credentials_wrapper :  auth_credentials_wrapper Atdgen_codec_runtime.Decode.t

val write_auth_credentials_wrapper :  auth_credentials_wrapper Atdgen_codec_runtime.Encode.t

val read_app_state :  app_state Atdgen_codec_runtime.Decode.t

val write_app_state :  app_state Atdgen_codec_runtime.Encode.t

