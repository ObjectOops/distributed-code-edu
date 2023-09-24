#!/bin/bash

cd openvscode-server-v${OPENVSCODE_SERVER_VERSION}-linux-x64
./bin/openvscode-server --without-connection-token --server-data-dir "server-data" --user-data-dir "user-data" --extensions-dir "user-extensions"
