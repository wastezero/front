const defaultTheme = require('tailwindcss/defaultTheme');
const tailwindUiPlugin = require('@tailwindcss/ui');

module.exports = {
  future: {
    removeDeprecatedGapUtilities: true,
    // purgeLayersByDefault: true,
  },
  purge: [],
  theme: {
    extend: {
      fontFamily: {
        mono: [
          '"SFMono-Regular"',
          'Consolas',
          '"Liberation Mono"',
          'Menlo',
          'Courier',
          'monospace',
        ],
      },
    },
  },
  variants: {},
  plugins: [
    tailwindUiPlugin({
      layout: 'sidebar',
    }),
  ],
  // purge: {
  //   content: ["./src/**/*.html", "./src/**/*.re", "./src/**/*.bs.js"],
  // },
};
