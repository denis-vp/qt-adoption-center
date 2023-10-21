//
// Created by qdeni on 3/23/2023.
//

#include <iostream>
#include <Windows.h>
#include "Ui.h"
#include "../extra/exceptions.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;


void Ui::run() {
    Ui::printTitle();

    int option;
    try {
        while (true) {
            cout << "\n1. Admin" << endl;
            cout << "2. User" << endl;
            cout << "0. Exit" << endl;

            option = Ui::getOption();

            if (option == 1)
                this->runAdmin();
            else if (option == 2)
                this->runUser();
            else if (option == 0)
                break;
            else
                cout << "Invalid option!" << endl;
        }
    }
    catch (CustomException &exception) {
        cout << exception.what() << endl;
    }
}

void Ui::printTitle() {
    cout << "|-------------------------------|" << endl;
    cout << "| ------ Pet Shelter App ------ |" << endl;
    cout << "|-------------------------------|" << endl;
}

void Ui::runAdmin() {
    int option;
    while (true) {
        Ui::printAdminMenu();

        option = Ui::getOption();

        try {
            switch (option) {
                default: {
                    cout << "Invalid option!" << endl;
                    break;
                }

                case 1: {
                    /// Add a new pet.

                    string name = Ui::getName();
                    string breed = Ui::getBreed();
                    int age = Ui::getAge();
                    string photo = Ui::getPhoto();
                    this->petService.addPet(name, breed, age, photo);

                    break;
                }

                case 2: {
                    /// Remove a pet.

                    string name = Ui::getName();
                    string breed = Ui::getBreed();
                    this->petService.removePet(name, breed);

                    break;
                }

                case 3: {
                    /// Update a pet.

                    string name = Ui::getName();
                    string breed = Ui::getBreed();
                    int newAge = Ui::getAge();
                    string newPhoto = Ui::getPhoto();
                    this->petService.updatePet(name, breed, newAge, newPhoto);

                    break;
                }

                case 4: {
                    /// List all pets.

                    vector<Pet> pets = this->petService.getAll();
                    if (pets.empty()) {
                        cout << "There are no pets in the shelter." << endl;
                        break;
                    }
                    cout << "Pets:" << endl;
                    for (const auto &pet : pets)
                        cout << "\n-> " << pet.toString() << endl;
                    cout << endl;

                    break;
                }

                case 0: {
                    return;
                }
            }
        }
        catch (CustomException &exception) {
            cout << exception.what() << endl;
        }
    }
}

void Ui::runUser() {
    string fileFormat;
    while (true) {
        try {
            fileFormat = Ui::getFileFormat();
            this->petService.modifyFileFormat(fileFormat);
            break;
        }
        catch (ServiceException &exception) {
            cout << exception.what() << endl;
            continue;
        }
    }

    int option;
    while (true) {
        Ui::printUserMenu();

        option = Ui::getOption();

        try {
            switch (option) {
                default: {
                    cout << "Invalid option!" << endl;
                    break;
                }

                case 0: {
                    return;
                }

                case 1: {
                    /// Cycle through the pets.

                    vector<Pet> pets = this->petService.getAll();
                    if (pets.empty()) {
                        cout << "There are no pets in the shelter." << endl;
                        break;
                    }

                    auto currentPet = pets.begin();
                    while (true) {
                        Ui::printPet(*currentPet);

                        int cycleOption;
                        while (true) {
                            cout << "\n1. Next pet" << endl;
                            cout << "2. Adopt pet" << endl;
                            cout << "0. Back" << endl;

                            cycleOption = Ui::getOption();

                            if (cycleOption == 1 || cycleOption == 0)
                                break;
                            else if (cycleOption == 2) {
                                try {
                                    this->petService.addPetToAdoptionList(currentPet->getName(), currentPet->getBreed());
                                }
                                catch (CustomException &exception) {
                                    cout << exception.what() << endl;
                                }
                                break;
                            }
                            else
                                cout << "Invalid option!" << endl;
                        }
                        if (cycleOption == 0)
                            break;

                        if (currentPet == pets.end() - 1)
                            currentPet = pets.begin();
                        else
                            currentPet++;
                    }
                    break;
                }

                case 2: {
                    /// Filter pets by breed and age.

                    string breed = Ui::getBreed();
                    int age = Ui::getAge();

                    if (breed.empty()) {
                        vector<Pet> filteredPets = this->petService.filterByAge(age);
                        if (filteredPets.empty()) {
                            cout << "There are no such pets in the shelter." << endl << endl;
                            break;
                        }
                        cout << "Pets:" << endl;
                        for (const auto &pet : filteredPets)
                            cout << "\n-> " << pet.toString() << endl;
                        cout << endl;

                        break;
                    }

                    vector<Pet> filteredPets = this->petService.filterByBreedAndAge(breed, age);
                    if (filteredPets.empty()) {
                        cout << "There are no such pets in the shelter." << endl << endl;
                        break;
                    }
                    cout << "Pets:" << endl;
                    for (const auto &pet : filteredPets)
                        cout << "\n-> " << pet.toString() << endl;
                    cout << endl;

                    break;
                }

                case 3: {
                    /// See the adoption list.

                    auto adoptionList = this->petService.getAdoptionList();
                    if (adoptionList.empty()) {
                        cout << "There are no pets in the adoption list." << endl << endl;
                        break;
                    }
                    cout << "Adoption list:" << endl;
                    for (const auto &pet : adoptionList)
                        cout << "\n-> " << pet.toString() << endl;
                    cout << endl;

                    break;
                }

                case 4: {
                    /// Save the adoption list.

                    if (this->petService.getAdoptionList().empty()) {
                        cout << "There are no pets in the adoption list." << endl << endl;
                        break;
                    }

                    try {
                        this->petService.saveAdoptionList();
                    }
                    catch (CustomException &exception) {
                        cout << exception.what() << endl;
                    }

                    break;
                }

                case 5: {
                    /// Open the adoption list.

                    if (this->petService.getAdoptionList().empty()) {
                        cout << "There are no pets in the adoption list." << endl << endl;
                        break;
                    }

                    try {
                        this->petService.openAdoptionList();
                    }
                    catch (CustomException &exception) {
                        cout << exception.what() << endl;
                    }

                    break;
                }
            }
        }
        catch (CustomException &exception) {
            cout << exception.what() << endl;
        }
    }
}

void Ui::printAdminMenu() {
    cout << "\n1. Add a new pet." << endl;
    cout << "2. Remove a pet." << endl;
    cout << "3. Update a pet." << endl;
    cout << "4. List all pets." << endl;
    cout << "0. Exit." << endl;
}

void Ui::printUserMenu() {
    cout << "1. Cycle through the pets" << endl;
    cout << "2. Filter pets by breed and age" << endl;
    cout << "3. See the adoption list" << endl;
    cout << "4. Save the adoption list" << endl;
    cout << "5. Open the adoption list" << endl;
    cout << "0. Exit." << endl;
}

void Ui::printPet(const Pet &pet) {
    cout << "Name: " << pet.getName() << endl;
    cout << "Breed: " << pet.getBreed() << endl;
    cout << "Age: " << pet.getAge() << endl;

    ShellExecuteA(nullptr, nullptr, "chrome.exe",
                 pet.getPhoto().c_str(), nullptr, SW_SHOWNORMAL);
}

int Ui::getOption() {
    int option;
    cout << "Option:";

    while (!(cin >> option)) {
        cout << "\nInvalid input!" << endl;
        cout << "Option:";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << endl;
    return option;
}

string Ui::getFileFormat() {
    string fileFormat;
    cout << "File format:";

    while (true) {
        cin >> fileFormat;
        if (fileFormat == "csv" || fileFormat == "html")
            break;
        cout << "\nInvalid input!" << endl;
        cout << "File format:";
    }

    cout << endl;
    return fileFormat;
}

string Ui::getName() {
    string name;
    cout << "Name:";
    fflush(stdin);
    getline(cin, name);
    return name;
}

string Ui::getBreed() {
    string breed;
    cout << "Breed:";
    fflush(stdin);
    getline(cin, breed);
    return breed;
}

int Ui::getAge() {
    int age;
    cout << "Age:";

    while (!(cin >> age)) {
        cout << "\nInvalid input!" << endl;
        cout << "Age:";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return age;
}

string Ui::getPhoto() {
    string photo;
    cout << "Photo:";
    fflush(stdin);
    getline(cin, photo);
    return photo;
}
