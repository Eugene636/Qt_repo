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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *coef;
    QLineEdit *coef_2;
    QLineEdit *coef_3;
    QPushButton *calculate_b;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *result_l;
    QLabel *Equation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        coef = new QLineEdit(centralwidget);
        coef->setObjectName(QString::fromUtf8("coef"));
        coef->setGeometry(QRect(30, 60, 113, 25));
        coef_2 = new QLineEdit(centralwidget);
        coef_2->setObjectName(QString::fromUtf8("coef_2"));
        coef_2->setGeometry(QRect(250, 60, 113, 25));
        coef_3 = new QLineEdit(centralwidget);
        coef_3->setObjectName(QString::fromUtf8("coef_3"));
        coef_3->setGeometry(QRect(440, 60, 113, 25));
        calculate_b = new QPushButton(centralwidget);
        calculate_b->setObjectName(QString::fromUtf8("calculate_b"));
        calculate_b->setGeometry(QRect(408, 150, 181, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 21, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 30, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 30, 67, 17));
        result_l = new QLabel(centralwidget);
        result_l->setObjectName(QString::fromUtf8("result_l"));
        result_l->setGeometry(QRect(60, 200, 351, 20));
        Equation = new QLabel(centralwidget);
        Equation->setObjectName(QString::fromUtf8("Equation"));
        Equation->setGeometry(QRect(60, 140, 151, 17));
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
        calculate_b->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\262\320\265\321\201\321\202\320\270 \320\270 \321\200\320\265\321\210\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "a", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "b", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "c", nullptr));
        result_l->setText(QString());
        Equation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
