type global;

[@bs.val] external global: global = "global";

external fromJson: Js.Json.t => Js.t({..}) = "%identity";

[@bs.set] external setConfig: (global, Js.t({..})) => unit = "__CFG__";

[@bs.set] external setState: (global, Js.t({..})) => unit = "__STATE__";

[@bs.set] external setContent: (global, Js.t({..})) => unit = "__CONTENT__";

[@bs.set] external setConsole: (global, Js.t({..})) => unit = "console";
