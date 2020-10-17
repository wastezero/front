module UserProfile = {
  type t = Protocol_v1_t.user_profile;

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_user_profile);
};
