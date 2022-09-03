#include "mygraphicsview.h"
#include <QWheelEvent>

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent) {}
void MyGraphicsView::wheelEvent(QWheelEvent *event) {
  if (event->type() == QEvent::Wheel) {
    auto wheel_event = static_cast<QWheelEvent *>(event);
    double rx = wheel_event->angleDelta().y();
    rx = 1 + rx / 1200;
    double ry = rx;
    scale(rx, ry);
  }
}
