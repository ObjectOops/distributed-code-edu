#!/bin/bash

wget "https://github.com/gitpod-io/openvscode-server/releases/download/openvscode-server-v${OPENVSCODE_SERVER_VERSION}/openvscode-server-v${OPENVSCODE_SERVER_VERSION}-linux-x64.tar.gz"
tar -xzf openvscode-server-v${OPENVSCODE_SERVER_VERSION}-linux-x64.tar.gz
cd openvscode-server-v${OPENVSCODE_SERVER_VERSION}-linux-x64
./bin/openvscode-server --server-data-dir "server-data" --user-data-dir "user-data" --extensions-dir "user-extensions" --install-extension "ms-python.python"
