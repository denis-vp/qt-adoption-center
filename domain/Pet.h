//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_PET_H
#define A7_DENIS916_1_PET_H

#include <string>
#include <tuple>
#include <iostream>

class Pet {

    /// Class that represents a pet.
    /// A pet has a name, a breed, an age and a photo.
    /// The name and the breed are strings, the age is an integer and the photo is a string.
    /// A pet is uniquely identified by its name and its breed.

private:
    std::string name;
    std::string breed;
    int age;
    std::string photo;

public:

    /// Default constructor for a Pet.
    /// The name, the breed and the photo are empty strings, while the age is 0.
    Pet() : age(0) {};

    /// Constructor with parameters for a Pet.
    ///
    /// \param name - string, the name of the pet
    /// \param breed - string, the breed of the pet
    /// \param age - integer, the age of the pet
    /// \param photo - string, the photo of the pet
    Pet(std::string const &name, std::string const &breed, int age, std::string const &photo);

    /// Copy constructor for a Pet.
    ///
    /// \param other - Pet, the pet to be copied
    Pet(const Pet &other);

    /// Destructor for a Pet.
    ~Pet() = default;

    /// Overload of the = operator for a Pet.
    ///
    /// \param other - Pet, the pet to be copied
    /// \return - Pet, the new pet
    Pet &operator=(const Pet &other);

    /// Getter for the name of a Pet.
    ///
    /// \return - string, the name of the pet
    std::string getName() const;

    /// Getter for the breed of a Pet.
    ///
    /// \return - string, the breed of the pet
    std::string getBreed() const;

    /// Getter for the age of a Pet.
    ///
    /// \return - int, the age of the pet
    int getAge() const;

    /// Getter for the photo of a Pet.
    ///
    /// \return - string, the photo of the pet
    std::string getPhoto() const;

    /// Setter for the name of a Pet.
    ///
    /// \param newName - string, the new name of the pet
    void setName(std::string const &newName);

    /// Setter for the breed of a Pet.
    ///
    /// \param newBreed - string, the new breed of the pet
    void setBreed(std::string const &newBreed);

    /// Setter for the age of a Pet.
    ///
    /// \param newAge - int, the new age of the pet
    void setAge(int newAge);

    /// Setter for the photo of a Pet.
    ///
    /// \param newPhoto - string, the new photo of the pet
    void setPhoto(std::string const &newPhoto);

    /// Getter for the id of a Pet.
    /// The id of a pet is a tuple of strings, where the first element is the name of the pet
    /// and the second element is the breed of the pet.
    ///
    /// \return - tuple<string, string>, the id of the pet
    std::tuple<std::string, std::string> getId() const;

    /// Overloading of the equality operator for a Pet.
    /// Two pets are equal if all their attributes are equal.
    bool operator==(const Pet &other) const;

    /// Overloading of the inequality operator for a Pet.
    bool operator!=(const Pet &other) const;

    /// String representation of a Pet.
    ///
    /// \return - string, the string representation of the pet
    std::string toString() const;

    /// Overloading of the extraction operator for a Pet.
    ///
    /// \param inputStream - istream, the input stream
    /// \param pet - Pet, the pet to be extracted from the input stream
    /// \return - istream, the input stream
    friend std::istream &operator>>(std::istream &inputStream, Pet& pet);

    /// Overloading of the insertion operator for a Pet.
    ///
    /// \param outputStream - ostream, the output stream
    /// \param pet - Pet, the pet to be inserted into the output stream
    /// \return - ostream, the output stream
    friend std::ostream &operator<<(std::ostream &outputStream, Pet& pet);
};


#endif //A7_DENIS916_1_PET_H
