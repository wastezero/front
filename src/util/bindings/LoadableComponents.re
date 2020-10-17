type statsOption('a) = {stats: 'a};
[@bs.new] [@bs.module "@loadable/server"]
external chunkExtractor: statsOption('a) => 'b = "ChunkExtractor";

[@bs.send.pipe: 'b] external getScriptTags: string = "getScriptTags";

[@bs.send.pipe: 'b] external collectChunks: 'c => 'd = "collectChunks";

[@bs.send.pipe: 'b] external requireEntrypoint: 'c => 'd = "requireEntrypoint";
