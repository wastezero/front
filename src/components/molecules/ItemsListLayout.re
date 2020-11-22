[@react.component]
let make = (~title, ~createRoute=?, ~children) => {
  <div className="flex-1 flex flex-col bg-white h-0 w-full">
    <div className="flex px-6 py-4 items-start">
      <h3 className="text-xl font-semibold font-display text-gray-900">
        {React.string(title)}
      </h3>
      {switch (createRoute) {
       | Some(route) =>
         <Link
           route
           className="text-sm bg-transparent ml-auto cursor-pointer hover:bg-blue-500 text-blue-700 font-semibold hover:text-white py-1 px-4 border border-blue-500 hover:border-transparent rounded">
           {React.string({j|Create|j})}
         </Link>
       | None => React.null
       }}
    </div>
    children
  </div>;
};
