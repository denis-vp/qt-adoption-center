//
// Created by qdeni on 20-Apr-23.
//

#include "PetValidator.h"

using std::vector;
using std::string;


PetException::PetException(std::vector<std::string> errors) : errors(errors) {}


std::vector<std::string> PetException::getErrors() const {
    return this->errors;
}


void PetValidator::validate(const Pet &pet) {
    vector<string> errors;

    if (pet.getName().empty()) {
        errors.emplace_back("The name cannot be empty!");
    }
    if (pet.getBreed().empty()) {
        errors.emplace_back("The breed cannot be empty!");
    }
    if (pet.getAge() < 0) {
        errors.emplace_back("The age cannot be negative!");
    }
    if (pet.getPhoto().empty()) {
        errors.emplace_back("The photo cannot be empty!");
    }

    if (!errors.empty()) {
        throw PetException(errors);
    }
}
