cmake_minimum_required(VERSION 3.25)
project(qt-adoption-center)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(a89_Denis916
        main.cpp
        domain/file_adoption_list/CsvAdoptionList.cpp
        domain/file_adoption_list/CsvAdoptionList.h
        domain/file_adoption_list/FileAdoptionList.h
        domain/file_adoption_list/HtmlAdoptionList.cpp
        domain/file_adoption_list/HtmlAdoptionList.h
        domain/AdoptionList.cpp
        domain/AdoptionList.h
        domain/Pet.cpp
        domain/Pet.h
        extra/exceptions.h
        extra/Utilities.cpp
        extra/Utilities.h
        repository/file_repository/DataBaseRepository.cpp
        repository/file_repository/DataBaseRepository.h
        repository/file_repository/FileRepository.cpp
        repository/file_repository/FileRepository.h
        repository/file_repository/TxtRepository.cpp
        repository/file_repository/TxtRepository.h
        repository/Repository.cpp
        repository/Repository.h
        service/PetService.cpp
        service/PetService.h
        ui/Ui.cpp
        ui/Ui.h
        validators/PetValidator.cpp
        validators/PetValidator.h
        ui/qt_ui/qtui.cpp
        ui/qt_ui/qtui.h
        ui/qt_ui/qtui.ui)

target_link_libraries(a89_Denis916
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
