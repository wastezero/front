const webpack = require('webpack');
const merge = require('webpack-merge');
const base = require('./webpack.base.js');
const path = require('path');

const MiniCssExtractPlugin = require('mini-css-extract-plugin');
// const {BundleAnalyzerPlugin} = require('webpack-bundle-analyzer');

const rootPath = path.resolve(__dirname);

module.exports = merge(base, {
  entry: {
    main: [
      'react-hot-loader/patch',
      'webpack-hot-middleware/client',
      './src/index.bs.js',
      // './resources/styles/index.css',
    ],
  },
  mode: 'development',
  // devtool: 'source-map',
  // devtool: 'eval',
  devtool: 'inline-source-map',
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          {
            loader: MiniCssExtractPlugin.loader,
          },
          // 'style-loader',
          {
            loader: 'css-loader',
            options: {importLoaders: 1},
          },
          {
            loader: 'postcss-loader',
            options: {
              postcssOptions: {
                ident: 'postcss',
                plugins: [
                  require('postcss-import'),
                  require('tailwindcss'),
                  require('autoprefixer'),
                ],
              },
            },
          },
        ],
      },
    ],
  },
  plugins: [
    // new BundleAnalyzerPlugin({
    //   analyzerPort: 2550,
    //   openAnalyzer: false,
    // }),
    new MiniCssExtractPlugin({
      filename: 'assets/css/[name].[hash:8].css',
      chunkFilename: 'assets/css/[name].bundle.[hash:8].css',
    }),
    new webpack.HotModuleReplacementPlugin(),
  ],
  // optimization: {
  //   namedModules: true,
  //   splitChunks: {
  //     name: 'vendor',
  //     minChunks: 2,
  //   },
  //   noEmitOnErrors: true,
  //   concatenateModules: true,
  // },
});
