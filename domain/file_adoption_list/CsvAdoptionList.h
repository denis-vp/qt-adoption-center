//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_CSVADOPTIONLIST_H
#define A7_DENIS916_1_CSVADOPTIONLIST_H


#include "FileAdoptionList.h"


class CsvAdoptionList : public FileAdoptionList {

    /// Class that represents an adoption list stored in a csv file.

public:

    /// Constructor for a csv adoption list.
    ///
    /// \param fileName - string, the name of the file
    CsvAdoptionList(const std::string &fileName) : FileAdoptionList(fileName) {};

    /// Writes the adoption list to a csv file.
    void writeToFile() override;

    /// Displays the adoption list, opening it with Microsoft Excel.
    void displayAdoptionList() override;
};


#endif //A7_DENIS916_1_CSVADOPTIONLIST_H
