#include "fileplaintextedit.h"

FilePlainTextEdit::FilePlainTextEdit(QWidget *parent) : QPlainTextEdit(parent) {
  directory_ = QDir::current();
  untitled_flag_ = true;
}
