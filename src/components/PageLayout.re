module Sidebar = {
  type menuItem = {
    label: string,
    route: Route.t,
    icon: (~className: string=?, unit) => React.element,
    soon: bool,
  };

  let menuItems = [
    {
      label: "Home",
      route: Route.Account(Home),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.Home ?className />;
      },
      soon: false,
    },
    {
      label: "Restaurants",
      route: Route.Account(Restaurants(List)),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.Library ?className />;
      },
      soon: false,
    },
    {
      label: "Branches",
      route: Route.Account(Branches(List)),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.OfficeBuilding ?className />;
      },
      soon: true,
    },
    {
      label: "Managers",
      route: Route.Account(Managers(List)),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.User ?className />;
      },
      soon: true,
    },
    {
      label: "Foods",
      route: Route.Account(Foods(List)),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.Menu ?className />;
      },
      soon: true,
    },
    {
      label: "Orders",
      route: Route.Account(Orders(List)),
      icon: (~className=?, ()) => {
        <Icons.HeroIcons.ShoppingBag ?className />;
      },
      soon: false,
    },
  ];

  module SidebarLink = {
    [@react.component]
    let make = (~route: Route.t, ~isMobile=false, ~children) => {
      let currentRoute = Route.useUrl() |> Route.ofUrl;
      let isActiveRoute = currentRoute == route;

      let linkClassName =
        Cn.fromList([
          // common
          "group flex items-center px-2 py-2 font-medium rounded-md focus:outline-none focus:bg-gray-700 transition ease-in-out duration-150",
          // static
          Cn.on("text-sm leading-5", !isMobile),
          // mobile
          Cn.on("text-base leading-6", isMobile),
          // active
          Cn.on("text-white bg-gray-700", isActiveRoute),
          // not active
          Cn.on(
            "text-gray-300 hover:text-white hover:bg-gray-700 focus:text-white",
            !isActiveRoute,
          ),
        ]);

      <Link route className=linkClassName> children </Link>;
    };
  };

  [@react.component]
  let make = () => {
    let currentRoute = Route.useUrl() |> Route.ofUrl;
    <>
      // <!-- Off-canvas menu for mobile, show/hide based on off-canvas menu state. -->
      <div className="hidden">
        <div className="fixed inset-0 flex z-40">
          // <!--
          //   Off-canvas menu overlay, show/hide based on off-canvas menu state.
          //   Entering: "transition-opacity ease-linear duration-300"
          //     From: "opacity-0"
          //     To: "opacity-100"
          //   Leaving: "transition-opacity ease-linear duration-300"
          //     From: "opacity-100"
          //     To: "opacity-0"
          // -->

            <div className="fixed inset-0">
              <div className="absolute inset-0 bg-gray-600 opacity-75" />
            </div>
            // <!--
            //   Off-canvas menu, show/hide based on off-canvas menu state.
            //   Entering: "transition ease-in-out duration-300 transform"
            //     From: "-translate-x-full"
            //     To: "translate-x-0"
            //   Leaving: "transition ease-in-out duration-300 transform"
            //     From: "translate-x-0"
            //     To: "-translate-x-full"
            // -->
            <div
              className="relative flex-1 flex flex-col max-w-xs w-full bg-gray-800">
              <div className="absolute top-0 right-0 -mr-14 p-1">
                <button
                  className="flex items-center justify-center h-12 w-12 rounded-full focus:outline-none focus:bg-gray-600"
                  ariaLabel="Close sidebar">
                  <Icons.HeroIcons.X className="h-6 w-6 text-white" />
                </button>
              </div>
              <div className="flex-1 h-0 pb-4 overflow-y-auto">
                <div
                  className="flex-shrink-0 flex items-center h-16 px-4 bg-gray-900">
                  <a
                    className="h-8 w-auto font-medium text-white text-xl"
                    href="#">
                    {React.string("WasteZero")}
                  </a>
                </div>
                <nav className="mt-5 px-2 space-y-1">
                  {let baseIconClassName =
                     Cn.fromList([
                       // common
                       "h-6 w-6 group-hover:text-gray-300 group-focus:text-gray-300 transition ease-in-out duration-150",
                       // mobile
                       "mr-4",
                     ]);

                   Belt.List.mapWithIndex(
                     menuItems,
                     (index, item) => {
                       let isActive = item.route == currentRoute;
                       let iconClassName =
                         Cn.fromList([
                           baseIconClassName,
                           // active
                           Cn.on("text-gray-300", isActive),
                           // not active
                           Cn.on("text-gray-400", !isActive),
                         ]);

                       <SidebarLink
                         route={item.route}
                         isMobile=true
                         key={j|sidebaritem-$index|j}>
                         {item.icon(~className=iconClassName, ())}
                         {React.string(item.label)}
                       </SidebarLink>;
                     },
                   )
                   |> Belt.List.toArray
                   |> React.array}
                </nav>
              </div>
              <hr className="h-px mt-6 bg-gray-700 border-none" />
              <div className="mt-6 flex-1 h-0 overflow-y-auto">
                <nav className="px-2 space-y-1">
                  <SidebarLink route={Route.Auth(Login)} isMobile=true>
                    <Icons.HeroIcons.QuestionMarkCircle
                      className="mr-4 h-6 w-6 text-gray-400 group-hover:text-gray-300 group-focus:text-gray-300 transition ease-in-out duration-150"
                    />
                    {React.string("Help")}
                  </SidebarLink>
                </nav>
              </div>
            </div>
            <div
              className="flex-shrink-0 w-14"
              // <!-- Dummy element to force sidebar to shrink to fit close icon -->
            />
          </div>
      </div>
      // <!-- Static sidebar for desktop -->
      <div className="hidden lg:flex lg:flex-shrink-0">
        <div className="flex flex-col w-64">
          // <!-- Sidebar component, swap this element with another sidebar if you like -->

            <div className="flex flex-col h-0 flex-1 bg-gray-800">
              <div className="flex-1 flex flex-col pb-4 overflow-y-auto">
                <div
                  className="flex items-center h-16 flex-shrink-0 px-4 bg-gray-900">
                  <a
                    className="h-8 w-auto font-medium text-white text-xl"
                    href="#">
                    {React.string("WasteZero")}
                  </a>
                </div>
                <div className="mt-5 flex-1 flex flex-col overflow-y-auto">
                  <div className="overflow-y-auto">
                    <nav className="px-2 space-y-1">
                      {let baseIconClassName =
                         Cn.fromList([
                           // common
                           "h-6 w-6 group-hover:text-gray-300 group-focus:text-gray-300 transition ease-in-out duration-150",
                           // static
                           "mr-3",
                         ]);

                       Belt.List.mapWithIndex(
                         menuItems,
                         (index, item) => {
                           let isActive = item.route == currentRoute;
                           let iconClassName =
                             Cn.fromList([
                               baseIconClassName,
                               // active
                               Cn.on("text-gray-300", isActive),
                               // not active
                               Cn.on("text-gray-400", !isActive),
                             ]);

                           <SidebarLink
                             route={item.route} key={j|sidebarlink-$index|j}>
                             {item.icon(~className=iconClassName, ())}
                             {React.string(item.label)}
                             {item.soon
                                ? <span
                                    className="ml-auto inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize bg-gray-900 text-gray-500">
                                    {React.string("Soon")}
                                  </span>
                                : React.null}
                           </SidebarLink>;
                         },
                       )
                       |> Belt.List.toArray
                       |> React.array}
                    </nav>
                  </div>
                  <hr className="h-px mt-6 bg-gray-700 border-none" />
                  <div className="mt-6 flex-1 h-0 overflow-y-auto">
                    <nav className="px-2 space-y-1">
                      <SidebarLink route={Route.Auth(Login)}>
                        <Icons.HeroIcons.QuestionMarkCircle
                          className="mr-3 h-6 w-6 text-gray-400 group-hover:text-gray-300 group-focus:text-gray-300 transition ease-in-out duration-150"
                        />
                        {React.string("Help")}
                      </SidebarLink>
                    </nav>
                  </div>
                </div>
              </div>
            </div>
          </div>
      </div>
    </>;
  };
};

module ProfileDropdown = {
  open EventHandlers;

  [@react.component]
  let make = (~className=?, ()) => {
    let (isDropdownShown, setIsDropdownShown) = React.useState(() => false);
    let (user, _) = Auth.UserContext.useUser();

    let activatorRef = React.useRef(Js.Nullable.null);
    let dropdownRef = React.useRef(Js.Nullable.null);

    useClickOutside(dropdownRef, activatorRef, _ =>
      setIsDropdownShown(_ => false)
    );

    /**
   * This will help us avoid situations when a click in context action is being propagated
   * to an outside container
   */
    let onClickedInside = ev => {
      ReactEvent.Mouse.stopPropagation(ev);
    };

    <div ?className>
      <div onClick=onClickedInside>
        <button
          ref={ReactDOMRe.Ref.domRef(activatorRef)}
          className="max-w-xs flex items-center text-sm text-cool-gray-400 rounded-full focus:outline-none focus:bg-cool-gray-100 lg:p-2 lg:rounded-md lg:hover:bg-cool-gray-100"
          id="user-menu"
          //  ariaHaspopup="true"
          ariaLabel="User menu"
          onClick={_ => setIsDropdownShown(_ => !isDropdownShown)}>
          <span
            className="inline-flex items-center justify-center h-8 w-8 p-1 rounded-full bg-gray-500">
            <Icons.HeroIcons.UserSolid className="text-white h-7 w-7" />
          </span>
          <p
            className="hidden ml-3 text-cool-gray-700 text-sm leading-5 font-medium lg:block">
            {switch (user) {
             | Authorized(user) => React.string(user.name)
             | Loading => <LoadingSpinner />
             | Guest => React.string({j|not reachable|j})
             }}
          </p>
          // <!-- Heroicon name: chevron-down -->
          <Icons.HeroIcons.ChevronDown
            className="hidden flex-shrink-0 ml-1 h-5 w-5 text-cool-gray-400 lg:block"
          />
        </button>
      </div>
      // <!--
      //   Profile dropdown panel, show/hide based on dropdown state.
      //   Entering: "transition ease-out duration-100"
      //     From: "transform opacity-0 scale-95"
      //     To: "transform opacity-100 scale-100"
      //   Leaving: "transition ease-in duration-75"
      //     From: "transform opacity-100 scale-100"
      //     To: "transform opacity-0 scale-95"
      // -->
      <div
        ref={ReactDOMRe.Ref.domRef(dropdownRef)}
        className={Cn.fromList([
          "origin-top-right",
          "absolute",
          "right-0",
          "mt-2",
          "w-48",
          "rounded-md",
          "shadow-lg",
          Cn.on("hidden", !isDropdownShown),
        ])}>
        <div
          className="py-1 rounded-md bg-white shadow-xs"
          role="menu"
          // ariaOrientation="vertical"
          ariaLabelledby="user-menu">
          <a
            href="#"
            className="block px-4 py-2 text-sm text-cool-gray-700 hover:bg-cool-gray-100 transition ease-in-out duration-150"
            role="menuitem">
            {React.string("Your Profile")}
          </a>
          <a
            href="#"
            className="block px-4 py-2 text-sm text-cool-gray-700 hover:bg-cool-gray-100 transition ease-in-out duration-150"
            role="menuitem">
            {React.string("Settings")}
          </a>
          <a
            href="#"
            className="block px-4 py-2 text-sm text-cool-gray-700 hover:bg-cool-gray-100 transition ease-in-out duration-150"
            role="menuitem">
            {React.string("Logout")}
          </a>
        </div>
      </div>
    </div>;
    // <!-- Profile dropdown -->
  };
};

module NavbarTop = {
  [@react.component]
  let make = () => {
    <div
      className="relative z-10 flex-shrink-0 flex h-16 bg-white border-b border-gray-200">
      <button
        className="px-4 border-r border-cool-gray-200 text-cool-gray-400 focus:outline-none focus:bg-cool-gray-100 focus:text-cool-gray-600 lg:hidden"
        ariaLabel="Open sidebar">
        <Icons.HeroIcons.MenuAlt1
          className="h-6 w-6 transition ease-in-out duration-150"
        />
      </button>
      // <!-- Search bar -->
      <div
        className="flex-1 px-4 flex justify-between sm:px-6 lg:max-w-6xl lg:mx-auto lg:px-8">
        <div className="flex-1 flex" />
        <div className="ml-4 flex items-center md:ml-6">
          <button
            className="p-1 text-cool-gray-400 rounded-full hover:bg-cool-gray-100 hover:text-cool-gray-500 focus:outline-none focus:shadow-outline focus:text-cool-gray-500"
            ariaLabel="Notifications">
            <Icons.HeroIcons.Bell className="h-6 w-6" />
          </button>
          <ProfileDropdown className="ml-3 relative" />
        </div>
      </div>
    </div>;
  };
};
