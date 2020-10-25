open PageLayout;

[@react.component]
let make = (~page: Route.account) => {
  <div className="h-screen flex overflow-hidden bg-cool-gray-100">
    <Sidebar />
    <div className="flex-1 overflow-auto focus:outline-none" tabIndex=0>
      <NavbarTop />
      {switch (page) {
       | Home => <AccountHomePage />
       | Restaurants(listState) => React.string({j|Restaurants|j})
       | Branches(listState) => React.string({j|Branches|j})
       | Managers(listState) => React.string({j|Managers|j})
       | Foods(listState) => React.string({j|Foods|j})
       | Orders(listState) => React.string({j|Orders|j})
       }}
    </div>
  </div>;
};
