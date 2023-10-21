//
// Created by qdeni on 01-May-23.
//

#include <algorithm>
#include "Repository.h"
#include "../extra/exceptions.h"


Repository::Repository(const Repository &other) : elements(other.elements) {};


Repository &Repository::operator=(const Repository &other) {
    if (this == &other) {
        return *this;
    }

    this->elements = other.elements;

    return *this;
}


void Repository::add(Pet element) {
    for (auto &elem: this->elements) {
        if (elem == element) {
            throw RepositoryException("element already exists");
        }
    }

    this->elements.push_back(element);
}


void Repository::remove(int index) {
    if (index >= this->elements.size()) {
        throw RepositoryException("Index out of range");
    }

    this->elements.erase(this->elements.begin() + index);
}


void Repository::remove(const Pet &element) {
    if (!this->search(element)) {
        throw RepositoryException("element not found");
    }

    this->elements.erase(std::remove(this->elements.begin(), this->elements.end(), element), this->elements.end());

}


Pet &Repository::operator[](int index) {
    return this->elements[index];
}


std::vector<Pet> Repository::getAll() {
    return this->elements;
}


int Repository::size() {
    return int(this->elements.size());
}


bool Repository::empty() {
    return this->elements.empty();
}


bool Repository::search(const Pet &element) {
    auto it = std::find(this->elements.begin(), this->elements.end(), element);
    return it != this->elements.end();
}
