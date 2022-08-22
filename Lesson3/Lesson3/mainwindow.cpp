#include "mainwindow.h"
#include "help.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QErrorMessage>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), hot_keys_(), choose_keys_(&hot_keys_, this),
      d_(this), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  error_ = new QErrorMessage;
  directory_ = new QDir;
  directory_->current();
  current_file_ = new QFileInfo;
  connect(ui->ru, &QPushButton::clicked, this, &MainWindow::onRussian);
  connect(ui->en, &QPushButton::clicked, this, &MainWindow::onEnglish);
  connect(ui->r_only_button, &QPushButton::clicked, this,
          &MainWindow::read_open);
  connect(ui->save_as_button, &QPushButton::clicked, this,
          &MainWindow::save_as);
  connect(ui->hot_keys_button, &QPushButton::clicked, this,
          &MainWindow::setHotKeys);
  connect(ui->night_button, &QPushButton::clicked, this,
          &MainWindow::nightButtonSlot);
  this->switchLanguage("en");
  choose_keys_.translate("en");
  d_.translate("en");
  ui->centralwidget->setFocusPolicy(Qt::StrongFocus);
}
MainWindow::~MainWindow() {

  delete ui;
  // delete error_;
  delete directory_;
  delete current_file_;
}

void MainWindow::on_open_button_clicked() {
  QString s = document_open();
  if (s.isEmpty())
    return;
  if (ui->opened->isReadOnly())
    ui->opened->setReadOnly(false);
  ui->opened->setPlainText(file_read(s));
}

void MainWindow::on_save_button_clicked() {
  QString s = current_file_->absoluteFilePath();
  if (s.isEmpty()) {
    save_as();
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
  }
}

void MainWindow::switchLanguage(const QString &language) {
  QTranslator translator;
  translator.load("Qt_Language_" + language);
  qApp->installTranslator(&translator);
  ui->retranslateUi(this);
  d_.translate(language);
  choose_keys_.translate(language);
}

void MainWindow::on_help_button_clicked() {
  QFile help_file(":/help/help.txt");
  QTextStream in_file(&help_file);
  help_file.open(QIODevice::ReadOnly);
  d_.setHelpText(in_file.readAll());
  d_.exec();
  return;
}
QString MainWindow::document_open() {
  QString s = QFileDialog::getOpenFileName(this, "Open text file",
                                           directory_->canonicalPath(),
                                           "text files (*.txt)");
  *current_file_ = QFileInfo(s);
  *directory_ = current_file_->dir();
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
  }
  return s;
}
void MainWindow::onRussian() { switchLanguage("ru"); }

void MainWindow::onEnglish() { switchLanguage("en"); }

QString MainWindow::file_read(const QString &s) {
  QFile file(s);
  if (file.open(QIODevice::ReadOnly)) {
    QTextStream from_file(&file);
    // ui->opened->setPlainText(from_file.readAll());
    QString file_text = from_file.readAll();
    file.close();
    return file_text;
  } else {
    error_->showMessage("File can not be open");
    return "";
  }
}
void MainWindow::save_as() {
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
void MainWindow::read_open() {
  QString s = document_open();
  if (s.isEmpty())
    return;
  if (ui->opened->isReadOnly())
    ui->opened->setReadOnly(false);
  ui->opened->setPlainText(file_read(s));
  ui->opened->setReadOnly(true);
}
void MainWindow::exit() { this->close(); }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if ((event->modifiers() == hot_keys_.getCodeKeyCreate().key_modifier) &&
      (event->key() == hot_keys_.getCodeKeyCreate().key_code))
    save_as();
  if ((event->modifiers() == hot_keys_.getCodeKeyOpen().key_modifier) &&
      (event->key() == hot_keys_.getCodeKeyOpen().key_code))
    on_open_button_clicked();
  if ((event->modifiers() == hot_keys_.getCodeKeySave().key_modifier) &&
      (event->key() == hot_keys_.getCodeKeySave().key_code))
    on_save_button_clicked();
  if ((event->modifiers() == hot_keys_.getCodeKeyExit().key_modifier) &&
      (event->key() == hot_keys_.getCodeKeyExit().key_code))
    exit();
}
void MainWindow::setHotKeys() {
  choose_keys_.exec();
  hot_keys_.writeKeysToFile();
}

void MainWindow::nightButtonSlot() {
  static bool flag = true;
  if (flag) {
    qApp->setStyleSheet(
        "QWidget {background-color: black; color: white} QPushButton "
        "{background-color: brown; color: black} "
        "QPushButton:hover {background-color: black; color: white} "
        "QPlainTextEdit {background-color: black; color: yellow}");
  } else
    qApp->setStyleSheet("");
  flag = !flag;
}
