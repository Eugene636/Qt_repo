#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*Основное меню. Содержит среди членов класса объекты диалоговых меню
 это сделано для сохранения результатов перевода */
#include "choosekeys.h"
#include "help.h"
#include "keys.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
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
private slots:
  void on_open_button_clicked();

  void on_save_button_clicked();

  void on_help_button_clicked();

  void onRussian();

  void onEnglish();

  void read_open();

  void save_as();

  void setHotKeys();

protected:
  virtual void keyPressEvent(QKeyEvent *event) override;

private:
  void exit();
  QString document_open();
  QString file_read(const QString &);
  void switchLanguage(const QString &);
  QErrorMessage *error_;
  QDir *directory_;
  QFileInfo *current_file_; // полезно для функции быстрого сохранения, например
  // QPushButton *eng_button_{};
  Ui::MainWindow *ui;
  Help d_;
  ChooseKeys choose_keys_;
};
#endif // MAINWINDOW_H
