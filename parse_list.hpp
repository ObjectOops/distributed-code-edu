#ifndef PARSE_LIST_HPP
#define PARSE_LIST_HPP

#include <fstream>
#include <string>
#include <vector>

std::vector <std::string> parseList(const std::string &fileName) {
    std::ifstream fin {fileName};
    std::vector <std::string> list;
    std::string line;
    while (std::getline(fin, line)) {
        list.push_back(line);
    }
    fin.close();
    return list;
}

#endif
