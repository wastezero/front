const webpack = require('webpack');
const cp = require('child_process');
const rimraf = require('rimraf');
const bs = require('browser-sync').create();
const webpackConfig = require('../webpack.edge');

// const [clientConfig, edgeConfig] = webpackConfig;

let edge;
let bsStarted = false;
function startEdge() {
  if (edge) {
    console.log('Restarting edge...');
    edge.kill('SIGTERM');
  }

  edge = cp.spawn('node', ['dist/edge.js']);

  edge.stdout.on('data', (data) => {
    console.log(`${data}`);
  });

  edge.stderr.on('data', (data) => {
    console.error(`${data}`);
  });

  if (bsStarted) {
    setTimeout(() => {
      bs.reload();
    }, 1000);
  }
}

const cleanPromise = new Promise((resolve, reject) => {
  rimraf('./dist', (err) => {
    if (err) {
      return reject(err);
    }

    return resolve();
  });
});

// function compilerPromise(config) {
//   return new Promise((resolve, reject) => {
//     webpack(config, (err, stats) => {
//       if (err || stats.hasErrors()) {
//         return reject(err || stats);
//       }

//       return resolve(stats);
//     });
//   });
// }

// function watchPromise(compiler) {
//   return new Promise((resolve, reject) => {
//     compiler.watch({}, (err, stats) => {
//       if (err || stats.hasErrors()) {
//         return reject(err || stats);
//       }

//       return resolve(stats);
//     });
//   });
// }

cleanPromise
  // .then(() => compilerPromise(clientConfig))
  .then(() => {
    const compiler = webpack(webpackConfig);

    compiler.watch({}, (err, stats) => {
      if (err) {
        return console.error(err);
      }

      if (stats.hasErrors()) {
        return console.log(
          stats.toString({
            colors: true,
            preset: 'errors',
          }),
        );
      }

      startEdge();

      if (!bsStarted) {
        bs.init({
          proxy: 'https://interpaysys.test:7443',
          ui: false,
          host: 'interpaysys.test',
          open: 'external',
        });

        bsStarted = true;
      }
    });

    // const edgeCompiler = webpack(edgeConfig);

    // edgeCompiler.watch({aggregateTimeout: 2000}, (err, stats) => {
    //   if (err) {
    //     return console.error(err);
    //   }

    //   if (stats.hasErrors()) {
    //     return console.log(
    //       stats.toString({
    //         colors: true,
    //         preset: 'errors',
    //       }),
    //     );
    //   }

    // });
  })
  .catch((err) =>
    err.hasErrors
      ? console.log(
          err.toString({
            colors: true,
            preset: 'errors',
          }),
        )
      : console.log(err),
  );
