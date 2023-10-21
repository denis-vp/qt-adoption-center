//
// Created by qdeni on 01-May-23.
//

#ifndef A7_DENIS916_1_FILEREPOSITORY_H
#define A7_DENIS916_1_FILEREPOSITORY_H

#include "../Repository.h"


class FileRepository : public Repository {

    /// Class that represents a repository that reads and writes to a file.
    /// It is an abstract class.

protected:
    std::string fileName;

protected:

    /// Writes the elements from the repository to the file.
    virtual void writeToFile() = 0;

    /// Reads the elements from the file to the repository.
    virtual void readFromFile() = 0;

public:

    /// Constructor for a file repository.
    ///
    /// \param fileName - std::string, the name of the file.
    FileRepository(const std::string &fileName);

    /// Adds an element to the repository.
    ///
    /// \param element - type, the element to be added.
    ///
    /// \throws RepositoryException - if the element already exists.
    /// \throws FileException - if the file could not be opened.
    void add(Pet element) override;

    /// Removes an element from the repository by index.
    ///
    /// \param index - int, the index of the element to be removed.
    ///
    /// \throws RepositoryException - if the index is out of range.
    /// \throws FileException - if the file could not be opened.
    void remove(int index) override;

    /// Removes an element from the repository by value.
    ///
    /// \param element - type, the element to be removed.
    ///
    /// \throws RepositoryException - if the element does not exist.
    /// \throws FileException - if the file could not be opened.
    void remove(const Pet &element) override;
};


#endif //A7_DENIS916_1_FILEREPOSITORY_H
