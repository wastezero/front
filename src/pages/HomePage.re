open PageLayout;

[@react.component]
let make = () => {
  <div className="h-screen flex overflow-hidden bg-cool-gray-100">
    <Sidebar />
    <div className="flex-1 overflow-auto focus:outline-none" tabIndex=0>
      <NavbarTop />
      {React.string({j|Home page|j})}
    </div>
  </div>;
};
