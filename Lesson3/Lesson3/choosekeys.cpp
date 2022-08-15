#include "choosekeys.h"
#include "ui_choosekeys.h"
#include <QDebug>

ChooseKeys::ChooseKeys(Keys *hot_keys, QWidget *parent)
    : QDialog(parent), ui(new Ui::ChooseKeys), hot_keys_(hot_keys) {
  ui->setupUi(this);
  keysForUser();
}

ChooseKeys::~ChooseKeys() { delete ui; }
void ChooseKeys::keysForUser() {
  keysToTextField(hot_keys_->getCodeKeySave(), ui->save_keys);
  keysToTextField(hot_keys_->getCodeKeyOpen(), ui->open_keys);
  keysToTextField(hot_keys_->getCodeKeyCreate(), ui->save_as_keys);
  keysToTextField(hot_keys_->getCodeKeyExit(), ui->quit_keys);
}

void ChooseKeys::keysToTextField(const KeyShortcut &keys,
                                 QPlainTextEdit *field) {
  QString s;
  switch (keys.key_modifier) {
  case Qt::ControlModifier:
    s += "Cntr+";
    break;
  case Qt::ShiftModifier:
    s += "Shift+";
    break;
  case Qt::AltModifier:
    s += "Alt+";
    break;
  case Qt::NoModifier:
    break;
  }
  int code = keys.key_code;
  if (((code >= Qt::Key_A) && (code <= Qt::Key_Z)) ||
      ((code >= Qt::Key_0) && (code <= Qt::Key_9))) {
    s += static_cast<char>(code);
  }
  if ((code >= Qt::Key_F1) && (code <= Qt::Key_F35)) {
    s += "F" + QString::number(code + 1 - Qt::Key_F1);
  }
  field->setPlainText(s);
}
KeyShortcut ChooseKeys::change_keys(QKeyEvent *event) {
  KeyShortcut keys;
  if ((event->key() == Qt::Key_Control) || (event->key() == Qt::Key_Shift) ||
      (event->key() == Qt::Key_Alt))
    return keys;
  if (event->modifiers() == Qt::ControlModifier)
    keys.key_modifier = Qt::ControlModifier;
  if (event->modifiers() == Qt::ShiftModifier)
    keys.key_modifier = Qt::ShiftModifier;
  if (event->modifiers() == Qt::AltModifier)
    keys.key_modifier = Qt::AltModifier;
  if (event->modifiers() == Qt::NoModifier)
    keys.key_modifier = Qt::NoModifier;
  keys.key_code = static_cast<Qt::Key>(event->key());
  return keys;
}
void ChooseKeys::keyPressEvent(QKeyEvent *event) {
  if (ui->save_as->isChecked())
    hot_keys_->setCodeKeyCreate(change_keys(event));
  if (ui->save->isChecked())
    hot_keys_->setCodeKeySave(change_keys(event));
  if (ui->open->isChecked())
    hot_keys_->setCodeKeyOpen(change_keys(event));
  if (ui->quit->isChecked())
    hot_keys_->setCodeKeyExit(change_keys(event));
  keysForUser();
}
