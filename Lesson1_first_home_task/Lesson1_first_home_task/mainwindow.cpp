#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtMath>
QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->calculate_b, &QPushButton::clicked, this, &MainWindow::on_calculate_b_clicked);
    setWindowTitle("Square equation resolving");
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::Roots MainWindow::resolve (double a, double b, double c){
    Roots roots;
    if (qFuzzyCompare(a, 0.0)) {
        if (!qFuzzyCompare(b, 0.0)) roots.x1 = (-c/b);// решаем как линейное уравнение
        return roots;
    }
    qreal D2 = b*b - 4*a*c;
    if (D2 < 0) return roots;//нет действительных корней
    if (qFuzzyCompare(D2, 0.0)) {
        roots.x1 = -b/(2*a);
        return roots;
    }
    qreal D = qSqrt(D2);
    roots.x1 = (-b - D)/(2*static_cast<double>(a));
    roots.x2 = (-b + D)/(2*static_cast<double>(a));
    return roots;
}

void MainWindow::on_calculate_b_clicked() {
    bool ok;
    int a, b, c;
    QString output_string;
    a = (ui->coef->text()).toDouble(&ok);
    if (ok == false) {
        output_string = "a coef is invalid";
        ui->result_l->setText("");
        ui->Equation->setText(output_string);
        return;
    }
    b = (ui->coef_2->text()).toDouble(&ok);
    if (ok == false) {
        output_string = "b coef is invalid";
        ui->result_l->setText("");
        ui->Equation->setText(output_string);
        return;
    }
    c = (ui->coef_3->text()).toDouble(&ok);
    if (ok == false) {
        output_string = "c coef is invalid";
        ui->result_l->setText("");
        ui->Equation->setText(output_string);
        return;
    }
    output_string = ui->coef->text() + "x^2+" + ui->coef_2->text() + "x+" + ui->coef_3->text() + "=0";
    Roots roots = resolve(a, b, c);
    if (roots.x1 == std::nullopt) {
        ui->result_l->setText("The equation has no roots");
    }
    else {
         if (roots.x2 == std::nullopt) {
            QString s = "X = " ;
            s += QString::number(*roots.x1);
            ui->result_l->setText(s);
         }
         else {
            QString s = "x1 = ";
            s += QString::number(*roots.x1);
            s += "; x2 = ";
            s += QString::number(*roots.x2);
            ui->result_l->setText(s);
        }
    }
    ui->Equation->setText(output_string);
}

