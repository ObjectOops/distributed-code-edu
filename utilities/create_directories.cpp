#include <iostream>
#include <string>
#include <vector>

#include "parse_list.hpp"

using namespace std;

int main() {
    cout << "Creating directories with template files.\n";
    vector <string> directories {parseList("directories.txt")};
    system("mkdir ../students");
    for (string &i : directories) {
        // Lazy management.
        string cmd {"mkdir ../students/" + i + " && cp -r template/ ../students/" + i};
        cout << "Executing: " << cmd << '\n';
        system(cmd.c_str());
    }
    return 0;
}
