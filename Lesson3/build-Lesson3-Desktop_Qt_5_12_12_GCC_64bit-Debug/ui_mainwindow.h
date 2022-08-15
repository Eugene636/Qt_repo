/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *opened;
    QPushButton *open_button;
    QPushButton *save_button;
    QPushButton *help_button;
    QPushButton *en;
    QPushButton *ru;
    QPushButton *r_only_button;
    QPushButton *save_as_button;
    QPushButton *hot_keys_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        opened = new QPlainTextEdit(centralwidget);
        opened->setObjectName(QString::fromUtf8("opened"));
        opened->setGeometry(QRect(0, 30, 801, 521));
        open_button = new QPushButton(centralwidget);
        open_button->setObjectName(QString::fromUtf8("open_button"));
        open_button->setGeometry(QRect(0, 0, 91, 31));
        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));
        save_button->setGeometry(QRect(90, 0, 101, 31));
        help_button = new QPushButton(centralwidget);
        help_button->setObjectName(QString::fromUtf8("help_button"));
        help_button->setGeometry(QRect(270, 0, 91, 31));
        en = new QPushButton(centralwidget);
        en->setObjectName(QString::fromUtf8("en"));
        en->setGeometry(QRect(720, 0, 41, 31));
        ru = new QPushButton(centralwidget);
        ru->setObjectName(QString::fromUtf8("ru"));
        ru->setGeometry(QRect(760, 0, 41, 31));
        r_only_button = new QPushButton(centralwidget);
        r_only_button->setObjectName(QString::fromUtf8("r_only_button"));
        r_only_button->setGeometry(QRect(360, 0, 89, 31));
        save_as_button = new QPushButton(centralwidget);
        save_as_button->setObjectName(QString::fromUtf8("save_as_button"));
        save_as_button->setGeometry(QRect(190, 0, 89, 31));
        hot_keys_button = new QPushButton(centralwidget);
        hot_keys_button->setObjectName(QString::fromUtf8("hot_keys_button"));
        hot_keys_button->setGeometry(QRect(450, 0, 89, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        open_button->setText(QApplication::translate("MainWindow", "open", nullptr));
        save_button->setText(QApplication::translate("MainWindow", "save", nullptr));
        help_button->setText(QApplication::translate("MainWindow", "help", nullptr));
        en->setText(QApplication::translate("MainWindow", "en", nullptr));
        ru->setText(QApplication::translate("MainWindow", "ru", nullptr));
        r_only_button->setText(QApplication::translate("MainWindow", "read_open", nullptr));
        save_as_button->setText(QApplication::translate("MainWindow", "save as", nullptr));
        hot_keys_button->setText(QApplication::translate("MainWindow", "hot keys", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
