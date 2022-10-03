#ifndef ORGANAIZER_H
#define ORGANAIZER_H

#include "tableview.h"
#include <QQuickWidget>
#include <QWidget>

class Organaizer : public QWidget {
  Q_OBJECT
public:
  QQuickWidget *organaizer_w_;
  TableView *view_;
  Organaizer(QWidget *parent = 0);
  void closeEvent(QCloseEvent *) override;
public slots:
  void onViewSignal();
};

#endif // ORGANAIZER_H
