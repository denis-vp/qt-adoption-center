//
// Created by qdeni on 19-Apr-23.
//

#include <vector>
#include "Pet.h"
#include "../extra/Utilities.h"

using std::string;
using std::vector;
using std::tuple;


Pet::Pet(string const &name, string const &breed, int age, string const &photo) {
    this->name = name;
    this->breed = breed;
    this->age = age;
    this->photo = photo;
}


Pet::Pet(const Pet &other) {
    this->name = other.name;
    this->breed = other.breed;
    this->age = other.age;
    this->photo = other.photo;
}


Pet &Pet::operator=(const Pet &other) {
    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    this->breed = other.breed;
    this->age = other.age;
    this->photo = other.photo;

    return *this;
}


string Pet::getName() const {
    return this->name;
}


string Pet::getBreed() const {
    return this->breed;
}

int Pet::getAge() const {
    return this->age;
}


string Pet::getPhoto() const {
    return this->photo;
}


void Pet::setName(string const &newName) {
    this->name = newName;
}


void Pet::setBreed(string const &newBreed) {
    this->breed = newBreed;
}


void Pet::setAge(int newAge) {
    this->age = newAge;
}


void Pet::setPhoto(string const &newPhoto) {
    this->photo = newPhoto;
}


tuple<string, string> Pet::getId() const {
    return {this->name, this->breed};
}


bool Pet::operator==(const Pet &other) const {
    return this->name == other.name && this->breed == other.breed && this->age == other.age &&
           this->photo == other.photo;
}


bool Pet::operator!=(const Pet &other) const {
    return !(*this == other);
}


string Pet::toString() const {
    return this->name + " " + this->breed + " " + std::to_string(this->age) + "\n" + this->photo;
}


std::istream &operator>>(std::istream &inputStream, Pet &pet) {
    string line;
    getline(inputStream, line);

    vector<string> tokens = tokenize(line, ',');
    if (tokens.size() != 4) {
        return inputStream;
    }

    pet.name = tokens[0];
    pet.breed = tokens[1];
    pet.age = std::stoi(tokens[2]);
    pet.photo = tokens[3];

    return inputStream;
}


std::ostream &operator<<(std::ostream &outputStream, Pet &pet) {
    outputStream << pet.name << "," << pet.breed << "," << pet.age << "," << pet.photo << std::endl;

    return outputStream;
}
