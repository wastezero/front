(* Auto-generated from "Protocol_v1.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

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

type restaurant = Protocol_v1_t.restaurant = {
  id: int;
  avatar: string;
  contacts: string;
  cuisine: string;
  description: string;
  name: string;
  status: string
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

type manager = Protocol_v1_t.manager = {
  id: int;
  branch_id: int;
  name: string;
  status: string
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

type address = Protocol_v1_t.address = {
  id: int;
  city_name: string;
  country_name: string;
  house_number: string;
  street: string;
  zip_code: string
}

type branch = Protocol_v1_t.branch = {
  id: int;
  address: address;
  restaurant: restaurant
}

type app_state = Protocol_v1_t.app_state = {
  serverUrl: string option;
  user: user_profile option;
  token: string option;
  prefetched: bool;
  deviceType: string
}

let write_user_profile = (
  Atdgen_codec_runtime.Encode.make (fun (t : user_profile) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"authentication_token"
          t.authentication_token
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"email"
          t.email
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"role"
          t.role
      ]
    )
  )
)
let read_user_profile = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          authentication_token =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "authentication_token"
            ) json;
          email =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "email"
            ) json;
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          role =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "role"
            ) json;
      } : user_profile)
    )
  )
)
let write_restaurant_registration_form = (
  Atdgen_codec_runtime.Encode.make (fun (t : restaurant_registration_form) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"cuisine"
          t.cuisine
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"avatar"
          t.avatar
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"website"
          t.website
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"description"
          t.description
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"contacts"
          t.contacts
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"email"
          t.email
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"password"
          t.password
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"password_confirmation"
          t.password_confirmation
      ]
    )
  )
)
let read_restaurant_registration_form = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          cuisine =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "cuisine"
            ) json;
          avatar =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "avatar"
            ) json;
          website =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "website"
            ) json;
          description =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "description"
            ) json;
          contacts =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "contacts"
            ) json;
          email =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "email"
            ) json;
          password =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "password"
            ) json;
          password_confirmation =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "password_confirmation"
            ) json;
      } : restaurant_registration_form)
    )
  )
)
let write_restaurant_registration_form_wrapper = (
  Atdgen_codec_runtime.Encode.make (fun (t : restaurant_registration_form_wrapper) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            write_restaurant_registration_form
            )
          ~name:"user"
          t.user
      ]
    )
  )
)
let read_restaurant_registration_form_wrapper = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          user =
            Atdgen_codec_runtime.Decode.decode
            (
              read_restaurant_registration_form
              |> Atdgen_codec_runtime.Decode.field "user"
            ) json;
      } : restaurant_registration_form_wrapper)
    )
  )
)
let write_restaurant = (
  Atdgen_codec_runtime.Encode.make (fun (t : restaurant) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"avatar"
          t.avatar
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"contacts"
          t.contacts
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"cuisine"
          t.cuisine
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"description"
          t.description
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"status"
          t.status
      ]
    )
  )
)
let read_restaurant = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          avatar =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "avatar"
            ) json;
          contacts =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "contacts"
            ) json;
          cuisine =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "cuisine"
            ) json;
          description =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "description"
            ) json;
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          status =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "status"
            ) json;
      } : restaurant)
    )
  )
)
let write_registration_response = (
  Atdgen_codec_runtime.Encode.make (fun (t : registration_response) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"authentication_token"
          t.authentication_token
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"email"
          t.email
      ]
    )
  )
)
let read_registration_response = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          authentication_token =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "authentication_token"
            ) json;
          email =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "email"
            ) json;
      } : registration_response)
    )
  )
)
let write_pagination_meta = (
  Atdgen_codec_runtime.Encode.make (fun (t : pagination_meta) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"current_page"
          t.current_page
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"total_pages"
          t.total_pages
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"total_count"
          t.total_count
      ]
    )
  )
)
let read_pagination_meta = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          current_page =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "current_page"
            ) json;
          total_pages =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "total_pages"
            ) json;
          total_count =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "total_count"
            ) json;
      } : pagination_meta)
    )
  )
)
let write_pagination = (
  Atdgen_codec_runtime.Encode.make (fun (t : pagination) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"limit"
          t.limit
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"page"
          t.page
      ]
    )
  )
)
let read_pagination = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          limit =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "limit"
            ) json;
          page =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "page"
            ) json;
      } : pagination)
    )
  )
)
let write_manager_registration_form = (
  Atdgen_codec_runtime.Encode.make (fun (t : manager_registration_form) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"email"
          t.email
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"password"
          t.password
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"password_confirmation"
          t.password_confirmation
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"branch_id"
          t.branch_id
      ]
    )
  )
)
let read_manager_registration_form = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          email =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "email"
            ) json;
          password =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "password"
            ) json;
          password_confirmation =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "password_confirmation"
            ) json;
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          branch_id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "branch_id"
            ) json;
      } : manager_registration_form)
    )
  )
)
let write_manager_registration_form_wrapper = (
  Atdgen_codec_runtime.Encode.make (fun (t : manager_registration_form_wrapper) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            write_manager_registration_form
            )
          ~name:"user"
          t.user
      ]
    )
  )
)
let read_manager_registration_form_wrapper = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          user =
            Atdgen_codec_runtime.Decode.decode
            (
              read_manager_registration_form
              |> Atdgen_codec_runtime.Decode.field "user"
            ) json;
      } : manager_registration_form_wrapper)
    )
  )
)
let write_manager = (
  Atdgen_codec_runtime.Encode.make (fun (t : manager) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"branch_id"
          t.branch_id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"status"
          t.status
      ]
    )
  )
)
let read_manager = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          branch_id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "branch_id"
            ) json;
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          status =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "status"
            ) json;
      } : manager)
    )
  )
)
let write_login_credentials = (
  Atdgen_codec_runtime.Encode.make (fun (t : login_credentials) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"email"
          t.email
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"password"
          t.password
      ]
    )
  )
)
let read_login_credentials = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          email =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "email"
            ) json;
          password =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "password"
            ) json;
      } : login_credentials)
    )
  )
)
let write_login_credentials_wrapper = (
  Atdgen_codec_runtime.Encode.make (fun (t : login_credentials_wrapper) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            write_login_credentials
            )
          ~name:"user"
          t.user
      ]
    )
  )
)
let read_login_credentials_wrapper = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          user =
            Atdgen_codec_runtime.Decode.decode
            (
              read_login_credentials
              |> Atdgen_codec_runtime.Decode.field "user"
            ) json;
      } : login_credentials_wrapper)
    )
  )
)
let write__5 = (
  Atdgen_codec_runtime.Encode.list (
    Atdgen_codec_runtime.Encode.string
  )
)
let read__5 = (
  Atdgen_codec_runtime.Decode.list (
    Atdgen_codec_runtime.Decode.string
  )
)
let write_error = (
  Atdgen_codec_runtime.Encode.make (fun (t : error) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"status"
          t.status
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"message"
          t.message
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write__5
            )
          ~name:"errors"
          t.errors
      ]
    )
  )
)
let read_error = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          status =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.fieldDefault "status" 400
            ) json;
          message =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "message"
            ) json;
          errors =
            Atdgen_codec_runtime.Decode.decode
            (
              read__5
              |> Atdgen_codec_runtime.Decode.fieldDefault "errors" []
            ) json;
      } : error)
    )
  )
)
let write__1 = (
    Atdgen_codec_runtime.Encode.string
  |> Atdgen_codec_runtime.Encode.contramap (Decimal.toString)
)
let read__1 = (
  (
    Atdgen_codec_runtime.Decode.string
  ) |> (Atdgen_codec_runtime.Decode.map (Decimal.fromString))
)
let write_decimal = (
  write__1
)
let read_decimal = (
  read__1
)
let write__2 = (
    Atdgen_codec_runtime.Encode.string
  |> Atdgen_codec_runtime.Encode.contramap (DateTime.toString)
)
let read__2 = (
  (
    Atdgen_codec_runtime.Decode.string
  ) |> (Atdgen_codec_runtime.Decode.map (DateTime.fromString))
)
let write_datetime = (
  write__2
)
let read_datetime = (
  read__2
)
let write_cfg = (
  Atdgen_codec_runtime.Encode.make (fun (t : cfg) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"app_url"
          t.app_url
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"cms_api_url"
          t.cms_api_url
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"app_env"
          t.app_env
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"ym_key"
          t.ym_key
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"analytics_key"
          t.analytics_key
      ]
    )
  )
)
let read_cfg = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          app_url =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "app_url"
            ) json;
          cms_api_url =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "cms_api_url"
            ) json;
          app_env =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "app_env"
            ) json;
          ym_key =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "ym_key"
            ) json;
          analytics_key =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "analytics_key"
            ) json;
      } : cfg)
    )
  )
)
let write_address = (
  Atdgen_codec_runtime.Encode.make (fun (t : address) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"city_name"
          t.city_name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"country_name"
          t.country_name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"house_number"
          t.house_number
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"street"
          t.street
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"zip_code"
          t.zip_code
      ]
    )
  )
)
let read_address = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          city_name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "city_name"
            ) json;
          country_name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "country_name"
            ) json;
          house_number =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "house_number"
            ) json;
          street =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "street"
            ) json;
          zip_code =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "zip_code"
            ) json;
      } : address)
    )
  )
)
let write_branch = (
  Atdgen_codec_runtime.Encode.make (fun (t : branch) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_address
            )
          ~name:"address"
          t.address
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_restaurant
            )
          ~name:"restaurant"
          t.restaurant
      ]
    )
  )
)
let read_branch = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "id"
            ) json;
          address =
            Atdgen_codec_runtime.Decode.decode
            (
              read_address
              |> Atdgen_codec_runtime.Decode.field "address"
            ) json;
          restaurant =
            Atdgen_codec_runtime.Decode.decode
            (
              read_restaurant
              |> Atdgen_codec_runtime.Decode.field "restaurant"
            ) json;
      } : branch)
    )
  )
)
let write__4 = (
  Atdgen_codec_runtime.Encode.nullable (
    write_user_profile
  )
)
let read__4 = (
  Atdgen_codec_runtime.Decode.nullable (
    read_user_profile
  )
)
let write__3 = (
  Atdgen_codec_runtime.Encode.nullable (
    Atdgen_codec_runtime.Encode.string
  )
)
let read__3 = (
  Atdgen_codec_runtime.Decode.nullable (
    Atdgen_codec_runtime.Decode.string
  )
)
let write_app_state = (
  Atdgen_codec_runtime.Encode.make (fun (t : app_state) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field_o
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"serverUrl"
          t.serverUrl
        ;
          Atdgen_codec_runtime.Encode.field_o
            (
            write_user_profile
            )
          ~name:"user"
          t.user
        ;
          Atdgen_codec_runtime.Encode.field_o
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"token"
          t.token
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.bool
            )
          ~name:"prefetched"
          t.prefetched
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"deviceType"
          t.deviceType
      ]
    )
  )
)
let read_app_state = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          serverUrl =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.fieldOptional "serverUrl"
            ) json;
          user =
            Atdgen_codec_runtime.Decode.decode
            (
              read_user_profile
              |> Atdgen_codec_runtime.Decode.fieldOptional "user"
            ) json;
          token =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.fieldOptional "token"
            ) json;
          prefetched =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.bool
              |> Atdgen_codec_runtime.Decode.fieldDefault "prefetched" false
            ) json;
          deviceType =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.fieldDefault "deviceType" ""
            ) json;
      } : app_state)
    )
  )
)
