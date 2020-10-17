module Duration = {
  type d = {
    . /* Duration type */
    /**** Members ****/
    "days": int,
    "hours": int,
    "milliseconds": int,
    "minutes": int,
    "months": int,
    "seconds": int,
    "weeks": int,
    "years": int,
    "locale": string,
  };

  type durationObj = {
    .
    "days": int,
    "hours": int,
    "milliseconds": int,
    "minutes": int,
    "months": int,
    "seconds": int,
    "weeks": int,
    "years": int,
    "locale": string,
  };

  [@bs.module "luxon"] [@bs.scope "Duration"]
  external fromObject: durationObj => d = "fromObject";

  [@bs.obj]
  external makeDurationObj:
    (
      ~years: int=?,
      ~months: int=?,
      ~weeks: int=?,
      ~days: int=?,
      ~hours: int=?,
      ~minutes: int=?,
      ~seconds: int=?,
      ~milliseconds: int=?,
      unit
    ) =>
    durationObj;

  let from =
      (
        ~days=?,
        ~hours=?,
        ~milliseconds=?,
        ~minutes=?,
        ~months=?,
        ~seconds=?,
        ~weeks=?,
        ~years=?,
        (),
      ) =>
    fromObject(
      makeDurationObj(
        ~days?,
        ~hours?,
        ~milliseconds?,
        ~minutes?,
        ~months?,
        ~seconds?,
        ~weeks?,
        ~years?,
        (),
      ),
    );
};

module DateTime = {
  type dt = {
    . /* DateTime type */
    /**** Members ****/
    "year": int,
    "day": int,
    "month": int,
    "hour": int,
    "minute": int,
    "second": int,
    "millisecond": int,
    "weekDay": int,
  };

  /**** Static Methods ****/
  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external local:
    (
      ~year: int=?,
      ~month: int=?,
      ~day: int=?,
      ~hour: int=?,
      ~minute: int=?,
      ~second: int=?,
      ~millisecond: int=?,
      unit
    ) =>
    dt =
    "local";

  /*** Methods ****/
  [@bs.send.pipe: dt] external setZone: string => dt = "setZone";

  [@bs.send.pipe: dt] external toISODate: string = "toISODate";

  [@bs.send.pipe: dt] external toFormat: string => string = "toFormat";

  [@bs.send.pipe: dt] external toISO: string = "toISO";

  [@bs.send.pipe: dt] external toJSDate: Js_date.t = "toJSDate";

  [@bs.send.pipe: dt] external valueOf: float = "valueOf";

  type arithmeticArgs = [
    | `DurationObj(Duration.durationObj)
    | `Int(int)
    | `Duration(Duration.d)
  ];

  [@bs.send.pipe: dt]
  external minus:
    (
    [@bs.unwrap]
    [
      | `DurationObj(Duration.durationObj)
      | `Int(int)
      | `Duration(Duration.d)
    ]
    ) =>
    dt =
    "minus";

  [@bs.send.pipe: dt]
  external set:
    (
    [@bs.unwrap]
    [
      | `DurationObj(Duration.durationObj)
      | `Int(int)
      | `Duration(Duration.d)
    ]
    ) =>
    dt =
    "set";

  [@bs.send.pipe: dt]
  external plus:
    (
    [@bs.unwrap]
    [
      | `DurationObj(Duration.durationObj)
      | `Int(int)
      | `Duration(Duration.d)
    ]
    ) =>
    dt =
    "plus";

  /* In the original API, these are all optional. But not in bs-luxon. In fact, in bs-luxon you should never use `fromObject` and always use `local` instead. */
  type objectDate = {
    .
    "year": int,
    "day": int,
    "month": int,
    "hour": int,
    "minute": int,
    "second": int,
    "millisecond": int,
  };

  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external fromISO: string => dt = "fromISO";

  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external fromFormat: (string, string) => dt = "fromFormat";

  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external fromObject: objectDate => dt = "fromObject";

  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external fromMillis: float => dt = "fromMillis";

  [@bs.send.pipe: dt]
  external endOf:
    (
    [@bs.string]
    [
      | `year
      | `month
      | `week
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
    ) =>
    dt =
    "endOf";

  [@bs.send.pipe: dt]
  external startOf:
    (
    [@bs.string]
    [
      | `year
      | `month
      | `week
      | `day
      | `hour
      | `minute
      | `second
      | `millisecond
    ]
    ) =>
    dt =
    "startOf";

  /**** Static Members ****/
  [@bs.module "luxon"] [@bs.scope "DateTime"]
  external dateTimeFull: string = "DATETIME_FULL";

  [@bs.get] external day: dt => int = "day";

  [@bs.get] external month: dt => int = "month";

  [@bs.get] external year: dt => int = "year";

  [@bs.get] external weekday: dt => int = "weekday";

  [@bs.get] external isValid: dt => bool = "isValid";
};
