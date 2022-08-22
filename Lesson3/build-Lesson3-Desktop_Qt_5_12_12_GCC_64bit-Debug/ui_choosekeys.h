/********************************************************************************
** Form generated from reading UI file 'choosekeys.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEKEYS_H
#define UI_CHOOSEKEYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ChooseKeys
{
public:
    QRadioButton *save_as;
    QRadioButton *save;
    QRadioButton *open;
    QRadioButton *quit;
    QPlainTextEdit *save_as_keys;
    QPushButton *pushButton;
    QPlainTextEdit *save_keys;
    QPlainTextEdit *open_keys;
    QPlainTextEdit *quit_keys;

    void setupUi(QDialog *ChooseKeys)
    {
        if (ChooseKeys->objectName().isEmpty())
            ChooseKeys->setObjectName(QString::fromUtf8("ChooseKeys"));
        ChooseKeys->resize(400, 300);
        save_as = new QRadioButton(ChooseKeys);
        save_as->setObjectName(QString::fromUtf8("save_as"));
        save_as->setGeometry(QRect(10, 0, 112, 23));
        save = new QRadioButton(ChooseKeys);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(10, 60, 112, 23));
        open = new QRadioButton(ChooseKeys);
        open->setObjectName(QString::fromUtf8("open"));
        open->setGeometry(QRect(10, 130, 112, 23));
        quit = new QRadioButton(ChooseKeys);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(10, 190, 112, 23));
        save_as_keys = new QPlainTextEdit(ChooseKeys);
        save_as_keys->setObjectName(QString::fromUtf8("save_as_keys"));
        save_as_keys->setGeometry(QRect(140, 10, 181, 31));
        pushButton = new QPushButton(ChooseKeys);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 260, 191, 25));
        save_keys = new QPlainTextEdit(ChooseKeys);
        save_keys->setObjectName(QString::fromUtf8("save_keys"));
        save_keys->setGeometry(QRect(140, 60, 181, 31));
        open_keys = new QPlainTextEdit(ChooseKeys);
        open_keys->setObjectName(QString::fromUtf8("open_keys"));
        open_keys->setGeometry(QRect(140, 120, 181, 31));
        quit_keys = new QPlainTextEdit(ChooseKeys);
        quit_keys->setObjectName(QString::fromUtf8("quit_keys"));
        quit_keys->setGeometry(QRect(140, 180, 181, 31));

        retranslateUi(ChooseKeys);

        QMetaObject::connectSlotsByName(ChooseKeys);
    } // setupUi

    void retranslateUi(QDialog *ChooseKeys)
    {
        ChooseKeys->setWindowTitle(QApplication::translate("ChooseKeys", "Dialog", nullptr));
        save_as->setText(QApplication::translate("ChooseKeys", "save as", nullptr));
        save->setText(QApplication::translate("ChooseKeys", "save", nullptr));
        open->setText(QApplication::translate("ChooseKeys", "open", nullptr));
        quit->setText(QApplication::translate("ChooseKeys", "quit", nullptr));
        pushButton->setText(QApplication::translate("ChooseKeys", "save keys", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseKeys: public Ui_ChooseKeys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEKEYS_H
