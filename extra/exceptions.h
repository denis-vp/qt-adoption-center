//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_EXCEPTIONS_H
#define A7_DENIS916_1_EXCEPTIONS_H

#include <exception>
#include <string>


class CustomException : public std::exception {

    /// This class is used to create custom exceptions.

protected:
    std::string message;

public:

    /// Constructor.
    CustomException(const std::string &msg) : message(msg) {};

    /// Returns the message of the exception.
    virtual const char *what() {
        return this->message.c_str();
    }
};


class RepositoryException : public CustomException {

    /// This class is used to create repository exceptions.

public:

    /// Constructor.
    RepositoryException(const std::string &msg) : CustomException(msg) {};

    /// Returns the message of the exception.
    const char *what() override {
        return this->message.c_str();
    }
};


class FileException : public CustomException {

    /// This class is used to create file exceptions.

public:

    /// Constructor.
    FileException(const std::string &msg) : CustomException(msg) {};

    /// Returns the message of the exception.
    const char *what() override {
        return this->message.c_str();
    }
};


class AdoptionListException : public CustomException {

    /// This class is used to create adoption list exceptions.

public:

    /// Constructor.
    AdoptionListException(const std::string &msg) : CustomException(msg) {};

    /// Returns the message of the exception.
    const char *what() override {
        return this->message.c_str();
    }
};


class ServiceException : public CustomException {

    /// This class is used to create service exceptions.

public:

    /// Constructor.
    ServiceException(const std::string &msg) : CustomException(msg) {};

    /// Returns the message of the exception.
    const char *what() override {
        return this->message.c_str();
    }
};

#endif //A7_DENIS916_1_EXCEPTIONS_H
