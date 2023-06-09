#include <iostream>
#include <string>
#include <vector>

#include "tui.hpp"
#include "parse_list.hpp"

using namespace std;

const int PIPE_MAX {2048};
const int SLEEP    {10 * 1000000};

// This should also throw an exception if the devcontainer was created incorrectly.
const string OPENVSCODE_SERVER_PATH {"openvscode-server-v" + string {getenv("OPENVSCODE_SERVER_VERSION")} + "-linux-x64"};

int main() {
    cout << "Monitoring extension status. Press (q) to exit.\nUsing: " + OPENVSCODE_SERVER_PATH + "\n\n";
    vector <string> extensions {parseList("valid_extensions.txt")};
    string expected;
    for (string &i : extensions) {
        expected += i + '\n';
    }
    tin::init();
    while (!tin::kbhit() || tin::getch() != 'q') {
        string cmd {"cd ../" + OPENVSCODE_SERVER_PATH + " && ./bin/openvscode-server --server-data-dir 'server-data' --user-data-dir 'user-data' --extensions-dir 'user-extensions' --list-extensions"};
        FILE *pipe {popen(cmd.c_str(), "r")};
        string got;
        char buffer [PIPE_MAX];
        while (fgets(buffer, PIPE_MAX, pipe)) got += buffer;
        pclose(pipe);
        if (expected != got) {
            cout << "Discrepancy Detected:\n\texpected=\n" << expected << "\n\tgot=\n" << got << '\n';
        }
        usleep(SLEEP);
    }
    tin::uninit();
    return 0;
}
