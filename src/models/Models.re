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

module Order = {
  type t = Protocol_v1_t.order;
  type grid = Atd.Grid_wrap.t(t);
  type form_body = Protocol_v1_t.order_form_body;
  type state = Protocol_v1_t.order_create_form;

  let decode: Atdgen_codec_runtime.Json.t => t =
    Atd.decode(Protocol_v1_bs.read_order);

  let encode: state => Js.Json.t =
    Atd.encode(Protocol_v1_bs.write_order_create_form);

  let grid: Atdgen_codec_runtime.Json.t => grid =
    Atd.Grid_wrap.decode("orders", decode);
};
