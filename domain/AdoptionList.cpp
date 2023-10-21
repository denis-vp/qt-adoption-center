//
// Created by qdeni on 19-Apr-23.
//

#include "AdoptionList.h"
#include "../extra/exceptions.h"

using std::vector;


AdoptionList::AdoptionList(const AdoptionList &other) {
    this->current = other.current;
    this->pets = other.pets;
}


AdoptionList &AdoptionList::operator=(const AdoptionList &other) {
    if (this == &other) {
        return *this;
    }

    this->current = other.current;
    this->pets = other.pets;

    return *this;
}


void AdoptionList::addPet(const Pet &pet) {
    for (const auto &p: this->pets) {
        if (p == pet) {
            throw AdoptionListException("Pet already in adoption list!");
        }
    }

    this->pets.push_back(pet);
}


vector<Pet> AdoptionList::getAll() const {
    return this->pets;
}


int AdoptionList::size() {
    return int(this->pets.size());
}


bool AdoptionList::empty() {
    return this->pets.empty();
}
