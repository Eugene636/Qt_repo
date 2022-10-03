#include "fileloader.h"
#include "organaizer.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Organaizer org;
  org.show();
  return app.exec();
}
