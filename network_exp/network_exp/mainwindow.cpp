#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->search_button, &QPushButton::clicked, this,
          &MainWindow::goSearch);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::searchRequest(const QString &search_string) {
  QNetworkRequest request;

  QUrl url(search_string);
  request.setUrl(url);
  if (url.isValid())
    qDebug() << "url is valid";
  else
    return;
  preply_ = manager_.get(request);
  if (preply_)
    qDebug() << "preply_ is real";
  // QString filename = url.fileName();
  // pfile_ = new QFile(filename);
  // pfile_->open(QIODevice::WriteOnly);
  //  connect(preply_, &QIODevice::readyRead, this, &MainWindow::slotReadyRead);
  connect(preply_, &QNetworkReply::finished, this,
          &MainWindow::slotSearchUploadFinished);
  preply_->ignoreSslErrors();
}

void MainWindow::downloadRequest() {
  QUrl url = images_[downloaded_picture_];
  QNetworkRequest request;
  request.setUrl(url);
  if (url.isValid())
    qDebug() << "url is valid";
  else
    return;
  preply_ = manager_.get(request);
  if (preply_)
    qDebug() << "preply_ is real";
  QString filename = url.fileName();
  pfile_ = new QFile(filename);
  pfile_->open(QIODevice::WriteOnly);
  connect(preply_, &QIODevice::readyRead, this, &MainWindow::slotReadyRead);
  connect(preply_, &QNetworkReply::finished, this,
          &MainWindow::slotUploadFinished);
  preply_->ignoreSslErrors();
}

void MainWindow::slotReadyRead() {
  qDebug() << "ready read";
  if (pfile_) {
    qDebug() << "pfile_ is available";
    pfile_->write(preply_->readAll());
  }
}
void MainWindow::goSearch() {
  QString search_string = ui->search_string->toPlainText().trimmed();
  searchRequest(search_string);
}
void MainWindow::slotUploadFinished() {
  qDebug() << "Upload is finished";
  if (pfile_) {
    pfile_->close();
    delete preply_;
  }
  downloaded_picture_++;
  if (downloaded_picture_ == 3) {
    downloaded_picture_ = 0;
    imagesSetup();
    return;
  } else {
    downloadRequest();
  }
}

void MainWindow::slotSearchUploadFinished() {
  QTextStream txt(preply_);
  QString s;
  QStringList urls;
  QRegExp exp("\"img_href\":\"https://*\"");
  exp.setPatternSyntax(QRegExp::Wildcard);
  int pos;
  int images_count = 0;
  while (!txt.atEnd() && images_count < 3) {
    txt >> s;
    pos = s.indexOf(exp);
    if (pos != -1) {
      urls = s.split("\"img_href\":\"");
      for (int i = 1; i < urls.size(); i++) {
        QString url = urls[i];
        int end = url.indexOf('\"');
        url.truncate(end);
        images_[images_count] = QUrl(url);
        ++images_count;
        if (images_count == 3)
          break;
        qDebug() << url;
      }
    }
  }
  txt.flush();
  delete preply_;
  imagesDownloader();
}

void MainWindow::imagesDownloader() {
  downloaded_picture_ = 0;
  downloadRequest();
}
void MainWindow::imagesSetup() {
  QImage img(images_[0].fileName());
  QPixmap pixmap = QPixmap::fromImage(img);
  pixmap.setDevicePixelRatio(2);
  qDebug() << ui->horizontalLayoutWidget->geometry().width()
           << ui->horizontalLayoutWidget->geometry().height();
  QPixmap scale =
      pixmap.scaled(ui->horizontalLayoutWidget->geometry().width() * 2 / 3,
                    ui->horizontalLayoutWidget->geometry().height() * 2);
  ui->label->setPixmap(scale);
  img = QImage(images_[1].fileName());
  // ui->label->setFixedSize(img.size());
  pixmap = QPixmap::fromImage(img);
  pixmap.setDevicePixelRatio(2);
  qDebug() << ui->horizontalLayoutWidget->geometry().width()
           << ui->horizontalLayoutWidget->geometry().height();
  scale = pixmap.scaled(ui->horizontalLayoutWidget->geometry().width() * 2 / 3,
                        ui->horizontalLayoutWidget->geometry().height() * 2);
  ui->label_2->setPixmap(scale);
  img = QImage(images_[2].fileName());
  // ui->label->setFixedSize(img.size());
  pixmap = QPixmap::fromImage(img);
  pixmap.setDevicePixelRatio(2);
  qDebug() << ui->horizontalLayoutWidget->geometry().width()
           << ui->horizontalLayoutWidget->geometry().height();
  scale = pixmap.scaled(ui->horizontalLayoutWidget->geometry().width() * 2 / 3,
                        ui->horizontalLayoutWidget->geometry().height() * 2);
  ui->label_3->setPixmap(scale);
}
