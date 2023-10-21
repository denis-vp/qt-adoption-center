/********************************************************************************
** Form generated from reading UI file 'qtui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTUI_H
#define UI_QTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtUi
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *modesLayout;
    QPushButton *adminButton;
    QPushButton *userCSVButton;
    QPushButton *userHTMLButton;

    void setupUi(QWidget *QtUi)
    {
        if (QtUi->objectName().isEmpty())
            QtUi->setObjectName("QtUi");
        QtUi->resize(475, 475);
        QtUi->setMinimumSize(QSize(475, 475));
        QtUi->setMaximumSize(QSize(475, 475));
        verticalLayoutWidget = new QWidget(QtUi);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-10, 390, 491, 86));
        modesLayout = new QVBoxLayout(verticalLayoutWidget);
        modesLayout->setObjectName("modesLayout");
        modesLayout->setContentsMargins(0, 0, 0, 0);
        adminButton = new QPushButton(verticalLayoutWidget);
        adminButton->setObjectName("adminButton");

        modesLayout->addWidget(adminButton);

        userCSVButton = new QPushButton(verticalLayoutWidget);
        userCSVButton->setObjectName("userCSVButton");

        modesLayout->addWidget(userCSVButton);

        userHTMLButton = new QPushButton(verticalLayoutWidget);
        userHTMLButton->setObjectName("userHTMLButton");

        modesLayout->addWidget(userHTMLButton);


        retranslateUi(QtUi);

        QMetaObject::connectSlotsByName(QtUi);
    } // setupUi

    void retranslateUi(QWidget *QtUi)
    {
        QtUi->setWindowTitle(QCoreApplication::translate("QtUi", "A89 - Denis916 - Modes", nullptr));
        adminButton->setText(QCoreApplication::translate("QtUi", "Admin Mode", nullptr));
        userCSVButton->setText(QCoreApplication::translate("QtUi", "User CSV Mode", nullptr));
        userHTMLButton->setText(QCoreApplication::translate("QtUi", "User HTML Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtUi: public Ui_QtUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTUI_H
