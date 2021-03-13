open Belt;
open Wis;
open Models;

let columns =
  ItemsTable.[
    {
      title: "ID",
      content: (item: Food.t) =>
        <Link
          route={Account(Foods(ItemView(item.id)))}
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
      content: (item: Food.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.name)}
        </p>,
      textAlign: `left,
    },
    {
      title: "Description",
      content: (item: Food.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.description)}
        </p>,
      textAlign: `left,
    },
    {
      title: "cuisine",
      content: (item: Food.t) =>
        <p
          className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.cuisine)}
        </p>,
      textAlign: `left,
    },
    {
      title: "Restaurant id",
      content: (item: Food.t) =>
        <Link
          route={Account(Restaurants(ItemView(item.id)))}
          className="inline-flex space-x-2 items-center justify-between group">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.restaurant_id |> string_of_int)}
          </p>
        </Link>,
      textAlign: `left,
    },
  ];

[@react.component]
let make = () => {
  <ItemsListLayout
    title={j|Foods|j} createRoute={Route.Account(Foods(Create))}>
    <ItemsTable columns grid={FoodService.grid()} />
  </ItemsListLayout>;
};
