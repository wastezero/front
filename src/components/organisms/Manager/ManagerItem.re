[@react.component]
let make = () => {
  <div className="flex-grow w-full max-w-7xl mx-auto lg:px-8 lg:flex bg-white">
    // <!-- Left sidebar & main wrapper -->

      <div className="flex-1 min-w-0 bg-white lg:flex">
        // <!-- Account profile -->

          <div
            className="lg:flex-shrink-0 lg:w-64 lg:border-r lg:border-gray-200 bg-white">
            <div className="pl-4 pr-6 py-6 sm:pl-6 lg:pl-0">
              <div className="flex items-center justify-between">
                <div className="flex-1 space-y-8">
                  <div
                    className="space-y-8 sm:space-y-0 sm:flex sm:justify-between sm:items-center lg:block lg:space-y-8">
                    // <!-- Profile -->

                      <div className="flex items-center space-x-3">
                        <div className="flex-shrink-0 h-12 w-12">
                          <span
                            className="inline-flex items-center justify-center h-12 w-12 p-1 rounded-full bg-gray-500">
                            <Icons.HeroIcons.UserSolid
                              className="text-white h-11 w-11"
                            />
                          </span>
                        </div>
                        <div className="space-y-1">
                          <div className="text-sm font-medium text-gray-900">
                            {React.string({j|Dake|j})}
                          </div>
                        </div>
                      </div>
                      // <!-- Action buttons -->
                      <div className="flex flex-col sm:flex-row lg:flex-col">
                        <button
                          type_="button"
                          className="inline-flex items-center justify-center px-4 py-2 border border-transparent shadow-sm text-sm font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500 lg:w-full">
                          {React.string({j|Settings|j})}
                        </button>
                        <button
                          type_="button"
                          className="mt-3 inline-flex items-center justify-center px-4 py-2 border border-red-500 shadow-sm text-sm font-medium rounded-md text-red-500 bg-white hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500 sm:mt-0 sm:ml-3 lg:ml-0 lg:mt-3 lg:w-full">
                          {React.string({j|Remove account|j})}
                        </button>
                      </div>
                    </div>
                  // <!-- Meta info -->
                  <div
                    className="flex flex-col space-y-6 sm:flex-row sm:space-y-0 sm:space-x-8 lg:flex-col lg:space-x-0 lg:space-y-6">
                    <div className="flex items-center space-x-2">
                      // <!-- Heroicon name: badge-check -->

                        <Icons.HeroIcons.BadgeCheck
                          className="h-5 w-5 text-gray-400"
                        />
                        <span className="text-sm text-gray-500 font-medium">
                          {React.string({j|Pro Manager|j})}
                        </span>
                      </div>
                    <div className="flex items-center space-x-2">
                      <Icons.HeroIcons.Collection
                        className="h-5 w-5 text-gray-400"
                      />
                      <span className="text-sm text-gray-500 font-medium">
                        {React.string({j|8 Branches|j})}
                      </span>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
          // <!-- Projects List -->
          <div className="bg-white lg:min-w-0 lg:flex-1">
            <div
              className="pl-4 pr-6 pt-4 pb-4 border-b border-t border-gray-200 sm:pl-6 lg:pt-6 lg:border-t-0">
              <div className="flex items-center">
                <h1 className="flex-1 text-lg font-medium">
                  {React.string({j|Orders|j})}
                </h1>
                <div className="relative">
                  <button
                    id="sort-menu"
                    type_="button"
                    className="w-full bg-white border border-gray-300 rounded-md shadow-sm px-4 py-2 inline-flex justify-center text-sm font-medium text-gray-700 hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500"
                    ariaExpanded=false>
                    <Icons.HeroIcons.SortAscending
                      className="mr-3 h-5 w-5 text-gray-400"
                    />
                    {React.string({j|Sort|j})}
                    <Icons.HeroIcons.ChevronDown
                      className="ml-2.5 -mr-1.5 h-5 w-5 text-gray-400"
                    />
                  </button>
                  <div
                    className="hidden origin-top-right z-10 absolute right-0 mt-2 w-56 rounded-md shadow-lg bg-white ring-1 ring-black ring-opacity-5">
                    <div
                      className="py-1" role="menu" ariaLabelledby="sort-menu">
                      <a
                        href="#"
                        className="block px-4 py-2 text-sm text-gray-700 hover:bg-gray-100 hover:text-gray-900"
                        role="menuitem">
                        {React.string({j|Name|j})}
                      </a>
                      <a
                        href="#"
                        className="block px-4 py-2 text-sm text-gray-700 hover:bg-gray-100 hover:text-gray-900"
                        role="menuitem">
                        {React.string({j|Date modified|j})}
                      </a>
                      <a
                        href="#"
                        className="block px-4 py-2 text-sm text-gray-700 hover:bg-gray-100 hover:text-gray-900"
                        role="menuitem">
                        {React.string({j|Date created|j})}
                      </a>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <ul
              className="relative z-0 divide-y divide-gray-200 border-b border-gray-200">
              <li
                className="relative pl-4 pr-6 py-5 hover:bg-gray-50 sm:py-6 sm:pl-6 lg:pl-6">
                <div className="flex items-center justify-between space-x-4">
                  // <!-- Repo name and link -->

                    <div className="min-w-0 space-y-3">
                      <div className="flex items-center space-x-3">
                        <span
                          className="h-4 w-4 bg-green-100 rounded-full flex items-center justify-center"
                          ariaHidden=true>
                          <span
                            className="h-2 w-2 bg-green-400 rounded-full"
                          />
                        </span>
                        <span className="block">
                          <h2 className="text-sm font-medium">
                            <a href="#">
                              <span
                                className="absolute inset-0"
                                ariaHidden=true
                              />
                              {React.string({j|Baursak x 8|j})}
                            </a>
                          </h2>
                        </span>
                      </div>
                      <a
                        href="#"
                        className="relative group flex items-center space-x-2.5">
                        <Icons.HeroIcons.OfficeBuilding
                          className="flex-shrink-0 w-5 h-5 text-gray-400 group-hover:text-gray-500"
                        />
                        <span
                          className="text-sm text-gray-500 group-hover:text-gray-900 font-medium truncate">
                          {React.string({j|Iftar / Timirev 34|j})}
                        </span>
                      </a>
                    </div>
                    <div
                      className="hidden sm:flex flex-col flex-shrink-0 items-end space-y-3">
                      <p className="flex items-center space-x-4">
                        <button
                          className="relative bg-white rounded-full focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500"
                          type_="button">
                          // <!-- Heroicon name: star -->

                            <Icons.HeroIcons.Star
                              className="h-5 w-5 text-yellow-300 hover:text-yellow-400"
                            />
                          </button>
                      </p>
                      <p className="flex text-gray-500 text-sm space-x-2">
                        <span> {React.string({j|Taken 3h ago|j})} </span>
                        <span> {React.string({j|·|j})} </span>
                        <span> {React.string({j|by Saddam|j})} </span>
                      </p>
                    </div>
                  </div>
              </li>
              <li
                className="relative pl-4 pr-6 py-5 hover:bg-gray-50 sm:py-6 sm:pl-6 lg:pl-6">
                <div className="flex items-center justify-between space-x-4">
                  // <!-- Repo name and link -->

                    <div className="min-w-0 space-y-3">
                      <div className="flex items-center space-x-3">
                        <span
                          className="h-4 w-4 bg-gray-100 rounded-full flex items-center justify-center"
                          ariaHidden=true>
                          <span className="h-2 w-2 bg-gray-400 rounded-full" />
                        </span>
                        <span className="block">
                          <h2 className="text-sm font-medium">
                            <a href="#">
                              <span
                                className="absolute inset-0"
                                ariaHidden=true
                              />
                              {React.string({j|Burgers x 3|j})}
                            </a>
                          </h2>
                        </span>
                      </div>
                      <a
                        href="#"
                        className="relative group flex items-center space-x-2.5">
                        <Icons.HeroIcons.OfficeBuilding
                          className="flex-shrink-0 w-5 h-5 text-gray-400 group-hover:text-gray-500"
                        />
                        <span
                          className="text-sm text-gray-500 group-hover:text-gray-900 font-medium truncate">
                          {React.string({j|Bahandi / Abay 42|j})}
                        </span>
                      </a>
                    </div>
                    <div
                      className="hidden sm:flex flex-col flex-shrink-0 items-end space-y-3">
                      <p className="flex items-center space-x-4">
                        <button
                          className="relative bg-white rounded-full focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500"
                          type_="button">
                          // <!-- Heroicon name: star -->

                            <Icons.HeroIcons.Star
                              className="h-5 w-5 text-yellow-300 hover:text-yellow-400"
                            />
                          </button>
                      </p>
                      <p className="flex text-gray-500 text-sm space-x-2">
                        <span>
                          {React.string({j|Expires after 3 hours|j})}
                        </span>
                        <span> {React.string({j|·|j})} </span>
                        <span> {React.string({j|no order yet|j})} </span>
                      </p>
                    </div>
                  </div>
              </li>
            </ul>
          </div>
        </div>
      // <!-- More items... -->
      // <!-- Activity feed -->
      <div
        className="bg-gray-50 pr-4 sm:pr-6 lg:flex-shrink-0 lg:border-l lg:border-gray-200 lg:pr-0">
        <div className="pl-6 lg:w-80">
          <div className="pt-6 pb-2">
            <h2 className="text-sm font-semibold">
              {React.string({j|Activity|j})}
            </h2>
          </div>
          <div>
            <ul className="divide-y divide-gray-200">
              <li className="py-4">
                <div className="flex space-x-3">
                  <span
                    className="inline-flex items-center justify-center h-5 w-5 p-1 rounded-full bg-gray-500">
                    <Icons.HeroIcons.UserSolid
                      className="text-white h-4 w-4"
                    />
                  </span>
                  <div className="flex-1 space-y-1">
                    <div className="flex items-center justify-between">
                      <h3 className="text-sm font-medium">
                        {React.string({j|Saddam|j})}
                      </h3>
                      <p className="text-sm text-gray-500">
                        {React.string({j|30m|j})}
                      </p>
                    </div>
                    <p className="text-sm text-gray-500">
                      {React.string({j|Took the the order, Baursaks x 8|j})}
                    </p>
                  </div>
                </div>
              </li>
              <li className="py-4">
                <div className="flex space-x-3">
                  <span
                    className="inline-flex items-center justify-center h-5 w-5 p-1 rounded-full bg-gray-500">
                    <Icons.HeroIcons.UserSolid
                      className="text-white h-4 w-4"
                    />
                  </span>
                  <div className="flex-1 space-y-1">
                    <div className="flex items-center justify-between">
                      <h3 className="text-sm font-medium">
                        {React.string({j|Dake|j})}
                      </h3>
                      <p className="text-sm text-gray-500">
                        {React.string({j|1h|j})}
                      </p>
                    </div>
                    <p className="text-sm text-gray-500">
                      {React.string({j|Posted new order, Baursak x 8|j})}
                    </p>
                  </div>
                </div>
              </li>
              <li className="py-4">
                <div className="flex space-x-3">
                  <span
                    className="inline-flex items-center justify-center h-5 w-5 p-1 rounded-full bg-gray-500">
                    <Icons.HeroIcons.UserSolid
                      className="text-white h-4 w-4"
                    />
                  </span>
                  <div className="flex-1 space-y-1">
                    <div className="flex items-center justify-between">
                      <h3 className="text-sm font-medium">
                        {React.string({j|Dake|j})}
                      </h3>
                      <p className="text-sm text-gray-500">
                        {React.string({j|4h|j})}
                      </p>
                    </div>
                    <p className="text-sm text-gray-500">
                      {React.string({j|Posted new order, Burgers x 2|j})}
                    </p>
                  </div>
                </div>
              </li>
            </ul>
            // <!-- More items... -->
            <div className="py-4 text-sm border-t border-gray-200">
              <a
                href="#"
                className="text-indigo-600 font-semibold hover:text-indigo-900">
                {React.string({j|View all activity|j})}
                <span ariaHidden=true> {React.string("&rarr;")} </span>
              </a>
            </div>
          </div>
        </div>
      </div>
    </div>;
};
