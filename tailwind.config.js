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
        sans: ['Hauss', ...defaultTheme.fontFamily.sans],
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
