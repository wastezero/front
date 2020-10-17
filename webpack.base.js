const path = require('path');
const webpack = require('webpack');

const {CleanWebpackPlugin} = require('clean-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const dotenv = require('dotenv');

const rootPath = path.resolve(__dirname);
const publicPath = path.join(rootPath, 'dist');
dotenv.config();

// const dotenv = require('dotenv').config({path: path.join(rootPath, '.env')}).parsed;

// const isDevMode = process.env.NODE_ENV !== 'production';

module.exports = {
  output: {
    path: publicPath,
    publicPath: '/',
    filename: 'assets/js/[name].[hash:8].js',
    chunkFilename: 'assets/js/[name].bundle.[hash:8].js',
  },
  resolve: {
    alias: {
      assets: path.join(rootPath, 'resources/assets'),
    },
  },
  node: {
    fs: 'empty',
  },
  plugins: [
    new webpack.DefinePlugin({
      'process.env.APP_URL': JSON.stringify(process.env.APP_URL),
      'process.env.CSR_ONLY': JSON.stringify(true),
    }),
    new CleanWebpackPlugin(),
    new HtmlWebpackPlugin({template: 'resources/html/index.html'}),
    new CopyWebpackPlugin({
      patterns: [
        // {from: 'public/static', to: 'static/'},
        {from: 'public/*', flatten: true},
      ],
    }),
  ],
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
        test: /\.(woff|woff2|eot|ttf|otf)$/,
        use: [
          {
            loader: 'file-loader',
            options: {
              name: 'assets/fonts/[name].[hash:8].[ext]',
            },
          },
        ],
      },
    ],
  },
};
