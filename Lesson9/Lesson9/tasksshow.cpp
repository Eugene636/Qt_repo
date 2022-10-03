#include "tasksshow.h"
#include "ui_TasksShow.h"
TasksShow::TasksShow(QWidget *parent) : QDialog(parent) { ui->setupUi(this); }

TasksShow::~TasksShow() { delete ui; }
