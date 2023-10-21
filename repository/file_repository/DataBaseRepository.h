//
// Created by qdeni on 02-May-23.
//

#ifndef A7_DENIS916_1_DATABASEREPOSITORY_H
#define A7_DENIS916_1_DATABASEREPOSITORY_H

#include "FileRepository.h"


class DataBaseRepository : public FileRepository {
public:

    DataBaseRepository(const std::string &fileName);

    void writeToFile() override;

    void readFromFile() override;
};


#endif //A7_DENIS916_1_DATABASEREPOSITORY_H
