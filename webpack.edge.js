const path = require('path');
const WebpackAssetsManifest = require('webpack-assets-manifest');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const webpack = require('webpack');
const dotenv = require('dotenv');
const TerserPlugin = require('terser-webpack-plugin');
const LoadablePlugin = require('@loadable/webpack-plugin');

const isDev = !process.argv.includes('--release');
const rootPath = path.resolve(__dirname);
const distPath = path.join(rootPath, 'dist');
const publicPath = path.join(distPath, 'public');

dotenv.config();

const config = {
  mode: isDev ? 'development' : 'production',

  resolve: {
    alias: {
      assets: path.join(rootPath, 'resources/assets'),
    },
  },

  module: {
    rules: [
      {
        test: /\.svg$/,
        use: ['@svgr/webpack'],
      },
      {
        test: /\.(png|jpg|gif)$/,
        use: [
          {
            loader: 'file-loader',
            options: {
              name: 'assets/images/[name].[hash:8].[ext]',
            },
          },
        ],
      },
      {
        test: /\.s[ac]ss$/,
        use: ['null-loader'],
      },
      {
        test: /\.js$/,
        use: ['babel-loader'],
      },
    ],
  },

  plugins: [
    new webpack.DefinePlugin({
      'process.env.IS_DEVELOPMENT': JSON.stringify(isDev),
    }),
    new LoadablePlugin(),
  ],
};

const edgeConfig = {
  ...config,

  entry: './src/edge/Server.bs.js',

  target: 'node',

  externals: ['./dist/webpack-manifest.json'],

  output: {
    path: distPath,
    filename: 'edge.js',
  },

  module: {
    rules: [...config.module.rules],
  },

  node: {
    __dirname: true,
  },

  plugins: [
    ...config.plugins,
    new CopyWebpackPlugin({
      patterns: [{from: 'resources/html'}],
    }),
  ],
};

const clientPlugins = [
  ...config.plugins,
  new WebpackAssetsManifest({
    output: '../webpack-manifest.json',
  }),
  new CopyWebpackPlugin({
    patterns: [
      {from: 'public/static', to: 'static/'},
      {from: 'public/*', flatten: true},
      {from: 'resources/assets/icons', to: 'static/icons'},
    ],
  }),
];

if (!isDev) {
  clientPlugins.push(new webpack.HashedModuleIdsPlugin());
}

let clientEntry = {
  main: ['./resources/styles/index.scss', './src/index.bs.js'],
};

const clientConfig = {
  ...config,

  entry: clientEntry,

  devtool: 'source-map',
  node: {
    fs: 'empty',
  },

  target: 'web',

  output: {
    path: publicPath,
    publicPath: '/',
    filename: 'assets/js/main.[hash:8].js',
  },

  plugins: clientPlugins,
};

if (!isDev) {
  clientConfig.optimization = {
    namedModules: true,
    noEmitOnErrors: true,
    concatenateModules: true,
    splitChunks: {
      chunks: 'all',
    },
    minimizer: [
      new TerserPlugin({
        cache: true,
        parallel: true,
        sourceMap: true,
      }),
    ],
  };
}

module.exports = [clientConfig, edgeConfig];
