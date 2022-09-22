#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <cmath>

constexpr int kSceneWidth = 800;
constexpr int kSceneHeight = 600;
constexpr int kRectWidth = 100;
constexpr int kRectHeight = 40;

class ItemEventFilter : public QGraphicsItem {
public:
  QRectF boundingRect() const override { return {}; }
  void paint(QPainter *, const QStyleOptionGraphicsItem *,
             QWidget * = 0) override {}
  QGraphicsItem *item_ = nullptr;

private:
  // bool move_flag = false;

protected:
  bool sceneEventFilter(QGraphicsItem *item, QEvent *event) override {
    static QPointF press_point;
    static QPointF release_point;
    static QPointF old_item_point;
    static QPointF new_item_point;
    static bool move_flag = false;
    static bool rotation_flag = false;
    // rotation

    if (event->type() == QEvent::GraphicsSceneMousePress) {
      auto mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
      if ((mouse_event->button() == Qt::LeftButton) && !move_flag) {
        move_flag = true;
        old_item_point = item->scenePos();
        qDebug() << old_item_point.x() << old_item_point.y();
        press_point = mouse_event->pos();
        return true;
      }
      if (mouse_event->button() == Qt::RightButton) {
        QGraphicsScene *pscene = item->scene();
        pscene->removeItem(item);
        delete item;
        return true;
      }
      if ((mouse_event->button() == Qt::MiddleButton) && !rotation_flag) {
        qDebug() << event->type();
        press_point = mouse_event->scenePos();
        rotation_flag = true;
        return true;
      }
    }
    if (event->type() == QEvent::GraphicsSceneMouseRelease) {
      auto mouse_event = static_cast<QGraphicsSceneMouseEvent *>(event);
      if ((mouse_event->button() == Qt::LeftButton) && move_flag) {
        release_point = mouse_event->pos();
        new_item_point.setX(old_item_point.x() + release_point.x() -
                            press_point.x());
        new_item_point.setY(old_item_point.y() + release_point.y() -
                            press_point.y());
        item->setPos(new_item_point);
        move_flag = !move_flag;
        return false;
      }
      if ((mouse_event->button() == Qt::MiddleButton) && rotation_flag) {
        qDebug() << event->type();
        release_point = mouse_event->scenePos();
        release_point.rx() -=
            press_point.x(); //теперь release_point хранятся уже дельты
        release_point.ry() -= press_point.y();
        item->setTransformOriginPoint(mapFromScene(press_point));
        if (release_point.x() > 0) {
          item->setRotation((180 / M_PI) *
                            std::atan(release_point.y() / release_point.x()));
        } else {
          item->setRotation(-(180 / M_PI) *
                            std::atan(release_point.y() / release_point.x()));
        }
        rotation_flag = false;
        return false;
      }
      if (mouse_event->button() == Qt::RightButton) {
        if (!move_flag) {
          item_ = item;
          return false;
        }
        if (move_flag) {
          item->setPos(mouse_event->scenePos());
          move_flag = false;
          return false;
        }
      }
    }
    return false;
  }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, ui_{new Ui::MainWindow},
      scene_{kSceneWidth / 2 - kSceneWidth, kSceneHeight / 2 - kSceneHeight,
             kSceneWidth, kSceneHeight} {
  ui_->setupUi(this);
  graphicsView_ = new MyGraphicsView(this);
  ui_->centralwidget->layout()->addWidget(graphicsView_);
  graphicsView_->setScene(&scene_);
  graphicsView_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphicsView_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphicsView_->setRenderHint(QPainter::Antialiasing);
  graphicsView_->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  graphicsView_->installEventFilter(this);
  // graphicsView_->verticalScrollBar()->blockSignals(true);
  // graphicsView_->horizontalScrollBar()->blockSignals(true);
  filter_ = new ItemEventFilter{};
  scene_.addItem(filter_);

  setWindowTitle("Crazy figures!");
  srand(clock());
}

MainWindow::~MainWindow() { delete ui_; }

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
  if (watched != graphicsView_) {
    return false;
  }
  if (event->type() == QEvent::KeyPress) {
    auto key_event = static_cast<QKeyEvent *>(event);
    if (key_event->key() == Qt::Key_Plus) {
      double rx = 1.1;
      double ry = 1.1;
      graphicsView_->scale(rx, ry);
      return false;
    }
    if (key_event->key() == Qt::Key_Minus) {
      double rx = 0.9;
      double ry = 0.9;
      graphicsView_->scale(rx, ry);
      return false;
    }
  }
  if (event->type() == QEvent::MouseButtonPress) {
    auto mouse_event = static_cast<QMouseEvent *>(event);
    if (mouse_event->button() == Qt::LeftButton) {
      /*auto rect = makeRect(mouse_event->x(), mouse_event->y());
      auto item = scene_.addEllipse(rect, QPen{Qt::NoPen}, Qt::red);
      item->installSceneEventFilter(filter_);*/
      static int figure_number = 1;
      switch (figure_number) {
      case 1: {
        auto item = scene_.addRect(
            makeRect(mouse_event->x(), mouse_event->y()), QPen{Qt::NoPen},
            QBrush(QColor(rand() % 256, rand() % 256, rand() % 256)));
        item->installSceneEventFilter(filter_);
      }
        ++figure_number;
        break;
      case 2: {
        auto item = scene_.addEllipse(
            makeRect(mouse_event->x(), mouse_event->y()), QPen{Qt::NoPen},
            QBrush(QColor(rand() % 256, rand() % 256, rand() % 256)));
        item->installSceneEventFilter(filter_);
      }
        ++figure_number;
        break;
      case 3: {
        auto item = scene_.addPolygon(
            makeStar(mouse_event->x(), mouse_event->y()), QPen{Qt::NoPen},
            QBrush(QColor(rand() % 256, rand() % 256, rand() % 256)));
        item->installSceneEventFilter(filter_);
      }
        figure_number = 1;
        break;
      }
    }
  }
  /*if (event->type() == QEvent::MouseButtonPress) {
    auto mouse_event = static_cast<QMouseEvent *>(event);
    if (mouse_event->button() == Qt::RightButton) {
      qDebug() << "Release right button";
      if (filter_->item_ == nullptr)
        return false;
      else
        filter_->item_->setPos(
            ui_->graphicsView->mapToScene(mouse_event->x(), mouse_event->y()));
      filter_->item_ = nullptr;
    }
  }*/

  return false;
}

QRectF MainWindow::makeRect(int x, int y) {
  auto top_left_point =
      graphicsView_->mapToScene(x - kRectWidth / 2, y - kRectHeight / 2);
  auto bottom_right_point =
      graphicsView_->mapToScene(x + kRectWidth / 2, y + kRectHeight / 2);
  return QRectF{top_left_point, bottom_right_point};
}
QPolygonF MainWindow::makeTriangle(int x, int y) {
  QVector<QPointF> points;
  QPointF top_left_point =
      graphicsView_->mapToScene(x - kRectWidth / 2, y - kRectHeight / 2);
  points.append(top_left_point);
  QPointF point =
      graphicsView_->mapToScene(x + kRectWidth / 2, y - kRectHeight / 2);
  points.append(point);
  QPointF bottom_right_point =
      graphicsView_->mapToScene(x + kRectWidth / 2, y + kRectHeight / 2);
  points.append(bottom_right_point);
  return QPolygonF(points);
}
QPolygonF MainWindow::makeStar(int x, int y) {
  QVector<QPointF> points;
  QPointF point;
  int stage = kRectWidth / 8;
  point = graphicsView_->mapToScene(x, y - 4 * stage);
  points.append(point);
  point = graphicsView_->mapToScene(x + stage, y - stage);
  points.append(point);
  point = graphicsView_->mapToScene(x + 4 * stage, y - stage);
  points.append(point);
  point = graphicsView_->mapToScene(x + 2 * stage, y + stage);
  points.append(point);
  point = graphicsView_->mapToScene(x + 3 * stage, y + 4 * stage);
  points.append(point);
  point = graphicsView_->mapToScene(x, y + 2 * stage);
  points.append(point);
  point = graphicsView_->mapToScene(x - 3 * stage, y + 4 * stage);
  points.append(point);
  point = graphicsView_->mapToScene(x - 2 * stage, y + stage);
  points.append(point);
  point = graphicsView_->mapToScene(x - 4 * stage, y - stage);
  points.append(point);
  point = graphicsView_->mapToScene(x - stage, y - stage);
  points.append(point);
  return QPolygonF(points);
}
