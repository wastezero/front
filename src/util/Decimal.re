type t = Big.t;

let make: float => t = Big.fromFloat;

let fromString: string => t = Big.fromString;
let toString: t => string = Big.toString;

let fromInt: int => t = Big.fromInt;

let times: (t, t) => t = Big.times;

let plus: (t, t) => t = Big.plus;

let rec plusMany: list(t) => t =
  list => {
    switch (list) {
    | [] => make(0.)
    | [item, ...rest] => Big.plus(item, plusMany(rest))
    };
  };
let minus: (t, t) => t = Big.minus;

let compare: (t, t) => int = Big.cmp;
let equals: (t, t) => bool = (a, b) => compare(a, b) == 0;

let toFixed: (~precision: int=?, t) => string =
  (~precision=2, value) => Big.toFixed(value, ~dp=precision, ());
