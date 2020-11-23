open PageLayout;

[@react.component]
let make = (~page: Route.account) => {
  let (ctx, _) = Auth.CtxContext.useCtx();
  <div className="h-screen flex overflow-hidden bg-cool-gray-100">
    <Sidebar />
    <div
      className="flex-1 flex flex-col overflow-autos focus:outline-none"
      tabIndex=0>
      <NavbarTop />
      {switch (page) {
       | Home =>
         switch (ctx) {
         | AdminCtx => <AdminHomePage />
         | RestaurantCtx => <RestaurantView id=2 />
         | ManagerCtx => <BranchList />
         | _ => React.string({j|not reachable|j})
         }
       | Restaurants(listState) =>
         switch (listState) {
         | ItemView(id) => <RestaurantView id />
         | List
         | _ => <RestaurantList />
         }
       | Branches(listState) =>
         switch (listState) {
         | List
         | _ => <BranchList />
         }
       | Managers(listState) =>
         switch (listState) {
         | ItemView(_)
         | ItemEdit(_) => <ManagerItem />
         | List
         | _ => <ManagerList />
         }
       | Foods(listState) =>
         switch (listState) {
         | List
         | _ => <FoodList />
         }
       | Orders(listState) =>
         switch (listState) {
         | List
         | _ => <OrderList />
         }
       }}
    </div>
  </div>;
};
