const defaultTheme = require('tailwindcss/defaultTheme');
const tailwindUiPlugin = require('@tailwindcss/ui');

module.exports = {
  future: {
    removeDeprecatedGapUtilities: true,
    purgeLayersByDefault: true,
  },
  theme: {
    extend: {
      transitionProperty: {
        'margin': 'margin',
      },
      maxHeight: {
        '80': '80vh'
      },
      boxShadow: {
        r: '10px 0px 12px -17px rgba(0,0,0,0.75)'
      },
      fontFamily: {
        // sans: ['Hauss', ...defaultTheme.fontFamily.sans],
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
        slideIn: 'slideIn 0.3s ease-in-out',
        slideOut: 'slideOut 0.3s ease-in-out',
        fadeIn: 'fadeIn 0.2s ease-out',
        fadeInUp: 'fadeInUp 0.3s ease-out',
        fadeOut: 'fadeOut 0.5s ease-out'
      },
      keyframes: {
        slideIn: {
          '0%': { transform: 'translateX(-100%)' },
          '100%': { transform: 'translateX(0)' },
        },
        slideOut: {
          '0%': { transform: 'translateX(0)' },
          '100%': { transform: 'translateX(-100%)' },
        },
        fadeInUp: {
          '0%': { transform: 'translateY(0.5rem)', opacity: 0 },
          '100%': { transform: 'translateY(0)', opacity: 1 },
        },
        fadeIn: {
          '0%': {opacity: 0 },
          '100%': {opacity: 1 },
        },
        fadeOut: {
          '0%': {opacity: 1 },
          '100%': {opacity: 0 },
        },
      }
    },
  },
  variants: {},
  plugins: [
    tailwindUiPlugin({
      layout: 'sidebar',
    }),
  ],
  purge: {
    content: ['./resources/html/index.html', './src/**/*.bs.js'],
  },
};
