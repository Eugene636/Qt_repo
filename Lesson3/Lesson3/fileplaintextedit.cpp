#include "fileplaintextedit.h"

FilePlainTextEdit::FilePlainTextEdit(QWidget *parent) : QTextEdit(parent) {
  directory_ = QDir::current();
  untitled_flag_ = true;
}
