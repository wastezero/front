# WasteZero UI

## Dev environment setup

We use VSCode, but vim and emacs are fine.

Local deps for productive coding:

[fnm](https://github.com/Schniz/fnm) - blazing-fast NVM alternative.

```
curl -fsSL https://github.com/Schniz/fnm/raw/master/.ci/install.sh | bash

fnm install
```

[esy](https://github.com/esy/esy) - package manager, we need to install required tooling:

```
npm install -g esy
esy install
```

## Available Scripts

In the project directory, you can run:

### `yarn start`

First, generate keys for HTTPS.

```
openssl req -newkey rsa:2048 -nodes \
  -keyout ./server.key \
  -x509 -days 365 \
  -out ./server.cert
```

### `esy gen:protocol`

Will rebuild ATD json schema protocols.
