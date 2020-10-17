const webpack = require('webpack');
const rimraf = require('rimraf');
const webpackConfig = require('../webpack.edge');

const [clientConfig, edgeConfig] = webpackConfig;

const cleanPromise = new Promise((resolve, reject) => {
  rimraf('./dist', err => {
    if (err) {
      return reject(err);
    }

    return resolve();
  });
});

cleanPromise
  .then(() => {
    console.log('Finished cleaning.');

    console.log('Starting the builds...');

    let frontendBuild = webpack(clientConfig, (err, stats) => {
      if (err || stats.hasErrors()) {
        !err
          ? console.log(
              stats.toString({
                colors: true,
                preset: 'errors',
              }),
            )
          : console.log(err);

        console.log('Error building frontend.');
        return;
      }

      console.log('Frontend build finished.');
    });

    let backendBuild = webpack(edgeConfig, (err, stats) => {
      if (err || stats.hasErrors()) {
        !err
          ? console.log(
              stats.toString({
                colors: true,
                preset: 'errors',
              }),
            )
          : console.log(err);

        console.log('Error building edge.');
        return;
      }

      console.log('Backend build finished.');
    });

    Promise.all([frontendBuild, backendBuild]);
  })
  .catch(err =>
    err.hasErrors
      ? console.log(
          err.toString({
            colors: true,
            preset: 'errors',
          }),
        )
      : console.log(err),
  );
