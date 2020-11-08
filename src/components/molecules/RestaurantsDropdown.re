open EventHandlers;
open Models;
open Wis.AuthService;
[@react.component]
let make =
    (
      ~value: option(Restaurant.t),
      ~onChange,
      ~className=?,
      ~validatedValue=?,
      (),
    ) => {
  let (isDropdownShown, setIsDropdownShown) = React.useState(() => false);

  let (grid, _, _) = RestaurantService.grid();

  let activatorRef = React.useRef(Js.Nullable.null);
  let dropdownRef = React.useRef(Js.Nullable.null);

  let onChange = value => {
    setIsDropdownShown(_ => false);
    onChange(value);
  };

  useClickOutside(dropdownRef, activatorRef, _ =>
    setIsDropdownShown(_ => false)
  );

  /**
   * This will help us avoid situations when a click in context action is being propagated
   * to an outside container
   */
  let onClickedInside = ev => {
    ReactEvent.Mouse.stopPropagation(ev);
  };

  <div
    className={Cn.fromList([
      "relative inline-block w-full",
      Cn.take(className),
    ])}>
    <div onClick=onClickedInside>
      <span className="rounded-md shadow-sm">
        <button
          type_="button"
          ref={ReactDOMRe.Ref.domRef(activatorRef)}
          onClick={_ => setIsDropdownShown(_ => !isDropdownShown)}
          className={Cn.fromList([
            "inline-flex justify-between w-full rounded-md active:text-gray-700 text-gray-600 hover:text-gray-500 border border-gray-300 px-4 py-2 bg-white text-sm leading-5 font-medium focus:outline-none focus:border-blue-300 focus:shadow-outline-blue active:bg-gray-50 transition ease-in-out duration-150",
            Cn.onSome(
              "active:text-gray-800 text-gray-700 hover:text-gray-500",
              value,
            ),
          ])}
          id="options-menu"
          ariaExpanded=true>
          {switch (value) {
           | Some(branch) => React.string(branch.name)
           | None => React.string({j|Choose restaurant|j})
           }}
          <Icons.HeroIcons.ChevronDown className="-mr-1 ml-2 h-5 w-5" />
        </button>
      </span>
    </div>
    <div
      ref={ReactDOMRe.Ref.domRef(dropdownRef)}
      className={Cn.fromList([
        "origin-top-right absolute right-0 mt-2 h-64 rounded-md shadow-lg w-full z-10 overflow-scroll",
        Cn.on("hidden", !isDropdownShown),
      ])}>
      <div
        className="rounded-md bg-white shadow-xs"
        role="menu"
        ariaLabelledby="options-menu">
        <div className="py-1">
          {switch (grid) {
           | `Data(items) =>
             items.restaurants
             |> Belt.List.mapWithIndex(_, (index, item) => {
                  <div
                    key={j|wallet-$index|j}
                    className="group flex flex-col items-start px-4 py-2 text-sm leading-5 cursor-pointer text-gray-700 hover:bg-gray-100 hover:text-gray-900 focus:outline-none focus:bg-gray-100 focus:text-gray-900"
                    role="menuitem"
                    onClick={_ => onChange(Some(item))}>
                    <p className="text-lg font-semibold text-gray-600">
                      {React.string(item.name)}
                    </p>
                    <div className="flex space-x-2">
                      <span
                        className="px-2.5 py-0.5 rounded-full text-xs font-medium leading-4 bg-cool-gray-100 text-cool-gray-800 capitalize">
                        {React.string(item.id |> string_of_int)}
                      </span>
                    </div>
                  </div>
                })
             |> Belt.List.toArray
             |> React.array
           | `Loading => <LoadingSpinner />
           | `Error(_) => React.string({j|error|j})
           }}
        </div>
      </div>
    </div>
    {switch (validatedValue) {
     | Some(Error(text)) =>
       <p className="mt-1 text-red-500 text-sm"> {React.string(text)} </p>
     | _ => React.null
     }}
  </div>;
};
