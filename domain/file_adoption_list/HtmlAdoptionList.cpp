//
// Created by qdeni on 19-Apr-23.
//

#include <fstream>
#include <Windows.h>
#include <string>
#include "HtmlAdoptionList.h"
#include "../../extra/exceptions.h"

using std::string;


void HtmlAdoptionList::writeToFile() {
    std::ofstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("could not open file");
    }

    file << R"(<!DOCTYPE html>)" << std::endl;
    file << R"(<html>)" << std::endl;
    file << R"(<head>)" << std::endl;
    file << R"(<title>Adoption List</title>)" << std::endl;
    file << R"(</head>)" << std::endl;
    file << R"(<body>)" << std::endl;
    file << R"(<table border="1">)" << std::endl;
    file << R"(<tr>)" << std::endl;
    file << R"(<th>Name</th>)" << std::endl;
    file << R"(<th>Breed</th>)" << std::endl;
    file << R"(<th>Age</th>)" << std::endl;
    file << R"(<th>Source</th>)" << std::endl;
    file << R"(</tr>)" << std::endl;

    for (const auto &pet: this->pets) {
        file << R"(<tr>)" << std::endl;
        file << R"(<td>)" << pet.getName() << R"(</td>)" << std::endl;
        file << R"(<td>)" << pet.getBreed() << R"(</td>)" << std::endl;
        file << R"(<td>)" << pet.getAge() << R"(</td>)" << std::endl;
        file << R"(<td><a href=")" << pet.getPhoto() << R"(">Link</a></td>)" << std::endl;
        file << R"(</tr>)" << std::endl;
    }

    file << R"(</table>)" << std::endl;
    file << R"(</body>)" << std::endl;
    file << R"(</html>)" << std::endl;

    file.close();
}


void HtmlAdoptionList::displayAdoptionList() {
    ShellExecuteA(0, "open", this->fileName.c_str(),
                  R"(C:\Program Files\Google\Chrome\Application\chrome.exe)",
                  0, SW_SHOWMAXIMIZED);
}
