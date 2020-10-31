open PageLayout;

[@react.component]
let make = (~page: Route.account) => {
  let (_, dispatchToasts) = Toast.ToastsContext.useToasts();

  React.useEffect0(() => {
    dispatchToasts(
      Add({
        id: Toast.generateId(),
        text: {j|Welcome back, Daneker Bekker|j},
        kind: `success,
        subtext: {j|We are happy to see you again|j},
        onClick: () => (),
      }),
    );
    None;
  });

  <div className="h-screen flex overflow-hidden bg-cool-gray-100">
    <Sidebar />
    <div className="flex-1 overflow-auto focus:outline-none" tabIndex=0>
      <NavbarTop />
      {switch (page) {
       | Home => <AccountHomePage />
       | Restaurants(listState) =>
         switch (listState) {
         | ItemView(_) => <RestaurantView />
         | List
         | _ => <RestaurantList />
         }
       | Branches(listState) =>
         switch (listState) {
         | List
         | _ => <BranchList />
         }
       | Managers(_) => React.string({j|Managers|j})
       | Foods(_) => React.string({j|Foods|j})
       | Orders(listState) =>
         switch (listState) {
         | List
         | _ => <OrderList />
         }
       }}
    </div>
  </div>;
};
