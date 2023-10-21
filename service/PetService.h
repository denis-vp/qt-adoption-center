//
// Created by qdeni on 19-Apr-23.
//

#ifndef A7_DENIS916_1_PETSERVICE_H
#define A7_DENIS916_1_PETSERVICE_H


#include "../domain/Pet.h"
#include "../validators/PetValidator.h"
#include "../domain/file_adoption_list/FileAdoptionList.h"
#include "../repository/file_repository/TxtRepository.h"


class PetService {

    /// Class that manages the business logic of the application.
    /// It is responsible for validating the data and calling the repository methods.

private:
    TxtRepository repository;
    FileAdoptionList *adoptionList;

public:
    PetService() : repository("../files/data.txt"), adoptionList(nullptr) {};

    /// Constructor for a PetService object.
    ///
    /// \param repository - Repository<Pet> object, the repository that will be used to store the pets.
    /// \param adoptionList - AdoptionList object, the adoption list that will be used to store the pets that will be adopted.
    PetService(const TxtRepository &repository, FileAdoptionList *adoptionList);

    /// Copy constructor for a PetService object.
    ///
    /// \param other - PetService object, the object that will be copied.
    PetService(const PetService &other);

    /// Destructor for a PetService object.
    ~PetService() = default;

    /// Assignment operator for a PetService object.
    ///
    /// \param other - PetService object, the object that will be assigned.
    PetService &operator=(const PetService &other);

    /// Changes the file format of the adoption list.
    ///
    /// \param fileFormat - std::string, the new file format.
    ///
    /// \throws ServiceException - if the file format is invalid.
    void modifyFileFormat(std::string const &fileFormat);

    /// Adds a new pet to the repository.
    ///
    /// \param name - std::string, the name of the pet.
    /// \param breed - std::string, the breed of the pet.
    /// \param age - int, the age of the pet.
    /// \param photo - std::string, the link to a photo of the pet.
    ///
    /// \throws ServiceException - if the pet already exists.
    /// \throws ServiceException - if the pet is invalid.
    void addPet(std::string const &name, std::string const &breed, int age, std::string const &photo);

    /// Removes a pet from the repository.
    ///
    /// \param name - std::string, the name of the pet.
    /// \param breed - std::string, the breed of the pet.
    ///
    /// \throws ServiceException - if the pet does not exist.
    void removePet(std::string const &name, std::string const &breed);

    /// Updates the data of a pet.
    ///
    /// \param name - std::string, the name of the pet.
    /// \param breed - std::string, the breed of the pet.
    /// \param newAge - int, the new age of the pet.
    /// \param newPhoto - std::string, the new link to a photo of the pet.
    ///
    /// \throws ServiceException - if the pet does not exist.
    /// \throws ServiceException - if the pet is invalid.
    void updatePet(std::string const &name, std::string const &breed, int newAge, std::string const &newPhoto);

    /// Returns a vector containing all the pets in the repository.
    ///
    /// \return std::vector<Pet>, a vector containing all the pets in the repository.
    std::vector<Pet> getAll();

    /// Adds a pet to the adoption list.
    ///
    /// \param name - std::string, the name of the pet.
    /// \param breed - std::string, the breed of the pet.
    ///
    /// \throws ServiceException - if the pet does not exist.
    /// \throws ServiceException - if the pet is already in the adoption list.
    void addPetToAdoptionList(std::string const &name, std::string const &breed);

    /// Returns a vector containing all the pets in the adoption list.
    ///
    /// \return - std::vector<Pet>, a vector containing all the pets in the adoption list.
    std::vector<Pet> getAdoptionList() const;

    /// Saves the adoption list to a file.
    ///
    /// \FileException - if the file cannot be opened.
    void saveAdoptionList();

    /// Saves and opens the adoption list.
    ///
    /// \FileException - if the file cannot be opened.
    void openAdoptionList();

    /// Returns a vector containing all the pets in the repository that have an age less than a given age.
    ///
    /// \param age - int, the given age.
    ///
    /// \return - std::vector<Pet>, a vector containing all the pets in the repository that have an age less than a given age.
    std::vector<Pet> filterByAge(int age);

    /// Returns a vector containing all the pets in the repository that have a breed equal to a given breed and
    /// an age less than a given age.
    ///
    /// \param breed - std::string, the given breed.
    /// \param age - int, the given age.
    ///
    /// \return - std::vector<Pet>, a vector containing all the pets in the repository that have a breed equal to a given breed and
    ///           an age less than a given age.
    std::vector<Pet> filterByBreedAndAge(std::string const &breed, int age);
};


#endif //A7_DENIS916_1_PETSERVICE_H
