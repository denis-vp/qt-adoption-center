//
// Created by qdeni on 19-Apr-23.
//

#include <fstream>
#include <Windows.h>
#include "CsvAdoptionList.h"
#include "../../extra/exceptions.h"


void CsvAdoptionList::writeToFile() {
    std::ofstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("could not open file");
    }

    for (auto pet: this->pets) {
        file << pet;
    }

    file.close();
}


void CsvAdoptionList::displayAdoptionList() {
    ShellExecuteA(nullptr, nullptr,
                  R"(C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Excel.lnk)",
                  this->fileName.c_str(), nullptr, SW_SHOWMAXIMIZED);
}
