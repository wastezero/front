let encode = Atdgen_codec_runtime.Encode.encode;
let decode = Atdgen_codec_runtime.Decode.decode;

module Grid_wrap = {
  type t('a) = {
    data: list('a),
    meta: Protocol_v1_t.pagination_meta,
  };

  let decode:
    (string, Atdgen_codec_runtime.Json.t => 'a, Atdgen_codec_runtime.Json.t) =>
    t('a) =
    (fieldName, decoder, json) => {
      Json.Decode.{
        data: json |> field(fieldName, list(decoder)),
        meta:
          json |> field("meta", decode(Protocol_v1_bs.read_pagination_meta)),
      };
    };
};
