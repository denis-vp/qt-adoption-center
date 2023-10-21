//
// Created by qdeni on 01-May-23.
//

#include <fstream>
#include "TxtRepository.h"
#include "../../extra/exceptions.h"


TxtRepository::TxtRepository(const std::string &fileName) : FileRepository(fileName) {}


void TxtRepository::writeToFile() {
    std::ofstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("Could not open file");
    }

    for (auto &elem: this->elements) {
        file << elem;
    }

    file.close();
}


void TxtRepository::readFromFile() {
    std::ifstream file(this->fileName);
    if (!file.is_open()) {
        throw FileException("Could not open file");
    }

    Pet elem;
    while (file >> elem) {
        this->elements.push_back(elem);
    }

    file.close();
}
