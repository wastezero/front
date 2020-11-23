(* Auto-generated from "Protocol_v1.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type address = Protocol_v1_t.address = {
  id: int;
  city_name: string;
  country_name: string;
  house_number: string;
  street: string;
  zip_code: string
}

type restaurant = Protocol_v1_t.restaurant = {
  id: int;
  avatar: string;
  contacts: string;
  cuisine: string;
  description: string;
  name: string;
  status: string
}

type branch = Protocol_v1_t.branch = {
  id: int;
  address: address;
  restaurant: restaurant;
  manager: manager option
}

and manager = Protocol_v1_t.manager = {
  id: int;
  branch: branch;
  name: string;
  status: string
}

type user_profile = Protocol_v1_t.user_profile = {
  id: int;
  authentication_token: string;
  email: string;
  name: string;
  role: string
}

type restaurant_registration_form =
  Protocol_v1_t.restaurant_registration_form = {
  name: string;
  cuisine: string;
  avatar: string;
  website: string;
  description: string;
  contacts: string;
  email: string;
  password: string;
  password_confirmation: string
}

type restaurant_registration_form_wrapper =
  Protocol_v1_t.restaurant_registration_form_wrapper = {
  user: restaurant_registration_form
}

type registration_response = Protocol_v1_t.registration_response = {
  id: int;
  authentication_token: string;
  email: string
}

type pagination_meta = Protocol_v1_t.pagination_meta = {
  current_page: int;
  total_pages: int;
  total_count: int
}

type pagination = Protocol_v1_t.pagination = { limit: int; page: int }

type manager_registration_form = Protocol_v1_t.manager_registration_form = {
  email: string;
  password: string;
  password_confirmation: string;
  name: string;
  branch_id: int
}

type manager_registration_form_wrapper =
  Protocol_v1_t.manager_registration_form_wrapper = {
  user: manager_registration_form
}

type login_credentials = Protocol_v1_t.login_credentials = {
  email: string;
  password: string
}

type login_credentials_wrapper = Protocol_v1_t.login_credentials_wrapper = {
  user: login_credentials
}

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

type app_state = Protocol_v1_t.app_state = {
  serverUrl: string option;
  user: user_profile option;
  token: string option;
  prefetched: bool;
  deviceType: string
}

val read_address :  address Atdgen_codec_runtime.Decode.t

val write_address :  address Atdgen_codec_runtime.Encode.t

val read_restaurant :  restaurant Atdgen_codec_runtime.Decode.t

val write_restaurant :  restaurant Atdgen_codec_runtime.Encode.t

val read_branch :  branch Atdgen_codec_runtime.Decode.t

val write_branch :  branch Atdgen_codec_runtime.Encode.t

val read_manager :  manager Atdgen_codec_runtime.Decode.t

val write_manager :  manager Atdgen_codec_runtime.Encode.t

val read_user_profile :  user_profile Atdgen_codec_runtime.Decode.t

val write_user_profile :  user_profile Atdgen_codec_runtime.Encode.t

val read_restaurant_registration_form :  restaurant_registration_form Atdgen_codec_runtime.Decode.t

val write_restaurant_registration_form :  restaurant_registration_form Atdgen_codec_runtime.Encode.t

val read_restaurant_registration_form_wrapper :  restaurant_registration_form_wrapper Atdgen_codec_runtime.Decode.t

val write_restaurant_registration_form_wrapper :  restaurant_registration_form_wrapper Atdgen_codec_runtime.Encode.t

val read_registration_response :  registration_response Atdgen_codec_runtime.Decode.t

val write_registration_response :  registration_response Atdgen_codec_runtime.Encode.t

val read_pagination_meta :  pagination_meta Atdgen_codec_runtime.Decode.t

val write_pagination_meta :  pagination_meta Atdgen_codec_runtime.Encode.t

val read_pagination :  pagination Atdgen_codec_runtime.Decode.t

val write_pagination :  pagination Atdgen_codec_runtime.Encode.t

val read_manager_registration_form :  manager_registration_form Atdgen_codec_runtime.Decode.t

val write_manager_registration_form :  manager_registration_form Atdgen_codec_runtime.Encode.t

val read_manager_registration_form_wrapper :  manager_registration_form_wrapper Atdgen_codec_runtime.Decode.t

val write_manager_registration_form_wrapper :  manager_registration_form_wrapper Atdgen_codec_runtime.Encode.t

val read_login_credentials :  login_credentials Atdgen_codec_runtime.Decode.t

val write_login_credentials :  login_credentials Atdgen_codec_runtime.Encode.t

val read_login_credentials_wrapper :  login_credentials_wrapper Atdgen_codec_runtime.Decode.t

val write_login_credentials_wrapper :  login_credentials_wrapper Atdgen_codec_runtime.Encode.t

val read_error :  error Atdgen_codec_runtime.Decode.t

val write_error :  error Atdgen_codec_runtime.Encode.t

val read_decimal :  decimal Atdgen_codec_runtime.Decode.t

val write_decimal :  decimal Atdgen_codec_runtime.Encode.t

val read_datetime :  datetime Atdgen_codec_runtime.Decode.t

val write_datetime :  datetime Atdgen_codec_runtime.Encode.t

val read_cfg :  cfg Atdgen_codec_runtime.Decode.t

val write_cfg :  cfg Atdgen_codec_runtime.Encode.t

val read_app_state :  app_state Atdgen_codec_runtime.Decode.t

val write_app_state :  app_state Atdgen_codec_runtime.Encode.t

