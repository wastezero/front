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
      content: (item: Manager.t) =>
        <Link
          route={Account(Branches(ItemView(item.id)))}
          className="inline-flex space-x-2 items-center justify-between group">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.status)}
          </p>
        </Link>,
      textAlign: `left,
    },
  ];

[@react.component]
let make = () => {
  <ItemsListLayout
    title={j|Managers|j} createRoute={Route.Account(Managers(Create))}>
    <ItemsTable columns grid={ManagerService.grid()} />
  </ItemsListLayout>;
};
