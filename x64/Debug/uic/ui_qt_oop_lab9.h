/********************************************************************************
** Form generated from reading UI file 'qt_oop_lab9.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_OOP_LAB9_H
#define UI_QT_OOP_LAB9_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_oop_lab9Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_oop_lab9Class)
    {
        if (qt_oop_lab9Class->objectName().isEmpty())
            qt_oop_lab9Class->setObjectName(QString::fromUtf8("qt_oop_lab9Class"));
        qt_oop_lab9Class->resize(600, 400);
        menuBar = new QMenuBar(qt_oop_lab9Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        qt_oop_lab9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_oop_lab9Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qt_oop_lab9Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(qt_oop_lab9Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qt_oop_lab9Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qt_oop_lab9Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qt_oop_lab9Class->setStatusBar(statusBar);

        retranslateUi(qt_oop_lab9Class);

        QMetaObject::connectSlotsByName(qt_oop_lab9Class);
    } // setupUi

    void retranslateUi(QMainWindow *qt_oop_lab9Class)
    {
        qt_oop_lab9Class->setWindowTitle(QCoreApplication::translate("qt_oop_lab9Class", "qt_oop_lab9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qt_oop_lab9Class: public Ui_qt_oop_lab9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OOP_LAB9_H
