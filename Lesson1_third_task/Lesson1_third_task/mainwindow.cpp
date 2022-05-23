#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->append_b, &QPushButton::clicked, this,&MainWindow::append_b_clicked);
    connect (ui->insert_b, &QCommandLinkButton::clicked, this, &MainWindow::insert_b_clicked);
    connect (ui->insert_html_b, &QPushButton::clicked, this, &MainWindow::insert_html_b_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::append_b_clicked () {
    static int counter = 0;
    counter++;
    QString d = "append_b" + QString::number(counter);
    ui->debug->setText(d);
    QString s = ui->appending_t->toPlainText();
    QString s2 = ui->Inserting_t->toPlainText();
    s += s2;
    ui->appending_t->setText(s);
}

void MainWindow::insert_b_clicked () {
    static int counter = 0;
    counter++;
    QString d = "insert_b" + QString::number(counter);
    ui->debug->setText(d);
    ui->Inserting_t->setText(ui->appending_t->toPlainText());
}
void MainWindow::insert_html_b_clicked (){
    static int counter = 0;
    counter++;
    QString d = "htmp_b" + QString::number(counter);
    ui->debug->setText(d);
    ui->appending_t->setHtml("<fontcolor='red'>Hello</font> ");
}
