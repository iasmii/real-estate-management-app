/********************************************************************************
** Form generated from reading UI file 'lab13_14.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB13_14_H
#define UI_LAB13_14_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab13_14Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab13_14Class)
    {
        if (lab13_14Class->objectName().isEmpty())
            lab13_14Class->setObjectName("lab13_14Class");
        lab13_14Class->resize(600, 400);
        menuBar = new QMenuBar(lab13_14Class);
        menuBar->setObjectName("menuBar");
        lab13_14Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab13_14Class);
        mainToolBar->setObjectName("mainToolBar");
        lab13_14Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(lab13_14Class);
        centralWidget->setObjectName("centralWidget");
        lab13_14Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lab13_14Class);
        statusBar->setObjectName("statusBar");
        lab13_14Class->setStatusBar(statusBar);

        retranslateUi(lab13_14Class);

        QMetaObject::connectSlotsByName(lab13_14Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab13_14Class)
    {
        lab13_14Class->setWindowTitle(QCoreApplication::translate("lab13_14Class", "lab13_14", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab13_14Class: public Ui_lab13_14Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB13_14_H
