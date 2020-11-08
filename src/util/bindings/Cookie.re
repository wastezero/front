type document;
[@bs.val] external document: document = "window.document";
[@bs.get] external value: document => string = "cookie";
[@bs.set] external set: (document, string) => unit = "cookie";
