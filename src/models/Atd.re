let encode = Atdgen_codec_runtime.Encode.encode;
let decode = Atdgen_codec_runtime.Decode.decode;

module Grid_wrap_branch = {
  type t('a) = {
    branches: list('a),
    meta: Protocol_v1_t.pagination_meta,
  };

  let decode:
    (Atdgen_codec_runtime.Json.t => 'a, Atdgen_codec_runtime.Json.t) => t('a) =
    (decoder, json) => {
      Json.Decode.{
        branches: json |> field("branches", list(decoder)),
        meta:
          json |> field("meta", decode(Protocol_v1_bs.read_pagination_meta)),
      };
    };
};

module Grid_wrap_restaurant = {
  type t('a) = {
    restaurants: list('a),
    meta: Protocol_v1_t.pagination_meta,
  };

  let decode:
    (Atdgen_codec_runtime.Json.t => 'a, Atdgen_codec_runtime.Json.t) => t('a) =
    (decoder, json) => {
      Json.Decode.{
        restaurants: json |> field("restaurants", list(decoder)),
        meta:
          json |> field("meta", decode(Protocol_v1_bs.read_pagination_meta)),
      };
    };
};
