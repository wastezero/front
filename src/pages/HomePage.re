open PageLayout;

[@react.component]
let make = (~page: Route.account) => {
  <div className="h-screen flex overflow-hidden bg-cool-gray-100">
    <Sidebar />
    <div className="flex-1 overflow-auto focus:outline-none" tabIndex=0>
      <NavbarTop />
      {switch (page) {
       | Home => <AccountHomePage />
       | Restaurants(listState) =>
         switch (listState) {
         | ItemView(_) => <RestaurantView />
         | List => <RestaurantList />
         | _ => React.string({j|Restaurants|j})
         }
       | Branches(_) => React.string({j|Branches|j})
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
