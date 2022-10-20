#include "mainwindow.h"
#include "form.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  accepted = false;
  Form f(this);
  connect(&f, &Form::trueSignal, this, &MainWindow::authorizationSlot);
  f.exec();
  ui->setupUi(this);
}

void MainWindow::authorizationSlot() {
  qDebug() << "authorization complete";
  accepted = true;
}
MainWindow::~MainWindow() { delete ui; }
