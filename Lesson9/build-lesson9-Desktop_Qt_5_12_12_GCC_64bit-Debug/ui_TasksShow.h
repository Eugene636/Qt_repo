/********************************************************************************
** Form generated from reading UI file 'TasksShow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSSHOW_H
#define UI_TASKSSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_TasksShow
{
public:

    void setupUi(QDialog *TasksShow)
    {
        if (TasksShow->objectName().isEmpty())
            TasksShow->setObjectName(QString::fromUtf8("TasksShow"));
        TasksShow->resize(400, 300);

        retranslateUi(TasksShow);

        QMetaObject::connectSlotsByName(TasksShow);
    } // setupUi

    void retranslateUi(QDialog *TasksShow)
    {
        TasksShow->setWindowTitle(QApplication::translate("TasksShow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TasksShow: public Ui_TasksShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSSHOW_H
