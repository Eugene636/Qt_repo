#ifndef FILEPLAINTEXTEDIT_H
#define FILEPLAINTEXTEDIT_H
#include <QDir>
#include <QPlainTextEdit>
class FilePlainTextEdit : public QPlainTextEdit {
  Q_OBJECT

public:
  bool untitled_flag_;
  QDir directory_;
  QFileInfo file_;
  FilePlainTextEdit(QWidget *parent = nullptr);
};

#endif // FILEPLAINTEXTEDIT_H
