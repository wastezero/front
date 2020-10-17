type t = Luxon.DateTime.dt;

let local = Luxon.DateTime.local;

let startOf = Luxon.DateTime.startOf;
let endOf = Luxon.DateTime.endOf;
let day = Luxon.DateTime.day;
let weekday = Luxon.DateTime.weekday;
let month = Luxon.DateTime.month;
let year = Luxon.DateTime.year;

let fromString = Luxon.DateTime.fromISO;
let fromFormat = Luxon.DateTime.fromFormat;
let fromDateFormat = Luxon.DateTime.fromFormat(_, "dd.MM.yyyy");

let toString = Luxon.DateTime.toISO;
let toFormat = Luxon.DateTime.toFormat;
let toLocalFormat = toFormat("dd.MM.yyyy HH:mm:ss");
let toDateFormat = toFormat("dd.MM.yyyy");
let toYear = toFormat("yyyy");

let isValid = Luxon.DateTime.isValid;

let minus = Luxon.DateTime.minus;

let compare = (first_date, second_date) => {
  let first_val = Luxon.DateTime.valueOf(first_date);
  let second_val = Luxon.DateTime.valueOf(second_date);

  first_val -. second_val;
};
