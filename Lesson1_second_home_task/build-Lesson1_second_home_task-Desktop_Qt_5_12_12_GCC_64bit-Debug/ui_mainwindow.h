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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *corner_units;
    QLineEdit *a_length;
    QLineEdit *b_length;
    QLineEdit *alpha_volume;
    QRadioButton *radians;
    QRadioButton *degrees;
    QLabel *Result;
    QPushButton *calculate_b;
    QLabel *Condition_l;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 20, 67, 17));
        corner_units = new QLabel(centralwidget);
        corner_units->setObjectName(QString::fromUtf8("corner_units"));
        corner_units->setGeometry(QRect(320, 20, 111, 17));
        a_length = new QLineEdit(centralwidget);
        a_length->setObjectName(QString::fromUtf8("a_length"));
        a_length->setGeometry(QRect(20, 40, 113, 25));
        b_length = new QLineEdit(centralwidget);
        b_length->setObjectName(QString::fromUtf8("b_length"));
        b_length->setGeometry(QRect(170, 40, 113, 25));
        alpha_volume = new QLineEdit(centralwidget);
        alpha_volume->setObjectName(QString::fromUtf8("alpha_volume"));
        alpha_volume->setGeometry(QRect(320, 40, 113, 25));
        radians = new QRadioButton(centralwidget);
        radians->setObjectName(QString::fromUtf8("radians"));
        radians->setGeometry(QRect(30, 90, 112, 23));
        degrees = new QRadioButton(centralwidget);
        degrees->setObjectName(QString::fromUtf8("degrees"));
        degrees->setGeometry(QRect(190, 90, 112, 23));
        Result = new QLabel(centralwidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(450, 40, 231, 17));
        calculate_b = new QPushButton(centralwidget);
        calculate_b->setObjectName(QString::fromUtf8("calculate_b"));
        calculate_b->setGeometry(QRect(440, 120, 89, 25));
        Condition_l = new QLabel(centralwidget);
        Condition_l->setObjectName(QString::fromUtf8("Condition_l"));
        Condition_l->setGeometry(QRect(60, 160, 231, 17));
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
        label->setText(QApplication::translate("MainWindow", "a", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "b", nullptr));
        corner_units->setText(QString());
        radians->setText(QApplication::translate("MainWindow", "radian", nullptr));
        degrees->setText(QApplication::translate("MainWindow", "degrees", nullptr));
        Result->setText(QApplication::translate("MainWindow", "Result \321\201 = ", nullptr));
        calculate_b->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        Condition_l->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
