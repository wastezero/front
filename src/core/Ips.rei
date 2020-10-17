open Documents;
open Forms;

// module ItemService: {
//   /**
//    * Creates a new Item.t model from ItemForm.state state data.
//    * The result is either `Ok(Item.t)`, or `Error(Request.error)`
//    */
//   let create:
//     (~ctx: Auth.ctx, ~account: int, ItemForm.state) =>
//     Js.Promise.t(result(Item.t, Request.error));

//   let update:
//     (~ctx: Auth.ctx, ~account: int, Item.t, ItemForm.state) =>
//     Js.Promise.t(result(Item.t, Request.error));
//   // let delete:
//   //   (~ctx: Auth.ctx, ~account: int, Item.t) =>
//   //   Js.Promise.t(result(unit, Request.error));
// };

// module Kassa: {
//   open KassaForms;

//   module KkmService: {
//     /**
//      * Creates a new KkmSale.t model.
//      * The result is either `Ok(KkmSale.t)`, or `Error(Request.error)`
//      */
//     let create:
//       (~ctx: Auth.ctx, ~account: int, KkmCreateForm.state) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let update:
//       (~ctx: Auth.ctx, ~account: int, ~kkm: Kkm.t, KkmUpdateForm.state) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let start:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let confirm:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let connect:
//       (~ctx: Auth.ctx, ~account: int, ~kkm: Kkm.t, KkmConnectForm.state) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let register:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));

//     let activate:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));
//     let closeShift:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));
//     let requestX:
//       (~ctx: Auth.ctx, ~account: int, Kkm.t) =>
//       Js.Promise.t(result(Kkm.t, Request.error));
//   };

//   module SaleService: {
//     /**
//      * Creates a new KkmSale.detailed model from CashboxForm.state data.
//      * The result is either `Ok(KkmSale.detailed)`, or `Error(Request.error)`
//      */
//     let create:
//       (~ctx: Auth.ctx, ~account: int, CashboxForm.state) =>
//       Js.Promise.t(result(KkmSale.detailed, Request.error));
//   };
// };
