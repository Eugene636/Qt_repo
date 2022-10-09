#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void searchRequest(const QString &);
  void downloadRequest();

private:
  void imagesDownloader();
  Ui::MainWindow *ui;
  QNetworkAccessManager manager_;
  QNetworkReply *preply_;
  QNetworkRequest *prequest_;
  QPointer<QFile> pfile_;
  QUrl images_[3];
  int downloaded_picture_;
  void imagesSetup();
public slots:
  void slotReadyRead();
  void goSearch();
  void slotUploadFinished();
  void slotSearchUploadFinished();
};
#endif // MAINWINDOW_H
