#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    QList<QStandardItem*> Headers;
    Headers.push_back(new QStandardItem("Num"));
    Headers.push_back(new QStandardItem("Unit name"));
    Headers.push_back(new QStandardItem("IP addr"));
    Headers.push_back(new QStandardItem("Mac addr"));
    model_.appendRow(Headers);
    Headers.clear();
    Headers.push_back(new QStandardItem("1"));
    Headers.push_back(new QStandardItem("Hugo@host"));
    Headers.push_back(new QStandardItem("192.168.0.2"));
    Headers.push_back(new QStandardItem("f0:76:1c:f1:49:39"));
    model_.appendRow(Headers);
    Headers.clear();
    Headers.push_back(new QStandardItem("2"));
    Headers.push_back(new QStandardItem("Hugo@host"));
    Headers.push_back(new QStandardItem("192.168.43.166"));
    Headers.push_back(new QStandardItem("4c:bb:58:c4:6e:ad"));
    model_.appendRow(Headers);
    ui_->compTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui_->compTableView->setModel(&model_);
    ui_->compTableView->setColumnWidth(0, 30);
    ui_->compTableView->setColumnWidth(1, 100);
    ui_->compTableView->setColumnWidth(2, 200);
    ui_->compTableView->setColumnWidth(3, 200);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::on_changeBack_b_clicked()
{
    auto selection_model = ui_->compTableView->selectionModel();
    if (selection_model->hasSelection())
    {
        QStandardItem* st;
        auto           list_indexes = selection_model->selectedIndexes();
        for (int i = 0; i < list_indexes.size(); i++)
        {
            if (list_indexes[i].isValid())
            {
                st = model_.itemFromIndex(list_indexes[i]);
                st->setData(QColor(Qt::red), Qt::BackgroundRole);
            }
        }
        selection_model->clearSelection();
        ui_->compTableView->setSelectionModel(selection_model);
    }
}
