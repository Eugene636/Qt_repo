#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView {
  Q_OBJECT
public:
  MyGraphicsView(QWidget *parent);

protected:
  virtual void wheelEvent(QWheelEvent *event) override;
};

#endif // MYGRAPHICSVIEW_H
