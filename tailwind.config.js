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
      spacing: {
        'sm': '24rem',
      },
      animation: {
        fadeInUp: 'fadeInUp 0.5s ease-out',
        fadeOut: 'fadeOut 0.5s ease-out'
      },
      keyframes: {
        fadeInUp: {
          '0%': { transform: 'translateY(0.5rem)', opacity: 0 },
          '100%': { transform: 'translateY(0)', opacity: 1 },
        },
        fadeOut: {
          '0%': {opacity: 1 },
          '100%': {opacity: 0 },
        }
      }
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
