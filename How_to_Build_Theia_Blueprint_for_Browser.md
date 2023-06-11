# How to Build Theia Blueprint for Browser
## *This file is purely for future reference and is only partially related to other contents in this repository.*
1. Install and verify prerequisites listed [here](https://github.com/eclipse-theia/theia/blob/master/doc/Developing.md):
    - Can install Node.js through nvm:
    ```sh
    nvm install 16.14.0
    nvm use 16.14.0
    ```
    - Other dependences:
    ```sh
    sudo apt update
    sudo apt install libx11-dev libxkbfile-dev
    sudo apt install libsecret-1-dev
    ```
    - A 4-core machine may be required.
2. Run `yarn` or `yarn --pure-lockfile`.
3. Run `yarn browser download:plugins`.
4. Run `yarn browser start`
> Note: Extensions may not work.
