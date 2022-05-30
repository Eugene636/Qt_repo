#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelectionModel>
#include <QList>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_changeBack_b_clicked();

private:
    Ui::MainWindow*    ui_;
    QStandardItemModel model_;
};
#endif // MAINWINDOW_H
