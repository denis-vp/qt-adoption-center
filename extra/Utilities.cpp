//
// Created by qdeni on 19-Apr-23.
//

#include <sstream>
#include "Utilities.h"

using std::vector;
using std::string;


string trim(const std::string &str) {
    string result(str);

    size_t position = result.find_first_not_of(' ');
    if (position != -1) {
        result.erase(0, position);
    }
    position = result.find_last_not_of(' ');
    if (position != string::npos) {
        result.erase(position + 1);
    }

    return result;
}


vector<string> tokenize(const std::string &str, char delimiter) {
    vector<string> result;
    std::stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}
