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
      } : user_profile)
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
let write_auth_profile = (
  Atdgen_codec_runtime.Encode.make (fun (t : auth_profile) ->
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
let read_auth_profile = (
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
      } : auth_profile)
    )
  )
)
let write_auth_credentials = (
  Atdgen_codec_runtime.Encode.make (fun (t : auth_credentials) ->
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
let read_auth_credentials = (
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
      } : auth_credentials)
    )
  )
)
let write_auth_credentials_wrapper = (
  Atdgen_codec_runtime.Encode.make (fun (t : auth_credentials_wrapper) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            write_auth_credentials
            )
          ~name:"user"
          t.user
      ]
    )
  )
)
let read_auth_credentials_wrapper = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          user =
            Atdgen_codec_runtime.Decode.decode
            (
              read_auth_credentials
              |> Atdgen_codec_runtime.Decode.field "user"
            ) json;
      } : auth_credentials_wrapper)
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
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"ctx"
          t.ctx
        ;
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
          ctx =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.fieldDefault "ctx" "user"
            ) json;
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
