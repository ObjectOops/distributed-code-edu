FROM mcr.microsoft.com/devcontainers/base:jammy

RUN apt update && export DEBIAN_FRONTEND=noninteractive \
    && apt install -y --no-install-recommends build-essential python3

COPY setup.sh /usr/local/setup.sh

ENV OPENVSCODE_SERVER_VERSION="1.79.2"
