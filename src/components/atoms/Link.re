let handleClick = (ev: ReactEvent.Mouse.t, to_: string) => {
  let metaClick =
    ReactEvent.Mouse.metaKey(ev)
    || ReactEvent.Mouse.ctrlKey(ev)
    || ReactEvent.Mouse.altKey(ev)
    || ReactEvent.Mouse.shiftKey(ev);

  if (!metaClick) {
    ReactEvent.Mouse.preventDefault(ev);
    ReasonReact.Router.push(to_);
    Webapi.Dom.(Window.scrollTo(0., 0., window));
  };
};

let handle = (ev: ReactEvent.Mouse.t, fn) => {
  ReactEvent.Mouse.preventDefault(ev);
  fn();
};

[@react.component]
let make = (~route: Route.t, ~className=?, ~onLinkClicked=() => (), ~children) => {
  let href = Route.toString(route);

  let onClick = ev => {
    handleClick(ev, href);
    onLinkClicked();
  };

  <a href ?className onClick> children </a>;
};
