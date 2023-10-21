//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_FILEADOPTIONLIST_H
#define A7_DENIS916_1_FILEADOPTIONLIST_H

#include "../AdoptionList.h"


class FileAdoptionList : public AdoptionList {

    /// Class that represents an adoption list stored in a file.
    /// It is an abstract class.

protected:
    std::string fileName;

public:

    /// Constructor for a file adoption list.
    ///
    /// \param fileName - string, the name of the file
    FileAdoptionList(const std::string &fileName) : fileName(fileName) {};

    /// Writes the adoption list to a file.
    virtual void writeToFile() = 0;

    /// Displays the adoption list, opening it with the appropriate application.
    virtual void displayAdoptionList() = 0;
};


#endif //A7_DENIS916_1_FILEADOPTIONLIST_H
