cd "/workspaces/$(ls /workspaces | head -n 1)/"
sh install.sh
cp settings.json openvscode-server-v${OPENVSCODE_SERVER_VERSION}-linux-x64/user-data/Machine
cd utilities
g++ -w -O2 -std=c++17 extension_monitor.cpp -o extension_monitor.out
g++ -w -O2 -std=c++17 create_directories.cpp -o create_directories.out
