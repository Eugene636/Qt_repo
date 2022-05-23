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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *appending_t;
    QTextEdit *Inserting_t;
    QLabel *label;
    QLabel *label_2;
    QPushButton *append_b;
    QPushButton *insert_html_b;
    QLabel *debug;
    QCommandLinkButton *insert_b;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        appending_t = new QTextEdit(centralwidget);
        appending_t->setObjectName(QString::fromUtf8("appending_t"));
        appending_t->setGeometry(QRect(70, 50, 181, 70));
        Inserting_t = new QTextEdit(centralwidget);
        Inserting_t->setObjectName(QString::fromUtf8("Inserting_t"));
        Inserting_t->setGeometry(QRect(400, 50, 211, 70));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 111, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 20, 67, 17));
        append_b = new QPushButton(centralwidget);
        append_b->setObjectName(QString::fromUtf8("append_b"));
        append_b->setGeometry(QRect(80, 160, 89, 25));
        insert_html_b = new QPushButton(centralwidget);
        insert_html_b->setObjectName(QString::fromUtf8("insert_html_b"));
        insert_html_b->setGeometry(QRect(238, 160, 101, 25));
        debug = new QLabel(centralwidget);
        debug->setObjectName(QString::fromUtf8("debug"));
        debug->setGeometry(QRect(80, 240, 451, 17));
        insert_b = new QCommandLinkButton(centralwidget);
        insert_b->setObjectName(QString::fromUtf8("insert_b"));
        insert_b->setGeometry(QRect(410, 150, 177, 41));
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
        label->setText(QApplication::translate("MainWindow", "appending", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Inserting", nullptr));
        append_b->setText(QApplication::translate("MainWindow", "append", nullptr));
        insert_html_b->setText(QApplication::translate("MainWindow", "Insert_html", nullptr));
        debug->setText(QString());
        insert_b->setText(QApplication::translate("MainWindow", "CommandLinkButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
