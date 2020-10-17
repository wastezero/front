process.env.NODE_TLS_REJECT_UNAUTHORIZED = '0';

const fs = require('fs');
const path = require('path');

const https = require('https');

const express = require('express');

const cookieParser = require('cookie-parser');

const webpack = require('webpack');

const createWebpackDevMiddleware = require('webpack-dev-middleware');
const webpackHotMiddleware = require('webpack-hot-middleware');

const config = require('../webpack.dev.js');

const ApiProxy = require('../src/edge/ApiProxy.bs');
const EdgeRouter = require('../src/edge/EdgeRouter.bs');

const DotenvConfig = require('../src/edge/DotenvConfig.bs');
const ClientRender = require('../src/edge/ClientRender.bs');

DotenvConfig.init();

const app = express();
const port = DotenvConfig.getInt(7443, 'APP_EDGE_PORT');

const cfg = DotenvConfig.makeClientConfig();

const compiler = webpack(config);

const webpackDevMiddleware = createWebpackDevMiddleware(compiler, {
  publicPath: config.output.publicPath,
  hot: true,
  serverSideRender: true,
  index: false,
});

app.use('/api', ApiProxy.make('/api', undefined));

app
  .use(cookieParser())
  .use(webpackDevMiddleware)
  .use(webpackHotMiddleware(compiler))
  .use(express.static('./public'));

const indexFile = path.resolve(compiler.outputPath, 'index.html');

const prepareEntryPoint = (req, res, next) => {
  compiler.outputFileSystem.readFile(indexFile, (err, buf) => {
    if (err) {
      return next(err);
    }

    const data = buf.toString('utf8');

    const {'ipsys-token': cookie = false} = req.cookies;
    const prefetched = !cookie;

    const injected = ClientRender.inject(cfg, req.path, prefetched, data);

    res.set('content-type', 'text/html');
    res.send(injected);
    res.end();
  });
};

app.use([EdgeRouter.middleware(), prepareEntryPoint]);

const server = https.createServer(
  {
    key: fs.readFileSync('server.key'),
    cert: fs.readFileSync('server.cert'),
  },
  app,
);

server.listen(port, () => {
  console.log(`Server started at port ${JSON.stringify(server.address())}`);
});
