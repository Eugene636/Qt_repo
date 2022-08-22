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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *buttonLayout_2;
    QPushButton *save_button;
    QPushButton *en;
    QPushButton *open_button;
    QPushButton *help_button;
    QPushButton *hot_keys_button;
    QPushButton *r_only_button;
    QPushButton *ru;
    QPushButton *save_as_button;
    QPushButton *night_button;
    QPlainTextEdit *opened;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        buttonLayout_2 = new QGridLayout();
        buttonLayout_2->setObjectName(QString::fromUtf8("buttonLayout_2"));
        save_button = new QPushButton(centralwidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        buttonLayout_2->addWidget(save_button, 0, 9, 1, 1);

        en = new QPushButton(centralwidget);
        en->setObjectName(QString::fromUtf8("en"));

        buttonLayout_2->addWidget(en, 0, 7, 1, 1);

        open_button = new QPushButton(centralwidget);
        open_button->setObjectName(QString::fromUtf8("open_button"));

        buttonLayout_2->addWidget(open_button, 0, 10, 1, 1);

        help_button = new QPushButton(centralwidget);
        help_button->setObjectName(QString::fromUtf8("help_button"));

        buttonLayout_2->addWidget(help_button, 0, 8, 1, 1);

        hot_keys_button = new QPushButton(centralwidget);
        hot_keys_button->setObjectName(QString::fromUtf8("hot_keys_button"));

        buttonLayout_2->addWidget(hot_keys_button, 0, 3, 1, 1);

        r_only_button = new QPushButton(centralwidget);
        r_only_button->setObjectName(QString::fromUtf8("r_only_button"));

        buttonLayout_2->addWidget(r_only_button, 0, 5, 1, 1);

        ru = new QPushButton(centralwidget);
        ru->setObjectName(QString::fromUtf8("ru"));

        buttonLayout_2->addWidget(ru, 0, 6, 1, 1);

        save_as_button = new QPushButton(centralwidget);
        save_as_button->setObjectName(QString::fromUtf8("save_as_button"));

        buttonLayout_2->addWidget(save_as_button, 0, 4, 1, 1);

        night_button = new QPushButton(centralwidget);
        night_button->setObjectName(QString::fromUtf8("night_button"));

        buttonLayout_2->addWidget(night_button, 0, 11, 1, 1);


        verticalLayout->addLayout(buttonLayout_2);

        opened = new QPlainTextEdit(centralwidget);
        opened->setObjectName(QString::fromUtf8("opened"));

        verticalLayout->addWidget(opened);

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
        save_button->setText(QApplication::translate("MainWindow", "save", nullptr));
        en->setText(QApplication::translate("MainWindow", "en", nullptr));
        open_button->setText(QApplication::translate("MainWindow", "open", nullptr));
        help_button->setText(QApplication::translate("MainWindow", "help", nullptr));
        hot_keys_button->setText(QApplication::translate("MainWindow", "hotKeys", nullptr));
        r_only_button->setText(QApplication::translate("MainWindow", "readOpen", nullptr));
        ru->setText(QApplication::translate("MainWindow", "ru", nullptr));
        save_as_button->setText(QApplication::translate("MainWindow", "saveAs", nullptr));
        night_button->setText(QApplication::translate("MainWindow", "n/d", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
