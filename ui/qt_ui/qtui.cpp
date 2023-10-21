//
// Created by qdeni on 5/14/2023.
//

#include <Windows.h>
#include "qtui.h"
#include "ui_QtUi.h"
#include "../../extra/exceptions.h"

using namespace std;


QtUi::QtUi(QWidget *parent, const PetService &petService) : QWidget(parent), ui(new Ui::QtUi), petService(petService) {
    ui->setupUi(this);

    // the forms
    this->adminWindow = new QWidget();
    this->userWindow = new QWidget();
    this->icon = new QIcon("../resources/icon.png");

    // ------------------ modes ------------------

    // style the modes form
    this->setWindowIcon(*this->icon);

    // ------------------ admin ------------------

    // admin layout
    this->adminLayout = new QHBoxLayout();
    this->adminOutputLayout = new QVBoxLayout();
    this->adminCommandsLayout = new QVBoxLayout();
    this->adminAddLayout = new QGridLayout();
    this->adminRemoveLayout = new QGridLayout();
    this->adminUpdateLayout = new QGridLayout();

    // admin output elements
    this->adminList = new QListWidget();
    this->adminOutputLine = new QLineEdit();
    this->adminOutputLine->setReadOnly(true);

    // admin buttons
    this->adminAddButton = new QPushButton("Add");
    this->adminRemoveButton = new QPushButton("Remove");
    this->adminUpdateButton = new QPushButton("Update");
    this->adminBackButton = new QPushButton("Back");

    // admin add input fields
    this->adminAddNameLine = new QLineEdit();
    this->adminAddBreedLine = new QLineEdit();
    this->adminAddAgeLine = new QLineEdit();
    this->adminAddPhotoLine = new QLineEdit();
    // admin add labels
    this->adminAddNameLabel = new QLabel("Name");
    this->adminAddBreedLabel = new QLabel("Breed");
    this->adminAddAgeLabel = new QLabel("Age");
    this->adminAddPhotoLabel = new QLabel("Photo");

    // admin remove input fields
    this->adminRemoveNameLine = new QLineEdit();
    this->adminRemoveBreedLine = new QLineEdit();
    // admin remove labels
    this->adminRemoveNameLabel = new QLabel("Name");
    this->adminRemoveBreedLabel = new QLabel("Breed");

    // admin update input fields
    this->adminUpdateNameLine = new QLineEdit();
    this->adminUpdateBreedLine = new QLineEdit();
    this->adminUpdateAgeLine = new QLineEdit();
    this->adminUpdatePhotoLine = new QLineEdit();
    // admin update labels
    this->adminUpdateNameLabel = new QLabel("Name");
    this->adminUpdateBreedLabel = new QLabel("Breed");
    this->adminUpdateAgeLabel = new QLabel("Age");
    this->adminUpdatePhotoLabel = new QLabel("Photo");

    // add layouts to the form
    this->adminLayout->addLayout(this->adminOutputLayout);
    this->adminLayout->addLayout(this->adminCommandsLayout);
    this->adminCommandsLayout->addLayout(this->adminAddLayout);
    this->adminCommandsLayout->addLayout(this->adminRemoveLayout);
    this->adminCommandsLayout->addLayout(this->adminUpdateLayout);
    this->adminCommandsLayout->addWidget(this->adminBackButton);

    // add the elements to the output layout
    this->adminOutputLayout->addWidget(this->adminList);
    this->adminOutputLayout->addWidget(this->adminOutputLine);

    // add the elements to the add layout
    this->adminAddLayout->addWidget(this->adminAddNameLabel, 0, 0);
    this->adminAddLayout->addWidget(this->adminAddNameLine, 0, 1);
    this->adminAddLayout->addWidget(this->adminAddBreedLabel, 1, 0);
    this->adminAddLayout->addWidget(this->adminAddBreedLine, 1, 1);
    this->adminAddLayout->addWidget(this->adminAddAgeLabel, 2, 0);
    this->adminAddLayout->addWidget(this->adminAddAgeLine, 2, 1);
    this->adminAddLayout->addWidget(this->adminAddPhotoLabel, 3, 0);
    this->adminAddLayout->addWidget(this->adminAddPhotoLine, 3, 1);
    this->adminAddLayout->addWidget(this->adminAddButton, 4, 0, 1, 2);

    // add the elements to the remove layout
    this->adminRemoveLayout->addWidget(this->adminRemoveNameLabel, 0, 0);
    this->adminRemoveLayout->addWidget(this->adminRemoveNameLine, 0, 1);
    this->adminRemoveLayout->addWidget(this->adminRemoveBreedLabel, 1, 0);
    this->adminRemoveLayout->addWidget(this->adminRemoveBreedLine, 1, 1);
    this->adminRemoveLayout->addWidget(this->adminRemoveButton, 2, 0, 1, 2);

    // add the elements to the update layout
    this->adminUpdateLayout->addWidget(this->adminUpdateNameLabel, 0, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateNameLine, 0, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateBreedLabel, 1, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateBreedLine, 1, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateAgeLabel, 2, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdateAgeLine, 2, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdatePhotoLabel, 3, 0);
    this->adminUpdateLayout->addWidget(this->adminUpdatePhotoLine, 3, 1);
    this->adminUpdateLayout->addWidget(this->adminUpdateButton, 4, 0, 1, 2);

    // add the layout to the admin window
    this->adminWindow->setLayout(this->adminLayout);

    // style the admin form
    this->adminWindow->setWindowTitle("A89 - Denis916 - Admin");
    this->adminWindow->setFixedSize(450, 475);
    this->adminWindow->setWindowIcon(*this->icon);

    // ------------------ user ------------------

    // user layout
    this->userLayout = new QHBoxLayout();
    this->userOutputLayout = new QVBoxLayout();
    this->userInputLayout = new QVBoxLayout();
    this->userFilterLayout = new QGridLayout();
    this->userViewLayout = new QGridLayout();

    // user output elements
    this->userList = new QListWidget();
    this->userOutputLine = new QLineEdit();
    this->userOutputLine->setReadOnly(true);

    // user buttons
    this->userAdoptButton = new QPushButton("Adopt");
    this->userNextButton = new QPushButton("Next");
    this->userShowButton = new QPushButton("Show");
    this->userFilterButton = new QPushButton("Filter");
    this->userOpenButton = new QPushButton("Open");
    this->userBackButton = new QPushButton("Back");

    // user filter input fields
    this->userFilterBreedLine = new QLineEdit();
    this->userFilterAgeLine = new QLineEdit();
    // user filter labels
    this->userFilterBreedLabel = new QLabel("Breed");
    this->userFilterAgeLabel = new QLabel("Age");

    // user view output fields
    this->userViewNameLine = new QLineEdit();
    this->userViewNameLine->setReadOnly(true);
    this->userViewBreedLine = new QLineEdit();
    this->userViewBreedLine->setReadOnly(true);
    this->userViewAgeLine = new QLineEdit();
    this->userViewAgeLine->setReadOnly(true);
    // user view labels
    this->userViewNameLabel = new QLabel("Name");
    this->userViewBreedLabel = new QLabel("Breed");
    this->userViewAgeLabel = new QLabel("Age");

    this->userViewPhotoLabel = new QLabel();
    QPixmap dogPhotoMap("../resources/dogPhoto.png");
    this->userViewPhotoLabel->setPixmap(dogPhotoMap.scaled(200, 200, Qt::KeepAspectRatio));

    // add the elements to the user layout
    this->userLayout->addLayout(this->userOutputLayout);
    this->userLayout->addLayout(this->userInputLayout);
    this->userLayout->addLayout(this->userViewLayout);

    // add elements to the output layout
    this->userOutputLayout->addWidget(this->userList);
    this->userOutputLayout->addWidget(this->userOutputLine);

    // add elements to the input layout
    this->userInputLayout->addWidget(this->userNextButton);
    this->userInputLayout->addWidget(this->userAdoptButton);
    this->userInputLayout->addWidget(this->userShowButton);
    this->userInputLayout->addLayout(this->userFilterLayout);
    this->userInputLayout->addWidget(this->userOpenButton);
    this->userInputLayout->addWidget(this->userBackButton);

    // add elements to the filter layout
    this->userFilterLayout->addWidget(this->userFilterBreedLabel, 0, 0);
    this->userFilterLayout->addWidget(this->userFilterBreedLine, 0, 1);
    this->userFilterLayout->addWidget(this->userFilterAgeLabel, 1, 0);
    this->userFilterLayout->addWidget(this->userFilterAgeLine, 1, 1);
    this->userFilterLayout->addWidget(this->userFilterButton, 2, 0, 1, 2);

    // add elements to the view layout
    this->userViewLayout->addWidget(this->userViewPhotoLabel, 0, 0, 1, 2);
    this->userViewLayout->addWidget(this->userViewNameLabel, 1, 0);
    this->userViewLayout->addWidget(this->userViewNameLine, 1, 1);
    this->userViewLayout->addWidget(this->userViewBreedLabel, 2, 0);
    this->userViewLayout->addWidget(this->userViewBreedLine, 2, 1);
    this->userViewLayout->addWidget(this->userViewAgeLabel, 3, 0);
    this->userViewLayout->addWidget(this->userViewAgeLine, 3, 1);

    // add the layout to the user window
    this->userWindow->setLayout(this->userLayout);

    // style the user form
    this->userWindow->setWindowTitle("A89 - Denis916 - User");
    this->userWindow->setFixedSize(550, 300);
    this->userWindow->setWindowIcon(*this->icon);

    // ------------------ connections ------------------

    // form selection
    QObject::connect(this->ui->adminButton, &QPushButton::clicked, this, &QtUi::showAdminWindow);
    QObject::connect(this->ui->userCSVButton, &QPushButton::clicked, this, &QtUi::setCSVAdoptionList);
    QObject::connect(this->ui->userHTMLButton, &QPushButton::clicked, this, &QtUi::setHTMLAdoptionList);

    // admin commands
    QObject::connect(this->adminAddButton, &QPushButton::clicked, this, &QtUi::addPet);
    QObject::connect(this->adminRemoveButton, &QPushButton::clicked, this, &QtUi::removePet);
    QObject::connect(this->adminUpdateButton, &QPushButton::clicked, this, &QtUi::updatePet);
    QObject::connect(this->adminBackButton, &QPushButton::clicked, this, &QtUi::showModesWindow);

    // user commands
    QObject::connect(this->userNextButton, &QPushButton::clicked, this, &QtUi::userNext);
    QObject::connect(this->userAdoptButton, &QPushButton::clicked, this, &QtUi::userAdopt);
    QObject::connect(this->userShowButton, &QPushButton::clicked, this, &QtUi::updateUserList);
    QObject::connect(this->userFilterButton, &QPushButton::clicked, this, &QtUi::userFilter);
    QObject::connect(this->userOpenButton, &QPushButton::clicked, this, &QtUi::userOpen);
    QObject::connect(this->userBackButton, &QPushButton::clicked, this, &QtUi::showModesWindow);

    // ------------------ show ------------------

    this->showModesWindow();
}

QtUi::~QtUi() {
    delete ui;
}

void QtUi::showAdminWindow() {
    this->updateAdminList();
    this->adminOutputLine->clear();
    this->clearAdminInputFields();
    this->userWindow->setVisible(false);
    this->setVisible(false);
    this->adminWindow->setVisible(true);
}

void QtUi::updateAdminList() {
    this->adminList->clear();
    for (auto &pet : this->petService.getAll()) {
        this->adminList->addItem(QString::fromStdString(pet.toString()));
    }
}

void QtUi::clearAdminInputFields() {
    this->adminAddNameLine->clear();
    this->adminAddBreedLine->clear();
    this->adminAddAgeLine->clear();
    this->adminAddPhotoLine->clear();
    this->adminRemoveNameLine->clear();
    this->adminRemoveBreedLine->clear();
    this->adminUpdateNameLine->clear();
    this->adminUpdateBreedLine->clear();
    this->adminUpdateAgeLine->clear();
    this->adminUpdatePhotoLine->clear();
}

void QtUi::setCSVAdoptionList() {
    this->petService.modifyFileFormat("csv");
    this->showUserWindow();
    this->userOutputLine->setText("Adoption list format set to CSV");
}

void QtUi::setHTMLAdoptionList() {
    this->petService.modifyFileFormat("html");
    this->showUserWindow();
    this->userOutputLine->setText("Adoption list format set to HTML");
}

void QtUi::showUserWindow() {
    this->pets = this->petService.getAll();
    this->currentPetIndex = 0;

    this->updateUserList();
    this->userOutputLine->clear();
    this->clearUserInputFields();
    this->adminWindow->setVisible(false);
    this->setVisible(false);
    this->userWindow->setVisible(true);

    this->userNext();
}

void QtUi::updateUserList() {
    this->userList->clear();
    for (auto &pet: this->petService.getAdoptionList()) {
        this->userList->addItem(QString::fromStdString(pet.toString()));
    }
}

void QtUi::updateUserListFilter(const std::vector<Pet> &filteredPets) {
    this->userList->clear();
    for (auto &pet: filteredPets) {
        this->userList->addItem(QString::fromStdString(pet.toString()));
    }
}

void QtUi::clearUserInputFields() {
    this->userFilterBreedLine->clear();
    this->userFilterAgeLine->clear();
    this->userOutputLine->clear();
    this->userViewNameLine->clear();
    this->userViewBreedLine->clear();
    this->userViewAgeLine->clear();
}

void QtUi::showModesWindow() {
    this->adminWindow->setVisible(false);
    this->userWindow->setVisible(false);
    this->setVisible(true);
}

void QtUi::addPet() {
    try {
        char *name = new char[this->adminAddNameLine->text().toStdString().length() + 1];
        strcpy(name, this->adminAddNameLine->text().toStdString().c_str());
        char *breed = new char[this->adminAddBreedLine->text().toStdString().length() + 1];
        strcpy(breed, this->adminAddBreedLine->text().toStdString().c_str());
        int age = this->adminAddAgeLine->text().toInt();
        char *photo = new char[this->adminAddPhotoLine->text().toStdString().length() + 1];
        strcpy(photo, this->adminAddPhotoLine->text().toStdString().c_str());

        this->petService.addPet(name, breed, age, photo);
        this->updateAdminList();
        this->adminOutputLine->setText(QString::fromStdString("Pet added successfully!"));
    } catch (CustomException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }

    this->clearAdminInputFields();
}

void QtUi::removePet() {
    try {
        char *name = new char[this->adminRemoveNameLine->text().toStdString().length() + 1];
        strcpy(name, this->adminRemoveNameLine->text().toStdString().c_str());
        char *breed = new char[this->adminRemoveBreedLine->text().toStdString().length() + 1];
        strcpy(breed, this->adminRemoveBreedLine->text().toStdString().c_str());

        this->petService.removePet(name, breed);
        this->updateAdminList();
        this->adminOutputLine->setText(QString::fromStdString("Pet removed successfully!"));
    } catch (CustomException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }

    this->clearAdminInputFields();
}

void QtUi::updatePet() {
    try {
        char *name = new char[this->adminUpdateNameLine->text().toStdString().length() + 1];
        strcpy(name, this->adminUpdateNameLine->text().toStdString().c_str());
        char *breed = new char[this->adminUpdateBreedLine->text().toStdString().length() + 1];
        strcpy(breed, this->adminUpdateBreedLine->text().toStdString().c_str());
        int age = this->adminUpdateAgeLine->text().toInt();
        char *photo = new char[this->adminUpdatePhotoLine->text().toStdString().length() + 1];
        strcpy(photo, this->adminUpdatePhotoLine->text().toStdString().c_str());

        this->petService.updatePet(name, breed, age, photo);
        this->updateAdminList();
        this->adminOutputLine->setText(QString::fromStdString("Pet updated successfully!"));
    } catch (CustomException &exception) {
        this->adminOutputLine->setText(QString::fromStdString(exception.what()));
    }

    this->clearAdminInputFields();
}

void QtUi::userNext() {
    Pet pet = this->pets[this->currentPetIndex];

    this->userViewNameLine->setText(QString::fromStdString(pet.getName()));
    this->userViewBreedLine->setText(QString::fromStdString(pet.getBreed()));
    this->userViewAgeLine->setText(QString::fromStdString(to_string(pet.getAge())));

//    ShellExecuteA(nullptr, nullptr, "chrome.exe",
//                  pet.getPhoto().c_str(), nullptr, SW_SHOWNORMAL);

    this->currentPetIndex++;
    if (this->currentPetIndex == this->pets.size()) {
        this->currentPetIndex = 0;
    }
}

void QtUi::userAdopt() {
    try {
        Pet pet = this->pets[this->currentPetIndex];
        this->petService.addPetToAdoptionList(pet.getName(), pet.getBreed());
        this->updateUserList();
        this->userNext();
        this->userOutputLine->setText(QString::fromStdString("Pet adopted successfully!"));
    } catch (CustomException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::userFilter() {
    try {
        char *breed = new char[this->userFilterBreedLine->text().toStdString().length() + 1];
        strcpy(breed, this->userFilterBreedLine->text().toStdString().c_str());
        int age = this->userFilterAgeLine->text().toInt();

        vector<Pet> filteredPets;
        if (strlen(breed) == 0) {
            filteredPets = this->petService.filterByAge(age);
        } else {
            filteredPets = this->petService.filterByBreedAndAge(breed, age);
        }

        this->updateUserListFilter(filteredPets);
        if (filteredPets.empty()) {
            this->userOutputLine->setText(QString::fromStdString("No pets found!"));
        } else {
            this->userOutputLine->setText(QString::fromStdString("Pets filtered successfully!"));
        }
    } catch (CustomException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::userOpen() {
    this->updateUserList();

    if (this->petService.getAdoptionList().empty()) {
        this->userOutputLine->setText(QString::fromStdString("No pets selected!"));
        return;
    }

    try {
        this->petService.openAdoptionList();
        this->userOutputLine->setText(QString::fromStdString("Adoption list opened successfully!"));
    } catch (CustomException &exception) {
        this->userOutputLine->setText(QString::fromStdString(exception.what()));
    }
}

void QtUi::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    int petsUnder3YearsCount = 0;
    int petsOver3YearsCount = 0;
    for (auto &pet : this->petService.getAll()) {
        if (pet.getAge() < 3) {
            petsUnder3YearsCount++;
        } else {
            petsOver3YearsCount++;
        }
    }
    int petsUnder3YearsAngle = petsUnder3YearsCount * 360 / this->petService.getAll().size();
    int petsOver3YearsAngle = 360 - petsUnder3YearsAngle;

    QRectF size = QRectF(82, 50, this->width() - 160, this->width() - 160);

    painter.setBrush(Qt::red);
    painter.drawPie(size, 0, petsUnder3YearsAngle * 16);
    painter.setBrush(Qt::blue);
    painter.drawPie(size, petsUnder3YearsAngle * 16, petsOver3YearsAngle * 16);

    /// Draw legend
    painter.setBrush(Qt::red);
    painter.drawRect(10, 20, 20, 20);
    painter.setBrush(Qt::blue);
    painter.drawRect(10, 50, 20, 20);
    painter.setBrush(Qt::black);
    painter.drawText(40, 35, "Pets under 3 years");
    painter.drawText(40, 65, "Pets over 3 years");
}
