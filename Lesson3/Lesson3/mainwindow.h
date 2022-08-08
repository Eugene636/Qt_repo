#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class QErrorMessage;
class QDir;
class QFileInfo;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_open_button_clicked();

  void on_save_button_clicked();

  void on_help_button_clicked();

private:
  QErrorMessage *error_;
  QDir *directory_;
  QFileInfo *current_file_; // полезно для функции быстрого сохранения, например
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
