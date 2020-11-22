open Belt;
open Wis;
open Models;

let columns =
  ItemsTable.[
    {
      title: "ID",
      content: (item: Branch.t) =>
        <Link
          route={Account(Branches(ItemView(item.id)))}
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
      title: "Address",
      content: (item: Branch.t) =>
        <dd
          className="flex items-center text-sm leading-5 text-cool-gray-500 font-medium capitalize">
          <Icons.HeroIcons.OfficeBuilding
            className="flex-shrink-0 mr-1.5 h-5 w-5 text-cool-gray-400"
          />
          {React.string(Address.toString(item.address))}
        </dd>,
      textAlign: `left,
    },
    {
      title: "Manager",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("Manager 1")}
        </p>,
      textAlign: `left,
    },
    {
      title: "Restaurant",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("Restaurant 1")}
        </p>,
      textAlign: `left,
    },
    {
      title: "Pending Orders",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("12")}
        </p>,
      textAlign: `left,
    },
    {
      title: "Pending Orders",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("12")}
        </p>,
      textAlign: `left,
    },
    {
      title: "Booked Orders",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("12")}
        </p>,
      textAlign: `left,
    },
    {
      title: "Completed Orders",
      content: (_item: Branch.t) =>
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string("12")}
        </p>,
      textAlign: `left,
    },
  ];

[@react.component]
let make = () => {
  <ItemsListLayout
    title={j|Branches|j} createRoute={Route.Account(Branches(Create))}>
    <ItemsTable columns grid={BranchService.grid()} />
  </ItemsListLayout>;
};
