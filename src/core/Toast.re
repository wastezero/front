[@bs.deriving]
type kind = [ | `default | `success | `warning | `loading];

type t = {
  id: int,
  text: string,
  subtext: string,
  kind,
  onClick: unit => unit,
};

type action =
  | Add(t)
  | Remove(int)
  | Clear;

Random.init(int_of_float(Js.Date.now()));

let generateId = () => Random.int(1000000);

module ToastsContext = {
  type dispatch = action => unit;
  type contextValue = (list(t), dispatch);

  let initValue: contextValue = ([], _ => ignore());

  let context = React.createContext(initValue);

  let useToasts = () => React.useContext(context);
};

module ToastsProvider = {
  let make = React.Context.provider(ToastsContext.context);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

let useToastsContext = initialToasts => {
  let (toasts, dispatch) =
    React.useReducer(
      (toasts, action) =>
        switch (action) {
        | Add(toast) =>
          Js.log2(
            "recieved toast, toast length = ",
            Belt.List.length(toasts),
          );
          toasts @ [toast];
        | Remove(id) => Belt.List.keep(toasts, t => t.id != id)
        | Clear => []
        },
      initialToasts,
    );

  (toasts, dispatch);
};
