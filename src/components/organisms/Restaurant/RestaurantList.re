open Wis;
open Models;

module RestaurantCard = {
  [@react.component]
  let make = (~item: Restaurant.t) => {
    <Link
      route={Route.Account(Restaurants(ItemView(item.id)))}
      className="bg-white overflow-hidden shadow rounded-lg">
      <img
        width="100%"
        height="168"
        className="rounded-top object-cover"
        src={item.avatar}
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

/*let restaurants = [
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
  ];*/

[@react.component]
let make = () => {
  let (grid, _, _) = RestaurantService.grid();

  <main>
    <div className="">
      <div className="w-full">
        <div className="flex px-4 sm:px-6 lg:px-8 py-4 bg-white">
          <h3 className="text-xl font-semibold font-display text-gray-900">
            {React.string({j|Restaurant|j})}
          </h3>
          <Link
            route={Route.Account(Restaurants(Create))}
            className="text-sm bg-transparent ml-auto cursor-pointer hover:bg-blue-500 text-blue-700 font-semibold hover:text-white py-1 px-4 border border-blue-500 hover:border-transparent rounded">
            {React.string({j|Create|j})}
          </Link>
        </div>
        <div
          className="px-4 sm:px-6 lg:px-8 mt-4 grid grid-cols-1 gap-5 sm:grid-cols-2 lg:grid-cols-3">
          // <!-- Cards -->

            {switch (grid) {
             | `Loading =>
               <div className="flex-1 w-full"> <LoadingSpinner /> </div>
             | `Error(_) =>
               <div
                 className="flex-1 w-full  flex items-center justify-center">
                 {React.string({j|ошибка|j})}
               </div>
             | `Data((data: Atd.Grid_wrap.t(Restaurant.t))) =>
               data.data
               |> Belt.List.mapWithIndex(_, (index, item) =>
                    <RestaurantCard item key={j|RestaurantCard$index|j} />
                  )
               |> Belt.List.toArray
               |> React.array
             }}
          </div>
      </div>
    </div>
  </main>;
};
