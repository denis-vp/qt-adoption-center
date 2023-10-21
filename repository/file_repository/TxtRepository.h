//
// Created by qdeni on 01-May-23.
//

#ifndef A7_DENIS916_1_TXTREPOSITORY_H
#define A7_DENIS916_1_TXTREPOSITORY_H

#include "FileRepository.h"


class TxtRepository : public FileRepository {

    /// Class that represents a repository that reads and writes to a text file.

public:

    /// Constructor for a text repository.
    ///
    /// \param fileName - std::string, the name of the file.
    TxtRepository(const std::string &fileName);

    /// Writes the elements from the repository to the file.
    void writeToFile() override;

    /// Reads the elements from the file to the repository.
    void readFromFile() override;
};


#endif //A7_DENIS916_1_TXTREPOSITORY_H
