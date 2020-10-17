// module Item = {
//   type t = Protocol_v1_t.item;
//   type grid = Atd.Grid_wrap.t(t);
//   let decode: Atdgen_codec_runtime.Json.t => t =
//     Atd.decode(Protocol_v1_bs.read_item);
//   let grid: Atdgen_codec_runtime.Json.t => grid =
//     Atd.Grid_wrap.decode(decode);
// };
