open Belt;

type t = {
  id: int,
  restaurant_id: int,
  manager_id: int,
  address: string,
  raiting: Decimal.t,
  status: string,
  created_at: DateTime.t,
};

module BranchRowItem = {
  [@react.component]
  let make = (~item: t) => {
    <tr
      className="bg-white hover:bg-gray-100 cursor-pointer"
      onClick={_ => Route.navigateTo(Account(Branches(ItemView(item.id))))}>
      <td>
        <Link
          route={Account(Branches(ItemView(item.id)))}
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
        <dd
          className="flex items-center text-sm leading-5 text-cool-gray-500 font-medium capitalize sm:mr-6">
          <Icons.HeroIcons.OfficeBuilding
            className="flex-shrink-0 mr-1.5 h-5 w-5 text-cool-gray-400"
          />
          {React.string(item.address)}
        </dd>
      </td>
      <td
        className="max-w-0 w-full px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 group">
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.manager_id |> string_of_int)}
        </p>
      </td>
      <td
        className="max-w-0 w-full px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 group">
        <p className="text-cool-gray-700 group-hover:text-cool-gray-900">
          {React.string(item.restaurant_id |> string_of_int)}
        </p>
      </td>
      <td
        className="px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700">
        <span
          className={Cn.fromList([
            "inline-flex items-center px-2.5 py-0.5 rounded-full leading-4 capitalize",
            switch (item.status) {
            | "verified" => "bg-green-100 text-green-800"
            | "need_to_verify" => "bg-yellow-100 text-yellow-400"
            | "created"
            | _ => "bg-gray-100 text-gray-400"
            },
          ])}>
          {React.string(
             switch (item.status) {
             | "verified" => {j|Verified|j}
             | "need_to_verify" => {j|Need to verify|j}
             | "created"
             | _ => {j|Created|j}
             },
           )}
        </span>
      </td>
      <td
        className="px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700">
        <dd
          className="flex items-center text-sm leading-5 text-cool-gray-500 font-medium capitalize sm:mr-6">
          <Icons.HeroIcons.Star
            className="flex-shrink-0 mr-1.5 h-5 w-5 text-cool-gray-400"
          />
          {React.string(Decimal.toString(item.raiting))}
        </dd>
      </td>
      <td
        className="px-6 py-4 whitespace-no-wrap text-sm text-left leading-5 text-cool-gray-700">
        {React.string(DateTime.toDateFormat(item.created_at))}
      </td>
    </tr>;
  };
};

[@react.component]
let make = () => {
  let items = [
    {
      id: 1,
      restaurant_id: 2,
      manager_id: 2,
      address: "Dostyk ave 32",
      raiting: Decimal.make(4.3),
      status: "need_to_verify",
      created_at: DateTime.local(),
    },
    {
      id: 2,
      restaurant_id: 2,
      manager_id: 2,
      address: "Kabanbay ave 32",
      raiting: Decimal.make(4.3),
      status: "need_to_verify",
      created_at: DateTime.local(),
    },
    {
      id: 3,
      restaurant_id: 2,
      manager_id: 2,
      address: "Kabanbay ave 32",
      raiting: Decimal.make(5.0),
      status: "verified",
      created_at: DateTime.local(),
    },
    {
      id: 4,
      restaurant_id: 2,
      manager_id: 2,
      address: "Kabanbay ave 32",
      raiting: Decimal.make(4.7),
      status: "created",
      created_at: DateTime.local(),
    },
    {
      id: 5,
      restaurant_id: 2,
      manager_id: 2,
      address: "Dostyk ave 32",
      raiting: Decimal.make(2.3),
      status: "verified",
      created_at: DateTime.local(),
    },
  ];
  <div className="mx-auto bg-white pb-4">
    <div className="flex flex-col">
      <div className="align-middle min-w-full overflow-x-auto overflow-hidden">
        <div className="flex px-6 py-4">
          <h3 className="text-xl font-semibold font-display text-gray-900">
            {React.string({j|Branches|j})}
          </h3>
          <Link
            route={Route.Account(Branches(Create))}
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
                {React.string({j|Address|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Manager|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Restaurant|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Status|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Raiting|j})}
              </th>
              <th
                className="px-6 py-3 border-b border-gray-200 bg-gray-50 text-left text-xs leading-4 font-medium text-cool-gray-500 uppercase tracking-wider whitespace-no-wrap">
                {React.string({j|Created at|j})}
              </th>
            </tr>
          </thead>
          <tbody className="bg-white divide-y divide-cool-gray-200">
            {items
             |> List.mapWithIndex(_, (index, item) => {
                  <BranchRowItem item key={j|OrderRowItem-$index|j} />
                })
             |> List.toArray
             |> React.array}
          </tbody>
        </table>
      </div>
    </div>
  </div>;
};
