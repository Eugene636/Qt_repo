#include "tableview.h"
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
TableView::TableView(QWidget *parent) : QDialog(parent) {
  auto layout = new QVBoxLayout();
  table_ = new QTableView();
  setLayout(layout);
  layout->addWidget(table_);
  model_ = new QSqlTableModel(table_, QSqlDatabase::addDatabase("QSQLITE"));
  auto db = model_->database();
  db.setDatabaseName("Tasks.sqlite");
  if (!db.open()) {
    qDebug() << "Database not open";
    close();
  }
  table_->setModel(model_);
  model_->setTable("Tasks");
  model_->select();
}
inline void TableView::setView() {
  model_->setTable("Tasks");
  model_->select();
}
void TableView::renewDb() { setView(); }
