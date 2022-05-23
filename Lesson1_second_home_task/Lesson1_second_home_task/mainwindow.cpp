#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->calculate_b, &QPushButton::clicked, this, &MainWindow::on_calculate_b_clicked);
    ui->radians->setChecked(true);
    connect (ui->radians, &QRadioButton::toggled, this, &MainWindow::on_radians_toggled);
    setWindowTitle("Square equation resolving");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculate_b_clicked () {
    bool ok;
    QString condition;
    QString result;
    double a_len = (ui->a_length->text()).toDouble(&ok);
    if (!ok) {
        ui->Condition_l->setText("a length is not correct");
        ui->Result->setText("Result c = ");
        return;
    }
    double b_len = (ui->b_length->text()).toDouble(&ok);
    if (!ok) {
        ui->Condition_l->setText("b length is not correct");
        ui->Result->setText("Result c = ");
        return;
    }
    double corner_v = (ui->alpha_volume->text()).toDouble(&ok);
    if (!ok) {
        ui->Condition_l->setText("alpha value is not correct");
        ui->Result->setText("Result c = ");
        return;
    }
    corner_v = (ui->degrees->isChecked()) ? (corner_v*M_PI/180.0) : corner_v;
    if (corner_v >= M_PI) {
        ui->Condition_l->setText("alpha value is too big");
        ui->Result->setText("Result c = ");
        return;
    }
    double c2 = a_len*a_len + b_len*b_len - 2*a_len*b_len*qCos(corner_v);
    double c = qSqrt(c2);
    condition = ui->a_length->text() + "^2 + " + ui->b_length->text() + "^2 + "
             + ui->a_length->text() + "*" + ui->b_length->text() + "*Cos(" +  ui->alpha_volume->text() + ")";
    ui->Condition_l->setText(condition);
    result = "Result c = ";
    result += QString::number(c);
    ui->Result->setText(result);
    return;
}
void MainWindow::on_radians_toggled() {
    if (ui->radians->isChecked()) ui->corner_units->setText("alpha, rad");
    if (ui->degrees->isChecked()) ui->corner_units->setText("alpha, deg");
}
