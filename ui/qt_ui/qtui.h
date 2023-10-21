//
// Created by qdeni on 5/14/2023.
//

#ifndef A89_DENIS916_QTUI_H
#define A89_DENIS916_QTUI_H

#include <QWidget>
#include "../../service/PetService.h"
#include <qlayout.h>
#include <qline.h>
#include <QPainter>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qstackedlayout.h>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>


QT_BEGIN_NAMESPACE
namespace Ui { class QtUi; }
QT_END_NAMESPACE

class QtUi : public QWidget {
Q_OBJECT

public:
    explicit QtUi(QWidget *parent = nullptr, const PetService &petService = PetService());

    ~QtUi() override;

private:
    void showAdminWindow();

    void updateAdminList();

    void clearAdminInputFields();

    void setHTMLAdoptionList();

    void setCSVAdoptionList();

    void showUserWindow();

    void updateUserList();

    void updateUserListFilter(const std::vector<Pet> &filteredPets);

    void clearUserInputFields();

    void showModesWindow();

    void addPet();

    void removePet();

    void updatePet();

    void userNext();

    void userAdopt();

    void userFilter();

    void userOpen();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::QtUi *ui{};

private:
    PetService petService;
    std::vector<Pet> pets;
    int currentPetIndex;

    // the forms
    QWidget *adminWindow;
    QWidget *userWindow;
    QIcon *icon;

    // ------------------ admin ------------------

    // admin layout
    QHBoxLayout *adminLayout;
    QVBoxLayout *adminOutputLayout;
    QVBoxLayout *adminCommandsLayout;
    QGridLayout *adminAddLayout;
    QGridLayout *adminRemoveLayout;
    QGridLayout *adminUpdateLayout;

    // admin widget list
    QListWidget *adminList;
    // admin output text box for messages
    QLineEdit *adminOutputLine;

    // admin buttons
    QPushButton *adminAddButton;
    QPushButton *adminRemoveButton;
    QPushButton *adminUpdateButton;
    QPushButton *adminBackButton;

    // admin add input fields
    QLineEdit *adminAddNameLine;
    QLineEdit *adminAddBreedLine;
    QLineEdit *adminAddAgeLine;
    QLineEdit *adminAddPhotoLine;
    // admin add labels
    QLabel *adminAddNameLabel;
    QLabel *adminAddBreedLabel;
    QLabel *adminAddAgeLabel;
    QLabel *adminAddPhotoLabel;

    // admin remove input fields
    QLineEdit *adminRemoveNameLine;
    QLineEdit *adminRemoveBreedLine;
    // admin remove labels
    QLabel *adminRemoveNameLabel;
    QLabel *adminRemoveBreedLabel;

    // admin update input fields
    QLineEdit *adminUpdateNameLine;
    QLineEdit *adminUpdateBreedLine;
    QLineEdit *adminUpdateAgeLine;
    QLineEdit *adminUpdatePhotoLine;
    // admin update labels
    QLabel *adminUpdateNameLabel;
    QLabel *adminUpdateBreedLabel;
    QLabel *adminUpdateAgeLabel;
    QLabel *adminUpdatePhotoLabel;

    // ------------------ user ------------------

    // user layout
    QHBoxLayout *userLayout;
    QVBoxLayout *userOutputLayout;
    QVBoxLayout *userInputLayout;
    QGridLayout *userFilterLayout;
    QGridLayout *userViewLayout;

    // user widget list
    QListWidget *userList;
    // user output text box for messages
    QLineEdit *userOutputLine;

    // user buttons
    QPushButton *userNextButton;
    QPushButton *userAdoptButton;
    QPushButton *userShowButton;
    QPushButton *userFilterButton;
    QPushButton *userOpenButton;
    QPushButton *userBackButton;

    // user input fields
    QLineEdit *userFilterBreedLine;
    QLineEdit *userFilterAgeLine;
    // user labels
    QLabel *userFilterBreedLabel;
    QLabel *userFilterAgeLabel;

    // user view outputs fields
    QLineEdit *userViewNameLine;
    QLineEdit *userViewBreedLine;
    QLineEdit *userViewAgeLine;
    // user view labels
    QLabel *userViewNameLabel;
    QLabel *userViewBreedLabel;
    QLabel *userViewAgeLabel;
    QLabel *userViewPhotoLabel;
};


#endif //A89_DENIS916_QTUI_H
