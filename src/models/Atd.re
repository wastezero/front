let encode = Atdgen_codec_runtime.Encode.encode;
let decode = Atdgen_codec_runtime.Decode.decode;

module Grid_wrap = {
  type t('a) = {
    data: list('a),
    pagination: Protocol_v1_t.pagination,
  };

  let decode:
    (Atdgen_codec_runtime.Json.t => 'a, Atdgen_codec_runtime.Json.t) => t('a) =
    (decoder, json) => {
      Json.Decode.{
        data: json |> field("data", list(decoder)),
        pagination:
          json |> field("pagination", decode(Protocol_v1_bs.read_pagination)),
      };
    };
};
