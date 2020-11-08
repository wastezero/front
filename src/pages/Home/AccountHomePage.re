type restaurantType = {
  imageUrl: string,
  name: string,
};

module RestaurantCard = {
  [@react.component]
  let make = (~item: restaurantType) => {
    <Link
      route={Route.Account(Restaurants(ItemView(1)))}
      className="bg-white overflow-hidden shadow rounded-lg">
      <img
        width="100%"
        height="168"
        className="rounded-top object-cover"
        src={item.imageUrl}
        alt=""
      />
      <div className="bg-cool-gray-50 px-5 py-3 ">
        <p
          className="text-base leading-5 font-extrabold text-gray-900 hover:text-gray-700 transition ease-in-out duration-150">
          {React.string(item.name)}
        </p>
      </div>
    </Link>;
  };
};

let restaurants = [
  {
    name: {j|Black Star Burger|j},
    imageUrl: "https://res.cloudinary.com/glovoapp/w_700,h_360,f_auto,q_auto/Stores/ghbz39wssydjjglua1tk",
  },
  {
    name: {j|Alye Parusa / Алые паруса|j},
    imageUrl: "https://res.cloudinary.com/glovoapp/w_700,h_360,f_auto,q_auto/Stores/r5kcdprew6vomn1b9cpe",
  },
  {
    name: {j|BAO / БАО Noodles Sushi Bar|j},
    imageUrl: "https://res.cloudinary.com/glovoapp/w_700,h_360,f_auto,q_auto/Stores/mdernbrwezllqtpdllg2",
  },
  {
    name: {j|Pizza Italiano|j},
    imageUrl: "https://res.cloudinary.com/glovoapp/w_700,h_360,f_auto,q_auto/Stores/cnzvzq6o76lpthrcxh49",
  },
];

[@react.component]
let make = () => {
  let (user, _) = Auth.UserContext.useUser();
  <main>
    <div className="bg-white shadow">
      <div className="px-4 sm:px-6 lg:max-w-6xl lg:mx-auto lg:px-8">
        <div className="py-6 md:flex md:items-center md:justify-between">
          <div className="flex-1 min-w-0">
            // <!-- Profile -->

              <div className="flex items-center">
                <span
                  className="sm:inline-flex items-center justify-center hidden h-15 w-15 rounded-full p-1 bg-gray-500">
                  <Icons.HeroIcons.UserSolid
                    className="text-white h-14 w-14"
                  />
                </span>
                <div>
                  <div className="flex items-center">
                    <span
                      className="inline-flex items-center justify-center h-15 w-15 p-1 rounded-full bg-gray-500 sm:hidden">
                      <Icons.HeroIcons.UserSolid
                        className="text-white h-14 w-14"
                      />
                    </span>
                    <h1
                      className="ml-3 text-2xl font-bold leading-7 text-cool-gray-900 sm:leading-9 sm:truncate">
                      {let name =
                         switch (user) {
                         | Authorized(user) => React.string(user.name)
                         | Loading => <LoadingSpinner />
                         | Guest => React.string({j|not reachable|j})
                         };
                       React.string({j|Welcome back, $name|j})}
                    </h1>
                  </div>
                  <dl
                    className="mt-6 flex flex-col sm:ml-3 sm:mt-1 sm:flex-row sm:flex-wrap">
                    <dt className="sr-only">
                      {React.string({j|Company|j})}
                    </dt>
                    <dd
                      className="flex items-center text-sm leading-5 text-cool-gray-500 font-medium capitalize sm:mr-6">
                      // <!-- Heroicon name: office-building -->

                        <Icons.HeroIcons.OfficeBuilding
                          className="flex-shrink-0 mr-1.5 h-5 w-5 text-cool-gray-400"
                        />
                        {React.string({j|WasteZero LLP|j})}
                      </dd>
                    <dt className="sr-only">
                      {React.string({j|Account status|j})}
                    </dt>
                    <dd
                      className="mt-3 flex items-center text-sm leading-5 text-cool-gray-500 font-medium sm:mr-6 sm:mt-0 capitalize">
                      // <!-- Heroicon name: check-circle -->

                        <Icons.HeroIcons.CheckCircle
                          className="flex-shrink-0 mr-1.5 h-5 w-5 text-green-400"
                        />
                        {React.string({j|Verified account|j})}
                      </dd>
                  </dl>
                </div>
              </div>
            </div>
          <div className="mt-6 flex space-x-3 md:mt-0 md:ml-4">
            <span className="shadow-sm rounded-md">
              <button
                type_="button"
                className="inline-flex items-center px-4 py-2 border border-cool-gray-300 text-sm leading-5 font-medium rounded-md text-cool-gray-700 bg-white hover:text-cool-gray-500 focus:outline-none focus:shadow-outline-blue focus:border-blue-300 active:text-cool-gray-800 active:bg-cool-gray-50 transition duration-150 ease-in-out">
                {React.string({j|Deactivate|j})}
              </button>
            </span>
            <span className="shadow-sm rounded-md">
              <button
                type_="button"
                className="inline-flex items-center px-4 py-2 border border-transparent text-sm leading-5 font-medium rounded-md text-white bg-teal-600 hover:bg-teal-500 focus:outline-none focus:shadow-outline-teal focus:border-teal-700 active:bg-teal-700 transition duration-150 ease-in-out">
                {React.string({j|Manage Account|j})}
              </button>
            </span>
          </div>
        </div>
      </div>
    </div>
    <div className="mt-8">
      <div className="max-w-6xl mx-auto px-4 sm:px-6 lg:px-8">
        <h2 className="text-lg leading-6 font-medium text-cool-gray-900">
          {React.string({j|Overview|j})}
        </h2>
        <div
          className="mt-2 grid grid-cols-1 gap-5 sm:grid-cols-2 lg:grid-cols-3">
          // <!-- Cards -->

            {restaurants
             |> Belt.List.mapWithIndex(_, (index, item) =>
                  <RestaurantCard item key={j|RestaurantCard$index|j} />
                )
             |> Belt.List.toArray
             |> React.array}
          </div>
      </div>
    </div>
  </main>;
};
