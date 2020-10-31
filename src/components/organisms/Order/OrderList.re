open Belt;

type t = {
  id: int,
  branch_id: int,
  food_id: int,
  user_id: int,
  experation_time: DateTime.t,
  overdue_date: DateTime.t,
  discount_price: Decimal.t,
  status: string,
  taken_at: option(DateTime.t),
};

module OrderRowItem = {
  [@react.component]
  let make = (~item: t) => {
    <tr className="bg-white">
      <td>
        <Link
          route={Account(Orders(ItemView(item.id)))}
          className="inline-flex space-x-2 items-center justify-between px-6 pr-2 py-4 group text-left">
          <p
            className="text-sm leading-5 text-gray-700 group-hover:text-cool-gray-900">
            {React.string(item.id |> string_of_int)}
          </p>
          <Icons.HeroIcons.Eye
            className="w-4 h-4 text-gray-500 group-hover:text-cool-gray-900"
          />
        </Link>
      </td>
      <td
        className="max-w-0 w-full px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 group">
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.food_id |> string_of_int)}
        </p>
      </td>
      <td
        className="max-w-0 w-full px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 group">
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.user_id |> string_of_int)}
        </p>
      </td>
      <td
        className="max-w-0 w-full px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 group">
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.branch_id |> string_of_int)}
        </p>
      </td>
      <td
        className="hidden px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700 md:block">
        <span
          className={Cn.fromList([
            "inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize",
            switch (item.status) {
            | "processed" => "bg-green-100 text-green-800"
            | "pending" => "bg-yellow-100 text-yellow-500"
            | "created"
            | _ => "bg-gray-100 text-gray-400"
            },
          ])}>
          {React.string(
             switch (item.status) {
             | "processed" => {j|Обработан|j}
             | "pending" => {j|В обработке|j}
             | "created"
             | _ => {j|Создан|j}
             },
           )}
        </span>
      </td>
      <td
        className="px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700">
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize bg-yellow-100 text-yellow-500">
          {React.string(DateTime.toDateFormat(item.experation_time))}
        </span>
      </td>
      <td
        className="px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700">
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize bg-red-100 text-red-500">
          {React.string(DateTime.toDateFormat(item.overdue_date))}
        </span>
      </td>
      <td
        className="px-6 py-4 text-right whitespace-no-wrap text-sm leading-5 text-cool-gray-700">
        <span
          className="inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 bg-green-100 text-green-800 capitalize">
          <Currency amount={item.discount_price} />
        </span>
      </td>
      <td
        className={Cn.fromList([
          "px-6 py-4 text-left whitespace-no-wrap text-sm leading-5 text-gray-400",
          Cn.onSome("text-gray-700", item.taken_at),
        ])}>
        {switch (item.taken_at) {
         | Some(time) => React.string(DateTime.toLocalFormat(time))
         | None => React.string({j|Waiting for taker|j})
         }}
      </td>
    </tr>;
  };
};

[@react.component]
let make = () => {
  let items = [
    {
      id: 1,
      branch_id: 1,
      food_id: 1,
      user_id: 12354,
      experation_time: DateTime.local(),
      overdue_date: DateTime.local(),
      discount_price: Decimal.make(1400.),
      status: "processing",
      taken_at: Some(DateTime.local()),
    },
    {
      id: 2,
      branch_id: 1,
      food_id: 1,
      user_id: 12354,
      experation_time: DateTime.local(),
      overdue_date: DateTime.local(),
      discount_price: Decimal.make(2800.),
      status: "pending",
      taken_at: None,
    },
    {
      id: 3,
      branch_id: 1,
      food_id: 1,
      user_id: 12354,
      experation_time: DateTime.local(),
      overdue_date: DateTime.local(),
      discount_price: Decimal.make(1400.),
      status: "created",
      taken_at: None,
    },
    {
      id: 4,
      branch_id: 1,
      food_id: 1,
      user_id: 12354,
      experation_time: DateTime.local(),
      overdue_date: DateTime.local(),
      discount_price: Decimal.make(1400.),
      status: "processing",
      taken_at: Some(DateTime.local()),
    },
  ];
  <div className="mx-auto bg-white pb-4">
    <div className="flex flex-col">
      <div className="align-middle min-w-full overflow-x-auto overflow-hidden">
        <div className="flex px-6 py-4">
          <h3 className="text-xl font-semibold font-display text-gray-900">
            {React.string({j|Orders|j})}
          </h3>
          <Link
            route={Route.Account(Orders(Create))}
            className="text-sm bg-transparent ml-auto cursor-pointer hover:bg-blue-500 text-blue-700 font-semibold hover:text-white py-1 px-4 border border-blue-500 hover:border-transparent rounded">
            {React.string({j|Create|j})}
          </Link>
        </div>
        <table className="min-w-full divide-y divide-cool-gray-200">
          <thead>
            <tr className="border-t border-gray-200">
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|ID|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Food Id|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|User Id|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Branch Id|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Status|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Experation Time|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Overdue Date|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Price|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Taken|j})}
              </th>
            </tr>
          </thead>
          <tbody className="bg-white divide-y divide-cool-gray-200">
            {items
             |> List.mapWithIndex(_, (index, item) => {
                  <OrderRowItem item key={j|OrderRowItem-$index|j} />
                })
             |> List.toArray
             |> React.array}
          </tbody>
        </table>
      </div>
    </div>
  </div>;
};
