open Belt;
open Models;

let columns =
  ItemsTable.[
    {
      title: "ID",
      content: (item: Order.t) =>
        <Link
          route={Account(Orders(ItemView(item.id)))}
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
      title: "Food Id",
      content: (item: Order.t) =>
        <Link
          route={Account(Foods(ItemView(item.food.id)))}
          className="inline-flex space-x-2 items-center justify-between group">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.food.id |> string_of_int)}
          </p>
          <Icons.HeroIcons.ExternalLink
            className="w-4 h-4 text-gray-500 group-hover:text-cool-gray-900"
          />
        </Link>,
      textAlign: `left,
    },
    {
      title: "Experation Date",
      content: (item: Order.t) =>
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize bg-yellow-100 text-yellow-500">
          {React.string(DateTime.toDateFormat(item.expires_at))}
        </span>,
      textAlign: `left,
    },
    {
      title: "Deadline to take",
      content: (item: Order.t) =>
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize bg-red-100 text-red-500">
          {React.string(
             switch (item.deadline) {
             | Some(deadline) => DateTime.toDateFormat(deadline)
             | None => {j|–|j}
             },
           )}
        </span>,
      textAlign: `left,
    },
    {
      title: "Price",
      content: (item: Order.t) =>
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 bg-green-100 text-green-800 capitalize">
          <Currency amount={item.price |> Decimal.fromInt} />
        </span>,
      textAlign: `left,
    },
  ];

[@react.component]
let make = () => {
  <ItemsListLayout
    title={j|Orders|j} createRoute={Route.Account(Orders(Create))}>
    <ItemsTable columns grid={Wis.OrderService.grid()} />
  </ItemsListLayout>;
};
