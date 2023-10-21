//
// Created by qdeni on 3/23/2023.
//

#ifndef A45_DENIS916_UI_H
#define A45_DENIS916_UI_H


#include "../service/PetService.h"

class Ui {
private:
    PetService petService;

public:
    Ui(const PetService &petService) : petService(petService) {};

    ~Ui() = default;

    void run();

private:
    static void printTitle();

    void runAdmin();

    void runUser();

    static void printAdminMenu();

    static void printUserMenu();

    static void printPet(const Pet &pet);

    static int getOption();

    static std::string getFileFormat();

    static std::string getName();

    static std::string getBreed();

    static int getAge();

    static std::string getPhoto();
};


#endif //A45_DENIS916_UI_H
