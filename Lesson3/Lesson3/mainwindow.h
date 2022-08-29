#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*Основное меню. Содержит среди членов класса объекты диалоговых меню
 это сделано для сохранения результатов перевода */
#include "choosekeys.h"
#include "fileplaintextedit.h"
#include "help.h"
#include "keys.h"
#include <QMainWindow>
#include <QTranslator>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class QMdiSubWindow;
class QErrorMessage;
class QDir;
class QFileInfo;
class QPushButton;
class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  Keys hot_keys_;

private:
  void on_open_button_clicked();

  void on_save_button_clicked();

  void on_help_button_clicked();

  void onRussian();

  void onEnglish();

  void read_open();

  void save_as();

  void setHotKeys();

  void nightButtonSlot();

protected:
  virtual void keyPressEvent(QKeyEvent *event) override;

private:
  void modified();
  QMdiSubWindow *new_window(const QString &name = "Untitled");
  void exit();
  QString document_open(bool read_only = false);
  QString file_read(const QString &);
  void switchLanguage(const QString &);
  QErrorMessage *error_;
  FilePlainTextEdit *window_widget();
  // QDir *directory_;
  // QFileInfo *current_file_; // полезно для функции быстрого сохранения,
  // например
  //  QPushButton *eng_button_{};
  Ui::MainWindow *ui;
  Help d_;
  ChooseKeys choose_keys_;
  QTranslator translator_;
  QList<QAction *> FileList;
  QList<QAction *> SettingsList;
  QList<QAction *> HelpList;
};
#endif // MAINWINDOW_H
