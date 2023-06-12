#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "parse_list.hpp"

using namespace std;

string domain {"example.com"}; // Enter domain here. Empty for Codespace auto-detection.

int main() {
    if (domain.empty()) {
        char *codespaceName        {getenv("CODESPACE_NAME")};
        char *portForwardingDomain {getenv("GITHUB_CODESPACES_PORT_FORWARDING_DOMAIN")};
        if (codespaceName != nullptr && portForwardingDomain != nullptr) {
            domain = string {codespaceName} + "-3000." + string {portForwardingDomain};
        }
    }
    if (domain.empty()) {
        cout << "No domain specified. Could not auto-detect.\n";
        return 1;
    }
    vector <string> directories {parseList("directories.txt")};
    string markdown {"# Please click on the link with your id.\n"};
    for (string &i : directories) {
        markdown += "- [" + i + "](https://" + domain + "/?folder=/workspaces/distributed-code-edu/students/" + i + ")\n";
    }
    ofstream fout {"index.md"};
    fout << markdown;
    fout.close();
    return 0;
}
