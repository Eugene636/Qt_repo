#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <functional>
#include <unordered_map>

#include "mygraphicsview.h"
#include <QGraphicsScene>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ItemEventFilter;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override;
  bool eventFilter(QObject *watched, QEvent *event) override;

private:
  QRectF makeRect(int x, int y);
  QPolygonF makeTriangle(int x, int y);
  QPolygonF makeStar(int x, int y);
  ItemEventFilter *filter_{};
  Ui::MainWindow *ui_;
  QGraphicsScene scene_;
  MyGraphicsView *graphicsView_;
};
#endif // MAINWINDOW_H
