//
// Created by qdeni on 02-May-23.
//

#include "DataBaseRepository.h"
//#include <mysql.h>


DataBaseRepository::DataBaseRepository(const std::string &fileName) : FileRepository(fileName) {}


void DataBaseRepository::writeToFile() {
//    MYSQL *conn;
//    conn = mysql_init(0);
//    conn = mysql_real_connect(conn, this->fileName);
}


void DataBaseRepository::readFromFile() {

}