[@bs.deriving jsConverter]
type size = [ | `s | `m | `l];

[@bs.deriving jsConverter]
type state = [ | `Default | `Loading];

[@react.component]
let make =
    (
      ~state=`Default,
      ~type_="button",
      ~className=?,
      ~disabled=false,
      ~onClick=(_ev: ReactEvent.Mouse.t) => (),
      ~style=?,
      ~children,
    ) => {
  <button
    type_
    className={Cn.fromList([Cn.take(className)])}
    disabled
    onClick={ev => onClick(ev)}
    ?style>
    {switch (state) {
     | `Default => children
     | `Loading =>
       <LoadingSpinner size=`s kind=`white className="text-white" />
     }}
  </button>;
};
