#include <iostream>
#include <string>
#include <vector>

#include "parse_list.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2 || argc > 2) {
        cout << "Must provide one file only.\n";
        return 1;
    }
    cout << "Adding " << argv[1] << '\n';
    vector <string> directories {parseList("directories.txt")};
    for (string &i : directories) {
        // Lazy management.
        string cmd {"rm ../students/" + i + "/" + argv[1]};
        cout << "Executing: " << cmd << '\n';
        system(cmd.c_str());
    }
    return 0;
}
