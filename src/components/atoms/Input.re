open Belt;

[@react.component]
let make =
    (
      ~className=?,
      ~value="",
      ~placeholder="",
      ~type_="text",
      ~disabled=false,
      ~readOnly=false,
      ~required=false,
      ~isFocused=false,
      ~onKeyPress=?,
      ~onChange=_ => (),
      ~onFocus=_ => (),
      ~onBlur=_ => (),
    ) => {
  let inputRef = React.useRef(Js.Nullable.null);

  React.useEffect2(
    () => {
      if (isFocused) {
        inputRef.current
        |> Js.Nullable.toOption
        |> Option.map(_, el => ReactDOMRe.domElementToObj(el)##focus())
        |> ignore;
      };

      None;
    },
    (isFocused, inputRef),
  );

  <input
    ref={ReactDOMRe.Ref.domRef(inputRef)}
    type_
    disabled
    ?className
    placeholder
    readOnly
    required
    value
    ?onKeyPress
    onChange={ev => onChange(ReactEvent.Form.target(ev)##value)}
    onFocus={_ => onFocus()}
    onBlur={_ => onBlur()}
    style={ReactDOMRe.Style.make(
      ~fontSize="14px",
      ~lineHeight="20px",
      ~boxSizing="border-box",
      ~width="100%",
      (),
    )}
  />;
};
