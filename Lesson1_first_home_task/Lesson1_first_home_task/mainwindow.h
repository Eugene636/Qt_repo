#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <optional>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_calculate_b_clicked ();
private:
    struct Roots{
        std::optional <double> x1;
        std::optional <double> x2;
    };
    Roots resolve (double a, double b, double c);
};
#endif // MAINWINDOW_H
