module UserProfile = {
  type t = Protocol_v1_t.user_profile;

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_user_profile);
};

module Branch = {
  type t = Protocol_v1_t.branch;
  type grid = Atd.Grid_wrap.t(t);

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_branch);

  let grid: Atdgen_codec_runtime.Json.t => grid =
    Atd.Grid_wrap.decode("branches", decode);
};

module Restaurant = {
  type t = Protocol_v1_t.restaurant;
  type grid = Atd.Grid_wrap.t(t);

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_restaurant);

  let grid: Atdgen_codec_runtime.Json.t => grid =
    Atd.Grid_wrap.decode("restaurants", decode);
};

module Manager = {
  type t = Protocol_v1_t.manager;
  type grid = Atd.Grid_wrap.t(t);

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_manager);

  let grid: Atdgen_codec_runtime.Json.t => grid =
    Atd.Grid_wrap.decode("managers", decode);
};
