[@react.component]
let make = () => {
  let (toasts, _) = Toast.ToastsContext.useToasts();
  React.useEffect1(
    () => {
      Js.log2("toasts changed", Belt.List.length(toasts));
      None;
    },
    [|toasts|],
  );
  <div
    className="fixed p-2 pb-4 z-50 top-0 right-0 pr-4 pt-4 flex flex-col space-y-2 max-h-full overflow-x-scroll">
    {toasts
     |> Belt.List.map(
          _,
          (toast: Toast.t) => {
            let id = toast.id;
            <ToastNotification toast key={j|toast-view-$id|j} />;
          },
        )
     |> Belt.List.toArray
     |> React.array}
  </div>;
};
