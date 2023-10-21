//
// Created by qdeni on 19-Apr-23.
//

#include <algorithm>
#include "PetService.h"
#include "../domain/file_adoption_list/CsvAdoptionList.h"
#include "../domain/file_adoption_list/HtmlAdoptionList.h"
#include "../extra/exceptions.h"


using std::vector;
using std::string;

string DIR_PATH = R"(..\files\)";


PetService::PetService(const TxtRepository &repository, FileAdoptionList *adoptionList) : repository(repository), adoptionList(adoptionList) {}


PetService::PetService(const PetService &other) : repository(other.repository), adoptionList(other.adoptionList) {};


PetService &PetService::operator=(const PetService &other) {
    if (this == &other) {
        return *this;
    }

    this->repository = other.repository;
    this->adoptionList = other.adoptionList;

    return *this;
}


void PetService::modifyFileFormat(const std::string &fileFormat) {
    if (fileFormat == "csv") {
        this->adoptionList = new CsvAdoptionList(DIR_PATH + "adoption_list.csv");
    } else if (fileFormat == "html") {
        this->adoptionList = new HtmlAdoptionList(DIR_PATH + "adoption_list.html");
    } else {
        throw ServiceException("Invalid file format!");
    }
}


void PetService::addPet(const std::string &name, const std::string &breed, int age, const std::string &photo) {
    Pet newPet(name, breed, age, photo);
    try {
        PetValidator::validate(newPet);
    } catch (std::exception &exception) {
        throw ServiceException("Invalid pet data!");
    }

    auto pets = this->repository.getAll();
    for (const auto& pet : pets) {
        if (pet.getId() == std::make_tuple(name, breed)) {
            throw ServiceException("Pet already exists!");
        }
    }

    this->repository.add(newPet);
}


void PetService::removePet(const std::string &name, const std::string &breed) {
    for (int i = 0; i < this->repository.size(); i++) {
        Pet &currentPet = this->repository[i];
        if (currentPet.getId() == std::make_tuple(name, breed)) {
            this->repository.remove(i);
            return;
        }
    }
    throw ServiceException("Pet not found!");
}


void PetService::updatePet(const std::string &name, const std::string &breed, int newAge, const std::string &newPhoto) {
    Pet newPet(name, breed, newAge, newPhoto);
    try {
        PetValidator::validate(newPet);
    } catch (std::exception &exception) {
        throw ServiceException("Invalid pet data!");
    }

    for (int i = 0; i < this->repository.size(); i++) {
        Pet &currentPet = this->repository[i];
        if (currentPet.getId() == std::make_tuple(name, breed)) {
            currentPet.setAge(newAge);
            currentPet.setPhoto(newPhoto);

            this->repository.writeToFile();
            return;
        }
    }
    throw ServiceException("Pet not found!");
}


vector<Pet> PetService::getAll() {
    return this->repository.getAll();
}


void PetService::addPetToAdoptionList(const string &name, const string &breed) {
    auto pets = this->adoptionList->getAll();
    for (const auto& pet : pets) {
        if (pet.getId() == std::make_tuple(name, breed)) {
            throw ServiceException("Pet already in adoption list!");
        }
    }

    for (int i = 0; i < this->repository.size(); i++) {
        Pet currentPet = this->repository[i];
        if (currentPet.getId() == std::make_tuple(name, breed)) {
            this->adoptionList->addPet(currentPet);
            return;
        }
    }
    throw ServiceException("Pet not found!");
}


vector<Pet> PetService::getAdoptionList() const {
    return this->adoptionList->getAll();
}


void PetService::saveAdoptionList() {
    this->adoptionList->writeToFile();
}


void PetService::openAdoptionList() {
    this->adoptionList->writeToFile();
    this->adoptionList->displayAdoptionList();
}


vector<Pet> PetService::filterByAge(int age) {
    vector<Pet> filteredPets;

    auto pets = this->repository.getAll();
    std::copy_if(pets.begin(), pets.end(), std::back_inserter(filteredPets),
                 [age](const Pet& pet) {return pet.getAge() < age;});

    return filteredPets;
}


vector<Pet> PetService::filterByBreedAndAge(const string &breed, int age) {
    vector<Pet> filteredPets;
    string filterBreed = breed;
    std::transform(filterBreed.begin(), filterBreed.end(), filterBreed.begin(), ::tolower);

    auto pets = this->repository.getAll();
    std::copy_if(pets.begin(), pets.end(), std::back_inserter(filteredPets),
                 [filterBreed, age](const Pet& pet) {
                     string currentBreed = pet.getBreed();
                     std::transform(currentBreed.begin(), currentBreed.end(), currentBreed.begin(), ::tolower);
                     return currentBreed == filterBreed && pet.getAge() < age;
                 });

    return filteredPets;
}
