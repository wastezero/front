/**
 * TODO ISO 4217 codes and symbols map
 */
[@bs.deriving jsConverter]
type t = [ | `default | `kzt];

let symbol =
  fun
  | `default => {j|₸|j}
  | `kzt => {j|KZT|j};

[@react.component]
let make = (~className=?, ~unit=`default, ~precision=2, ~amount: Decimal.t) => {
  let money = Decimal.toFixed(~precision, amount);
  let symbol = symbol(unit);
  let className = Cn.fromList(["whitespace-no-wrap", Cn.take(className)]);
  <span className> {React.string({j|$money $symbol|j})} </span>;
};
