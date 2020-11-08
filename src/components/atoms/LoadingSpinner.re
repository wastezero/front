[@bs.deriving jsConverter]
type size = [ | `s | `m];

[@bs.deriving jsConverter]
type kind = [ | `default | `white];

[@react.component]
let make = (~size=`m, ~kind=`default, ~className=?) => {
  <div className="h-full w-full flex justify-center items-center">
    <div
      className={Cn.fromList([
        "loadingspinner",
        switch (size) {
        | `m => "w-8 h-8 border-4"
        | `s => "w-4 h-4 border-2"
        },
        switch (kind) {
        | `default => "border-gray-300 text-blue-500"
        | `white => "border-transparent text-white"
        },
        Cn.take(className),
      ])}
    />
  </div>;
};
