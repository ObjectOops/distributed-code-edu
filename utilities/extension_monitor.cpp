#include <iostream>
#include <string>
#include <vector>

#include "tui.hpp"
#include "parse_list.hpp"

using namespace std;

const int PIPE_MAX                  {2048};
const int SLEEP                     {10 * 1000000};
const string OPENVSCODE_SERVER_PATH {"openvscode-server-v1.78.2-linux-x64"};

int main() {
    cout << "Monitoring extension status. Press (q) to exit.\n\n";
    vector <string> extensions {parseList("valid_extensions.txt")};
    string expected;
    for (string &i : extensions) {
        expected += i + '\n';
    }
    tin::init();
    while (!tin::kbhit() || tin::getch() != 'q') {
        std::string cmd {"cd ../" + OPENVSCODE_SERVER_PATH + " && ./bin/openvscode-server --server-data-dir 'server-data' --user-data-dir 'user-data' --extensions-dir 'user-extensions' --list-extensions"};
        FILE *pipe {popen(cmd.c_str(), "r")};
        char buffer [PIPE_MAX];
        while (fgets(buffer, PIPE_MAX, pipe));
        pclose(pipe);
        if (expected != buffer) {
            cout << "Discrepancy Detected:\n\texpected=" << expected << "\n\tgot=" << buffer << '\n';
        }
        usleep(SLEEP);
    }
    tin::uninit();
    return 0;
}
