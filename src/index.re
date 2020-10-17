[@bs.val] external csrOnly: bool = "process.env.CSR_ONLY";

[@bs.module "@loadable/component"]
external loadableReady: 'a => 'b = "loadableReady";

[%bs.raw {|require("../resources/styles/index.css")|}];

let renderOrHydrate = component => {
  let element = component();

  if (csrOnly) {
    ReactDOMRe.renderToElementWithId(element, "root");
  } else {
    loadableReady(() => {ReactDOMRe.hydrateToElementWithId(element, "root")});
  };

  Js.Promise.resolve();
};

let state: Config.state = Config.getState();

renderOrHydrate(() => <App state />);

%raw
{|
if (module.hot) {
  module.hot.accept('./App.bs', () => {
    const NextApp = require('./App.bs');

    var state = Config$ConsoleUi.getState(undefined);

    renderOrHydrate(function (param) {
      return React.createElement(NextApp.make, {
        state: state
      });
    });
  });
}
|};
