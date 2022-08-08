#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QErrorMessage>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  error_ = QErrorMessage::qtHandler();
  directory_ = new QDir;
  directory_->current();
  current_file_ = new QFileInfo;
}

MainWindow::~MainWindow() {

  delete ui;
  delete error_;
  delete directory_;
  delete current_file_;
}

void MainWindow::on_open_button_clicked() {

  QString s = QFileDialog::getOpenFileName(this, "Open text file",
                                           directory_->canonicalPath(),
                                           "text files (*.txt)");
  *current_file_ = QFileInfo(s);
  *directory_ = current_file_->dir();
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
    return;
  }
  QFile file(s);
  if (file.open(QIODevice::ReadOnly)) {
    QTextStream from_file(&file);
    ui->opened->setPlainText(from_file.readAll());
    file.close();
  } else {
    error_->showMessage("File can not be open");
    return;
  }
}

void MainWindow::on_save_button_clicked() {
  QString s = QFileDialog::getSaveFileName(this, "Save text file",
                                           directory_->canonicalPath(),
                                           "text files (*.txt)");
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
    return;
  }
  QFile file(s);
  if (file.open(QIODevice::WriteOnly)) {
    QTextStream in_file(&file);
    s = ui->opened->toPlainText();
    in_file << s;
    file.close();
  } else {
    error_->showMessage("File can not be open");
    return;
  }
}

void MainWindow::on_help_button_clicked() {
  QFile help_file(":/help/help.txt");
  QTextStream in_file(&help_file);
  help_file.open(QIODevice::ReadOnly);
  ui->opened->setPlainText(in_file.readAll());
  return;
}
