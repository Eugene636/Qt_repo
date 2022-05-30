#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelectionModel>
#include <QListView>
#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void onRemoveButton();
  void onAddButton();

  void on_IconView_stateChanged(int arg1);

  void on_up_b_clicked();

  void on_down_b_clicked();

  void on_lang_edit_b_clicked();

private:
  Ui::MainWindow *ui_;
  QStandardItemModel model_;
};
#endif // MAINWINDOW_H
