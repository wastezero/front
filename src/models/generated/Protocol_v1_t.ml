(* Auto-generated from "Protocol_v1.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type user_profile = {
  id: int;
  authentication_token: string;
  email: string;
  name: string;
  role: string
}

type restaurant_registration_form = {
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

type restaurant_registration_form_wrapper = {
  user: restaurant_registration_form
}

type restaurant = {
  id: int;
  avatar: string;
  contacts: string;
  cuisine: string;
  description: string;
  name: string;
  status: string
}

type registration_response = {
  id: int;
  authentication_token: string;
  email: string
}

type pagination_meta = {
  current_page: int;
  total_pages: int;
  total_count: int
}

type pagination = { limit: int; page: int }

type order_form_body = {
  branch_id: int;
  food_id: int;
  expires_at: string;
  deadline: string;
  discount_price: int
}

type order_create_form = { order: order_form_body }

type id = { id: int }

type datetime = DateTime.t

type order = {
  id: int;
  branch: id;
  food: id;
  price: int;
  expires_at: datetime;
  deadline: datetime option
}

type manager_registration_form = {
  email: string;
  password: string;
  password_confirmation: string;
  name: string;
  branch_id: int
}

type manager_registration_form_wrapper = { user: manager_registration_form }

type address = {
  id: int;
  city_name: string;
  country_name: string;
  house_number: string;
  street: string;
  zip_code: string
}

type branch = { id: int; address: address; restaurant: restaurant }

type manager = { id: int; branch: branch; name: string; status: string }

type login_credentials = { email: string; password: string }

type login_credentials_wrapper = { user: login_credentials }

type error = { status: int; message: string; errors: string list }

type decimal = Decimal.t

type cfg = {
  app_url: string;
  cms_api_url: string;
  app_env: string;
  ym_key: string;
  analytics_key: string
}

type app_state = {
  serverUrl: string option;
  user: user_profile option;
  token: string option;
  prefetched: bool;
  deviceType: string
}
