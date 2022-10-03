#ifndef TASKSSHOW_H
#define TASKSSHOW_H

#include <QDialog>
#include <QWidget>
class Ui_TasksShow;
class TasksShow : public QDialog {
  Q_OBJECT
public:
  explicit TasksShow(QWidget *parent = nullptr);
  ~TasksShow();

private:
  Ui_TasksShow *ui;
signals:
};

#endif // TASKSSHOW_H
