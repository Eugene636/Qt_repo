#ifndef TABLEVIEW_H
#define TABLEVIEW_H
#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
class TableView : public QDialog {
  Q_OBJECT
public:
  TableView(QWidget *parent = 0);
  QSqlTableModel *model_;
  QTableView *table_;

private:
  inline void setView();
public slots:
  void renewDb();
};

#endif // TABLEVIEW_H
