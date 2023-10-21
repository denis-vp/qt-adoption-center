//
// Created by qdeni on 01-May-23.
//

#ifndef A7_DENIS916_1_REPOSITORY_H
#define A7_DENIS916_1_REPOSITORY_H

#include <vector>
#include "../domain/Pet.h"


class Repository {

    /// Class that represents a repository.

protected:
    std::vector<Pet> elements;

public:

    /// Default constructor for a repository.
    Repository() = default;

    /// Copy constructor for a repository.
    ///
    /// \param other - Repository<type>, the repository to be copied.
    Repository(const Repository &other);

    /// Destructor for a repository.
    ~Repository() = default;

    /// Assignment operator for a repository.
    ///
    /// \param other - Repository<type>, the repository to be assigned.
    /// \return - the current repository.
    Repository &operator=(const Repository &other);

    /// Adds an element to the repository.
    ///
    /// \param element - type, the element to be added.
    ///
    /// \throws RepositoryException - if the element already exists.
    virtual void add(Pet element);

    /// Removes an element from the repository by index.
    ///
    /// \param index - int, the index of the element to be removed.
    ///
    /// \throws RepositoryException - if the index is out of range.
    virtual void remove(int index);

    /// Removes an element from the repository by value.
    ///
    /// \param element - type, the element to be removed.
    ///
    /// \throws RepositoryException - if the element does not exist.
    virtual void remove(const Pet &element);

    /// Overload of the [] operator.
    ///
    /// \param index - int, the index of the element to be returned.
    ///
    /// \return - type, the element at the given index.
    Pet &operator[](int index);

    /// Returns all the elements from the repository.
    ///
    /// \return - std::vector<type>, all the elements from the repository.
    std::vector<Pet> getAll();

    /// Returns the size of the repository.
    ///
    /// \return - int, the size of the repository.
    int size();

    /// Checks if the repository is empty.
    ///
    /// \return - bool, true if the repository is empty, false otherwise.
    bool empty();

    /// Searches for an element in the repository.
    ///
    /// \param element - type, the element to be searched.
    ///
    /// \return - bool, true if the element exists, false otherwise.
    bool search(const Pet &element);
};


#endif //A7_DENIS916_1_REPOSITORY_H
