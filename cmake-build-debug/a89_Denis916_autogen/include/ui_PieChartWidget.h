/********************************************************************************
** Form generated from reading UI file 'piechartwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIECHARTWIDGET_H
#define UI_PIECHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PieChartWidget
{
public:

    void setupUi(QWidget *PieChartWidget)
    {
        if (PieChartWidget->objectName().isEmpty())
            PieChartWidget->setObjectName("PieChartWidget");
        PieChartWidget->resize(400, 300);

        retranslateUi(PieChartWidget);

        QMetaObject::connectSlotsByName(PieChartWidget);
    } // setupUi

    void retranslateUi(QWidget *PieChartWidget)
    {
        PieChartWidget->setWindowTitle(QCoreApplication::translate("PieChartWidget", "PieChartWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PieChartWidget: public Ui_PieChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIECHARTWIDGET_H
