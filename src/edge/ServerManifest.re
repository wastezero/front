let manifest = basePath => {
  let json =
    Node.Fs.readFileSync(
      Node.Path.join2(basePath, "webpack-manifest.json"),
      `utf8,
    );

  switch (Js.Json.parseExn(json)) {
  | parsed => Js.Json.decodeObject(parsed)
  | exception _ => None
  };
};

let chunksClient = basePath => {
  let json =
    Node.Fs.readFileSync(
      Node.Path.join2(basePath, "public/loadable-stats.json"),
      `utf8,
    );

  switch (Js.Json.parseExn(json)) {
  | parsed => Js.Json.decodeObject(parsed)
  | exception _ => None
  };
};

let html = basePath =>
  Node.Fs.readFileSync(Node.Path.join2(basePath, "index.html"), `utf8);
