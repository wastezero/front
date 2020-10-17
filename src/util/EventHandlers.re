open Webapi.Dom;

let useClickOutside =
    (
      dropdownRef: React.ref(_),
      activatorRef: React.ref(_),
      onClickOutside: MouseEvent.t => unit,
    ) => {
  let handleMouseDown = (ev: MouseEvent.t) => {
    let dropdown = dropdownRef.current |> Js.Nullable.toOption;
    let activator = activatorRef.current |> Js.Nullable.toOption;

    switch (dropdown, activator) {
    | (Some(dropdownElement), Some(activatorElement)) =>
      let target = MouseEvent.target(ev) |> EventTarget.unsafeAsElement;

      if (!Element.contains(target, dropdownElement)
          && !Element.contains(target, activatorElement)) {
        onClickOutside(ev);
      };

    | (_, _) => ()
    };
  };

  React.useEffect0(() => {
    Document.addMouseDownEventListener(handleMouseDown, document);
    Some(
      () => Document.removeMouseDownEventListener(handleMouseDown, document),
    );
  });
};

let scrollToBottom = () => {
  let bodyHeight = [%raw "document.body.scrollHeight"];
  Window.scrollTo(0., bodyHeight, window);
};

let scrollToFooter = () => {
  let bodyHeight = [%raw "document.body.scrollHeight"];
  Window.scrollTo(0., float_of_int(bodyHeight - 972), window);
};

let focusInput = (input: React.ref(_)) => {
  input.current
  |> Js.Nullable.toOption
  |> Belt.Option.map(_, el => ReactDOMRe.domElementToObj(el)##focus())
  |> ignore;
};
