[@react.component]
let make = (~toast: Toast.t) => {
  let (_, dispatchToasts) = Toast.ToastsContext.useToasts();
  let id = toast.id;
  let toastRef = React.useRef(Js.Nullable.null);
  let onClick = () => {
    dispatchToasts(
      Remove(id),
      // onClick();
    );
  };
  React.useEffect0(() => {
    let toastEl = toastRef.current |> Js.Nullable.toOption;
    switch (toastEl) {
    | Some(toastEl) =>
      let _ =
        Js.Global.setTimeout(
          () => {
            let _ =
              ReactDOMRe.domElementToObj(toastEl)##classList##remove(
                "animate-fadeInUp",
              );
            ReactDOMRe.domElementToObj(toastEl)##classList##add(
              "animate-fadeOut",
            );
          },
          3000,
        );
      ();
    | None => ()
    };
    let hide =
      Js.Global.setTimeout(() => {dispatchToasts(Remove(id))}, 3500);
    Some(() => Js.Global.clearTimeout(hide));
  });
  <div
    className={Cn.fromList([
      "w-sm bg-white shadow-lg rounded-lg pointer-events-auto animate-fadeInUp",
      switch (toast.kind) {
      | `warning => "border border-red-400"
      | _ => ""
      },
    ])}
    ref={ReactDOMRe.Ref.domRef(toastRef)}>
    <div className="rounded-lg shadow-xs overflow-hidden">
      <div className="p-4">
        <div className="flex items-start">
          {toast.kind == `success
             ? <Icons.HeroIcons.CheckCircle
                 className="h-6 w-6 text-green-400 mr-3"
               />
             : React.null}
          <div className="w-0 flex-1 pt-0.5">
            <p className="text-sm leading-5 font-medium text-gray-900">
              {React.string(toast.text)}
            </p>
            <p className="mt-1 text-sm leading-5 text-gray-500">
              {React.string(toast.subtext)}
            </p>
          </div>
          <div className="ml-4 flex-shrink-0 flex">
            <button
              onClick={_ => onClick()}
              className="inline-flex text-gray-400 focus:outline-none hover:text-gray-500 focus:text-gray-500 transition ease-in-out duration-150">
              <Icons.HeroIcons.X className="h-5 w-5" />
            </button>
          </div>
        </div>
      </div>
    </div>
  </div>;
};
