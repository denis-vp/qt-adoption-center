//
// Created by qdeni on 20-Apr-23.
//

#ifndef A7_DENIS916_1_PETVALIDATOR_H
#define A7_DENIS916_1_PETVALIDATOR_H

#include <vector>
#include <string>
#include "../domain/Pet.h"


class PetException : public std::exception {

    /// Class that represents an exception for a pet.

private:
    std::vector<std::string> errors;

public:

    /// Constructor for a PetException.
    ///
    /// \param errors - vector of strings, the errors
    PetException(std::vector<std::string> errors);

    /// Getter for the errors.
    std::vector<std::string> getErrors() const;
};


class PetValidator {

    /// Class that represents a validator for a pet.

public:

    /// Default constructor for a PetValidator.
    PetValidator() = default;

    /// Validates a pet.
    ///
    /// \param pet - Pet, the pet to be validated
    ///
    /// \throws PetException - if the pet is invalid
    static void validate(const Pet &pet);
};


#endif //A7_DENIS916_1_PETVALIDATOR_H
