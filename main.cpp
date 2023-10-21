#include <QApplication>
#include "repository/file_repository/TxtRepository.h"
#include "domain/file_adoption_list/CsvAdoptionList.h"
#include "service/PetService.h"
#include "ui/qt_ui/qtui.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TxtRepository repository("../files/data.txt");
    repository.readFromFile();
    std::unique_ptr<CsvAdoptionList> adoptionList = nullptr;
    PetService petService(repository, adoptionList.get());
    QtUi ui(nullptr, petService);

    return QApplication::exec();
}
