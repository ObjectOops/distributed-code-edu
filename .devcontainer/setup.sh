cd "/workspaces/$(ls /workspaces | head -n 1)/"
sh install.sh
cp simplify.code-profile /home/vscode/
cd utilities
g++ -w -O2 -std=c++17 extension_monitor.cpp -o extension_monitor.out
g++ -w -O2 -std=c++17 create_directories.cpp -o create_directories.out
