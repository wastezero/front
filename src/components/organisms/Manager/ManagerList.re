open Belt;
open Wis;
open Models;

let columns =
  ItemsTable.[
    {
      title: "ID",
      content: (item: Manager.t) =>
        <Link
          route={Account(Managers(ItemView(item.id)))}
          className="inline-flex space-x-2 items-center justify-between group">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.id |> string_of_int)}
          </p>
          <Icons.HeroIcons.Eye
            className="w-4 h-4 text-gray-500 group-hover:text-cool-gray-900"
          />
        </Link>,
      textAlign: `left,
    },
    {
      title: "Name",
      content: (item: Manager.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.name)}
        </p>,
      textAlign: `left,
    },
    {
      title: "Surname",
      content: (item: Manager.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.name)}
        </p>,
      textAlign: `left,
    },
    {
      title: "Phone",
      content: (item: Manager.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(
             item.id == 1 ? {j|+7 777 076 5776|j} : {j|+7 707 476 5306|j},
           )}
        </p>,
      textAlign: `left,
    },
    {
      title: "Branch",
      content: (item: Manager.t) =>
        <Link
          route={Account(Branches(ItemView(item.id)))}
          className="inline-flex space-x-2 items-center justify-between group">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.id |> string_of_int)}
          </p>
        </Link>,
      textAlign: `left,
    },
    {
      title: "Status",
      content: (item: Manager.t) => {
        switch (item.id == 2) {
        | true =>
          <button
            type_="button"
            className="inline-flex items-center px-2 py-1 border border-transparent text-xs leading-5 font-medium rounded-md text-white bg-teal-600 hover:bg-teal-500 focus:outline-none focus:shadow-outline-teal focus:border-teal-700 active:bg-teal-700 transition duration-150 ease-in-out">
            {React.string({j|Confirm|j})}
          </button>
        | _ =>
          <dd className="flex items-center text-sm text-gray-700">
            <Icons.HeroIcons.CheckCircle
              className="flex-shrink-0 mr-1.5 h-5 w-5 text-green-400"
            />
            {React.string({j|Verified account|j})}
          </dd>
        | _ =>
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string({j|unexpected status|j})}
          </p>
        };
      },
      textAlign: `left,
    },
  ];

[@react.component]
let make = () => {
  let managers: list(Manager.t) = [
    {
      id: 1,
      branch: {
        id: 1,
        address: {
          id: 1,
          city_name: "Almaty",
          country_name: "Kazakhstan",
          house_number: "23d",
          street: "Seifullin",
          zip_code: "021000",
        },
        restaurant: {
          id: 1,
          avatar: "",
          contacts: "",
          cuisine: "",
          description: "",
          name: "",
          status: "",
        },
      },
      name: "Nursultan",
      status: "",
    },
    {
      id: 2,
      branch: {
        id: 1,
        address: {
          id: 1,
          city_name: "Almaty",
          country_name: "Kazakhstan",
          house_number: "23d",
          street: "Seifullin",
          zip_code: "021000",
        },
        restaurant: {
          id: 1,
          avatar: "",
          contacts: "",
          cuisine: "",
          description: "",
          name: "",
          status: "",
        },
      },
      name: "Dake",
      status: "",
    },
  ];
  let grid: Request.state(Atd.Grid_wrap.t(Manager.t)) =
    `Data({
      data: managers,
      meta: {
        current_page: 1,
        total_pages: 1,
        total_count: 1,
      },
    });
  <ItemsListLayout
    title={j|Managers|j} createRoute={Route.Account(Managers(Create))}>
    <ItemsTable columns grid=(grid, 1, _ => ()) />
  </ItemsListLayout>;
};
