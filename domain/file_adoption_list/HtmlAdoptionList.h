//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_HTMLADOPTIONLIST_H
#define A7_DENIS916_1_HTMLADOPTIONLIST_H


#include "FileAdoptionList.h"


class HtmlAdoptionList : public FileAdoptionList {

    /// Class that represents an adoption list stored in a html file.

public:

    /// Constructor for a html adoption list.
    ///
    /// \param fileName - string, the name of the file
    HtmlAdoptionList(const std::string &fileName) : FileAdoptionList(fileName) {};

    /// Writes the adoption list to a html file.
    void writeToFile() override;

    /// Displays the adoption list, opening it with Google Chrome.
    void displayAdoptionList() override;
};


#endif //A7_DENIS916_1_HTMLADOPTIONLIST_H
