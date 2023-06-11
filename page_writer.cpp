#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "parse_list.hpp"

using namespace std;

const string DOMAIN {"example.com"}; // Enter domain here.

int main() {
    vector <string> directories {parseList("directories.txt")};
    string markdown {"# Please click on the link with your id.\n"};
    for (string &i : directories) {
        markdown += "- [" + i + "](https://" + DOMAIN + "/?folder=/workspaces/distributed-code-edu/students/" + i + ")\n";
    }
    ofstream fout {"index.md"};
    fout << markdown;
    fout.close();
    return 0;
}
