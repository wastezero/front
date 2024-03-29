[@react.component]
let make = (~checked, ~onChange) => {
  <span
    role="checkbox"
    tabIndex=0
    onClick={_ => onChange(!checked)}
    className={Cn.fromList([
      "relative inline-flex flex-shrink-0 h-6 w-11 border-2 border-transparent rounded-full cursor-pointer transition-colors ease-in-out duration-200 focus:outline-none focus:shadow-outline",
      Cn.on("bg-gray-200", !checked),
      Cn.on("bg-indigo-600", checked),
    ])}>
    // <!-- On: "", Off: "translate-x-0" -->

      <span
        ariaHidden=true
        className={Cn.fromList([
          "inline-block h-5 w-5 rounded-full bg-white shadow transform transition ease-in-out duration-200",
          Cn.on("translate-x-0", !checked),
          Cn.on("translate-x-5", checked),
        ])}
      />
    </span>;
};
