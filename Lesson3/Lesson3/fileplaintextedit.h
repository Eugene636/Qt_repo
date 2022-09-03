#ifndef FILEPLAINTEXTEDIT_H
#define FILEPLAINTEXTEDIT_H
#include <QDir>
#include <QTextCharFormat>
#include <QTextEdit>
class FilePlainTextEdit : public QTextEdit {
  Q_OBJECT

public:
  bool untitled_flag_;
  QDir directory_;
  QFileInfo file_;
  QTextCharFormat fmt_;
  FilePlainTextEdit(QWidget *parent = nullptr);
};

#endif // FILEPLAINTEXTEDIT_H
