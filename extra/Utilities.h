//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_UTILITIES_H
#define A7_DENIS916_1_UTILITIES_H

#include <string>
#include <vector>


/// Trims a string removing all the spaces from the beginning and the end.
///
/// \param str - the string to be trimmed
/// \return str - the trimmed string
std::string trim(const std::string &str);


/// Tokenizes a string. It splits the string into a vector of strings using the delimiter.
///
/// \param str - the string to be tokenized
/// \param delimiter - the delimiter
/// \return - std::vector <std::string> - the vector of strings
std::vector<std::string> tokenize(const std::string &str, char delimiter);


#endif //A7_DENIS916_1_UTILITIES_H
