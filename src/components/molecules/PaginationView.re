open Paginate;

[@react.component]
let make = (~page, ~onPaginate=_ => (), ~isLastPage=false) => {
  <nav
    className="bg-white px-4 py-3 flex items-center justify-between border-t border-gray-200 sm:px-6">
    <div className="hidden sm:block">
      <p className="text-sm leading-5 text-gray-700">
        {React.string({j|Page: |j})}
        <span className="font-medium"> {React.string({j| $page |j})} </span>
      </p>
    </div>
    <div className="flex-1 flex justify-between sm:justify-end">
      <button
        onClick={_ => onPaginate(Previous)}
        disabled={page == 1}
        className={Cn.fromList([
          "relative inline-flex items-center px-4 py-2 border border-gray-300 text-sm leading-5 font-medium rounded-md bg-white focus:outline-none active:bg-gray-100 active:text-gray-700 transition ease-in-out duration-150",
          page == 1
            ? "cursor-not-allowed text-gray-500"
            : "text-gray-700 hover:text-gray-500 ",
        ])}>
        {React.string({j|Previous|j})}
      </button>
      <button
        disabled=isLastPage
        onClick={_ => onPaginate(Next)}
        className={Cn.fromList([
          "ml-3 relative inline-flex items-center px-4 py-2 border border-gray-300 text-sm leading-5 font-medium rounded-md bg-white focus:outline-none active:bg-gray-100 active:text-gray-700 transition ease-in-out duration-150",
          isLastPage
            ? "cursor-not-allowed text-gray-500"
            : "text-gray-700 hover:text-gray-500 ",
        ])}>
        {React.string({j|Next|j})}
      </button>
    </div>
  </nav>;
};
