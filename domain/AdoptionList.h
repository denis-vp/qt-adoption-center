//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_ADOPTIONLIST_H
#define A7_DENIS916_1_ADOPTIONLIST_H

#include <vector>
#include "Pet.h"


class AdoptionList {

    /// Class that represents an adoption list.
    /// An adoption list is a list of pets that can be adopted.

protected:
    std::vector<Pet> pets;
    int current;

public:

    /// Default constructor for an adoption list.
    /// The adoption list is initially empty.
    AdoptionList() : current(0) {};

    /// Copy constructor for an adoption list.
    ///
    /// \param other - AdoptionList, the adoption list to be copied
    AdoptionList(const AdoptionList &other);

    /// Destructor for an adoption list.
    virtual ~AdoptionList() = default;

    /// Overload of the = operator for an adoption list.
    ///
    /// \param adoptionList - AdoptionList, the adoption list to be copied
    /// \return - AdoptionList, the new adoption list
    AdoptionList &operator=(const AdoptionList &adoptionList);

    /// Adds a pet to the adoption list.
    ///
    /// \param pet - Pet, the pet to be added
    ///
    /// \throws AdoptionListException - if the pet is already in the adoption list
    void addPet(const Pet &pet);

    /// Gets all the pets from the adoption list.
    ///
    /// \return - std::vector<Pet>, the pets from the adoption list
    std::vector<Pet> getAll() const;

    /// Gets the size of the adoption list.
    ///
    /// \return - int, the size of the adoption list
    int size();

    /// Checks if the adoption list is empty.
    ///
    /// \return - bool, true if the adoption list is empty, false otherwise
    bool empty();
};


#endif //A7_DENIS916_1_ADOPTIONLIST_H
