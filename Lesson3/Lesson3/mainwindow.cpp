#include "mainwindow.h"
#include "fileplaintextedit.h"
#include "help.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>
#include <QErrorMessage>
#include <QFile>
#include <QFileInfo>
#include <QFontDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextStream>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), hot_keys_(), choose_keys_(&hot_keys_, this),
      d_(this), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  error_ = new QErrorMessage;
  d_.translate("en");
  QAction *paction;
  paction = ui->menuFile->addAction("New", [this]() { new_window(); });
  paction->setShortcut(QKeySequence("Ctrl+N"));
  FileList.push_back(paction);
  paction = ui->menuFile->addAction("File Open",
                                    [this]() { on_open_button_clicked(); });
  paction->setShortcut(QKeySequence("Ctrl+O"));
  FileList.push_back(paction);
  paction = ui->menuFile->addAction("File Save",
                                    [this]() { on_save_button_clicked(); });
  paction->setShortcut(QKeySequence("Ctrl+S"));
  FileList.push_back(paction);
  paction = ui->menuFile->addAction("Save As", [this]() { save_as(); });
  paction->setShortcut(QKeySequence("Ctrl+A"));
  FileList.push_back(paction);
  paction =
      ui->menuFile->addAction("Read Only Open", [this]() { read_open(); });
  paction->setShortcut(QKeySequence("Ctrl+R"));
  FileList.push_back(paction);
  paction = ui->menuSettings->addAction("Russian Language",
                                        [this]() { onRussian(); });
  paction->setShortcut(QKeySequence("Shift+R"));
  SettingsList.push_back(paction);
  paction = ui->menuSettings->addAction("English Language",
                                        [this]() { onEnglish(); });
  paction->setShortcut(QKeySequence("Shift+E"));
  SettingsList.push_back(paction);
  paction = ui->menuSettings->addAction("Theme switch",
                                        [this]() { nightButtonSlot(); });
  SettingsList.push_back(paction);
  paction =
      ui->menuHelp->addAction("Help", [this]() { on_help_button_clicked(); });
  paction->setShortcut(QKeySequence("Ctrl+H"));
  HelpList.push_back(paction);
  paction = ui->menuFile->addAction("Print", [this]() {
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted)
      return;
    window_widget()->print(&printer);
  });
  paction->setShortcut(QKeySequence("Ctrl + P"));
  FileList.push_back(paction);
  ui->menuTask1->addAction("Set random Format", this,
                           SLOT(random_size_of_font()));
  ui->menuTask1->addAction("Copy format", this, SLOT(copyFormat()));
  ui->menuTask1->addAction("Set copied format", this, SLOT(setCopiedFormat()));
  QMenu *menu = new QMenu("Alignment", this);
  menu->addAction("Alignment left", this, SLOT(alignmentLeft()));
  menu->addAction("Alignment right", this, SLOT(alignmentRight()));
  menu->addAction("Alignment center", this, SLOT(alignmentCenter()));
  ui->menuTask1->addMenu(menu);
  ui->menuTask1->addAction("Set Font", this, SLOT(setFont()));
  ui->centralwidget->setFocusPolicy(Qt::StrongFocus);
  ui->work_area->setViewMode(QMdiArea::TabbedView);
  ui->work_area->setDocumentMode(true);
  srand(clock());
}
MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_open_button_clicked() {
  QString s = document_open();
  if (s.isEmpty())
    return;
}

void MainWindow::on_save_button_clicked() {
  QMdiSubWindow *subwindow = ui->work_area->activeSubWindow();
  FilePlainTextEdit *pwidget =
      qobject_cast<FilePlainTextEdit *>(subwindow->widget());
  QString s = pwidget->file_.absoluteFilePath();
  if (s.isEmpty()) {
    save_as();
    return;
  }
  QFile file(s);
  if (file.open(QIODevice::WriteOnly)) {
    QTextStream in_file(&file);
    s = pwidget->toPlainText();
    in_file << s;
    file.close();
  } else {
    error_->showMessage("File can not be open");
  }
  subwindow->setWindowModified(false);
  pwidget->blockSignals(false);
}

void MainWindow::switchLanguage(const QString &language) {
  translator_.load("Qt_Language_" + language);
  qApp->installTranslator(&translator_);
  ui->retranslateUi(this);
  d_.translate(language);
  choose_keys_.translate(language);
  FileList[0]->setText(tr("New"));
  FileList[1]->setText(tr("File Open"));
  FileList[2]->setText(tr("File Save"));
  FileList[3]->setText(tr("Save As"));
  FileList[4]->setText(tr("Read Only Open"));
  FileList[5]->setText(tr("Print"));
  SettingsList[2]->setText(tr("Theme switch"));
  HelpList[0]->setText(tr("See Help"));
}

void MainWindow::on_help_button_clicked() {
  QFile help_file(":/help/help.txt");
  QTextStream in_file(&help_file);
  help_file.open(QIODevice::ReadOnly);
  d_.setHelpText(in_file.readAll());
  d_.exec();
  return;
}
QString MainWindow::document_open(bool read_only) {
  QDir directory = QDir::current();
  QString s = QFileDialog::getOpenFileName(
      this, "Open text file", directory.canonicalPath(), "text files (*.txt)");
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
    return "";
  }
  QFileInfo file = QFileInfo(s);
  QMdiSubWindow *subwindow = new_window(file.fileName());
  FilePlainTextEdit *pwidget =
      qobject_cast<FilePlainTextEdit *>(subwindow->widget());
  pwidget->file_ = file;
  pwidget->directory_ = pwidget->file_.dir();
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
  }
  pwidget->setReadOnly(read_only);
  pwidget->setPlainText(file_read(s));
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
  QMdiSubWindow *subwindow = ui->work_area->activeSubWindow();
  FilePlainTextEdit *pwidget =
      qobject_cast<FilePlainTextEdit *>(subwindow->widget());
  QString s = QFileDialog::getSaveFileName(this, "Save text file",
                                           pwidget->directory_.canonicalPath(),
                                           "text files (*.txt)");
  if (s.isEmpty()) {
    error_->showMessage("File name is not choosed");
    return;
  }
  QFileInfo fil(s);
  pwidget->file_ = fil;
  pwidget->directory_ = fil.absoluteDir();
  subwindow->setWindowTitle(fil.fileName() + "[*]");
  QFile file(s);
  if (file.open(QIODevice::WriteOnly)) {
    QTextStream in_file(&file);
    s = pwidget->toPlainText();
    in_file << s;
    file.close();
  } else {
    error_->showMessage("File can not be open");
    return;
  }
  subwindow->setWindowModified(false);
  pwidget->blockSignals(false);
}
void MainWindow::read_open() {
  QString s = document_open(true);
  if (s.isEmpty())
    return;
}
void MainWindow::exit() { this->close(); }

void MainWindow::keyPressEvent(
    QKeyEvent *event) { //убрал функционал, связанный со сменой горячих клавиш.
  /* if ((event->modifiers() == hot_keys_.getCodeKeyCreate().key_modifier) &&
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
     exit();*/
}
void MainWindow::setHotKeys() {
  choose_keys_.open();
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

FilePlainTextEdit *MainWindow::window_widget() {
  QMdiSubWindow *pwindow = ui->work_area->activeSubWindow();
  return qobject_cast<FilePlainTextEdit *>(pwindow->widget());
}
QMdiSubWindow *MainWindow::new_window(const QString &name) {
  QMdiSubWindow *subwindow = new QMdiSubWindow;
  subwindow->setAttribute(Qt::WA_DeleteOnClose);
  FilePlainTextEdit *text = new FilePlainTextEdit;
  if (name == "Untitled") {
    int i = 0;
    for (auto w : ui->work_area->subWindowList()) {
      if (qobject_cast<FilePlainTextEdit *>(w->widget())->untitled_flag_)
        i++;
    }
    if (i)
      subwindow->setWindowTitle(name + '(' + QString::number(i) + ')' + "[*]");
    else
      subwindow->setWindowTitle(name + "[*]");
  } else {
    subwindow->setWindowTitle(name + "[*]");
    text->untitled_flag_ = false;
  }
  text->blockSignals(true);
  auto mod = [subwindow, text]() {
    subwindow->setWindowModified(true);
    text->blockSignals(true);
  };
  connect(text, &FilePlainTextEdit::textChanged, subwindow, mod);
  subwindow->setWidget(text);
  ui->work_area->addSubWindow(subwindow);
  subwindow->show();
  text->blockSignals(false);
  return subwindow;
}

void MainWindow::random_size_of_font() {
  FilePlainTextEdit *text = window_widget();
  // фрагмента текста
  text->fmt_.setForeground(
      QBrush(QColor(rand() % 256, rand() % 256, rand() % 256)));
  // Цвет символа
  // (setForeground(QBrush))
  text->fmt_.setBackground(
      QBrush(QColor(rand() % 256, rand() % 256, rand() % 256)));
  text->textCursor().setCharFormat(text->fmt_); // Задаем формат в
}
void MainWindow::copyFormat() {
  FilePlainTextEdit *text = window_widget();
  text->fmt_ = text->textCursor().charFormat();
}
void MainWindow::setCopiedFormat() {
  FilePlainTextEdit *text = window_widget();
  text->textCursor().setCharFormat(text->fmt_);
}

void MainWindow::alignmentLeft() {
  FilePlainTextEdit *text = window_widget();
  if (!text)
    return;
  QTextBlockFormat bfmt;
  bfmt.setAlignment(Qt::AlignLeft);
  text->textCursor().setBlockFormat(bfmt);
}

void MainWindow::alignmentRight() {
  FilePlainTextEdit *text = window_widget();
  if (!text)
    return;
  QTextBlockFormat bfmt;
  bfmt.setAlignment(Qt::AlignRight);
  text->textCursor().setBlockFormat(bfmt);
}
void MainWindow::alignmentCenter() {
  FilePlainTextEdit *text = window_widget();
  if (!text)
    return;
  QTextBlockFormat bfmt;
  bfmt.setAlignment(Qt::AlignHCenter);
  text->textCursor().setBlockFormat(bfmt);
}
void MainWindow::setFont() {
  FilePlainTextEdit *text = window_widget();
  if (!text)
    return;
  bool ok;
  QFont font = QFontDialog::getFont(&ok, text);
  text->setFont(font);
}
