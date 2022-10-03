#include "organaizer.h"
#include "fileloader.h"
#include <QDebug>
#include <QQuickItem>
#include <QVBoxLayout>

Organaizer::Organaizer(QWidget *parent) : QWidget(parent) {
  qmlRegisterType<FileLoader>("com.fileloader", 1, 0, "FileLoader");
  organaizer_w_ = new QQuickWidget(QUrl("qrc:/main.qml"));
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(organaizer_w_);
  setLayout(layout);
  view_ = new TableView(this);
  view_->resize(300, 600);
  auto root = organaizer_w_->rootObject();
  if (root) {
    auto _view = root->findChild<QObject *>("tasksView");
    if (_view) {
      connect(_view, SIGNAL(viewSignal()), this, SLOT(onViewSignal()));
    }
  }
  if (root) {
    auto loader = root->findChild<FileLoader *>("loader");
    if (loader) {
      connect(loader, SIGNAL(dbRenew()), view_, SLOT(renewDb()));
    }
  }
}

void Organaizer::onViewSignal() {
  view_->setGeometry(0, 0, 600, 600);
  view_->show();
}

void Organaizer::closeEvent(QCloseEvent *event) {
  auto root = organaizer_w_->rootObject();
  if (root) {
    auto ldr = root->findChild<FileLoader *>("loader");
    auto name = root->findChild<QObject *>("task_name");
    auto deadline = root->findChild<QObject *>("deadline");
    auto task_abstract = root->findChild<QObject *>("task_abstract");
    if (ldr) {
      ldr->writeTask(name->property("text").toString(),
                     deadline->property("text").toString(),
                     task_abstract->property("text").toString());
    }
  }
  event->accept();
}
