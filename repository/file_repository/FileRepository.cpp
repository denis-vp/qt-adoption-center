//
// Created by qdeni on 01-May-23.
//

#include "FileRepository.h"

FileRepository::FileRepository(const std::string &fileName) : fileName(fileName) {}


void FileRepository::add(Pet element) {
    Repository::add(element);
    this->writeToFile();
}


void FileRepository::remove(int index) {
    Repository::remove(index);
    this->writeToFile();
}

void FileRepository::remove(const Pet &element) {
    Repository::remove(element);
    this->writeToFile();
};
