#include "keys.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

Keys::Keys() {
  QFile key_file("keys/keys.txt");
  QTextStream istream(&key_file);
  if (key_file.open(QIODevice::ReadOnly)) {
    int temp;
    istream >> temp;
    code_key_create_.key_code = static_cast<Qt::Key>(temp);
    istream >> temp;
    code_key_create_.key_modifier = static_cast<Qt::KeyboardModifier>(temp);
    istream >> temp;
    code_key_save_.key_code = static_cast<Qt::Key>(temp);
    istream >> temp;
    code_key_save_.key_modifier = static_cast<Qt::KeyboardModifier>(temp);
    istream >> temp;
    code_key_open_.key_code = static_cast<Qt::Key>(temp);
    istream >> temp;
    code_key_open_.key_modifier = static_cast<Qt::KeyboardModifier>(temp);
    istream >> temp;
    code_key_exit_.key_code = static_cast<Qt::Key>(temp);
    istream >> temp;
    code_key_exit_.key_modifier = static_cast<Qt::KeyboardModifier>(temp);
    key_file.close();
  } else {
    QDir directory;
    if (!directory.cd("keys")) {
      directory.mkdir("keys");
    }
    code_key_create_.key_code = Qt::Key_N;
    code_key_create_.key_modifier = Qt::ControlModifier;
    code_key_save_.key_code = Qt::Key_S;
    code_key_save_.key_modifier = Qt::ControlModifier;
    code_key_open_.key_code = Qt::Key_O;
    code_key_open_.key_modifier = Qt::ControlModifier;
    code_key_exit_.key_code = Qt::Key_Q;
    code_key_exit_.key_modifier = Qt::ControlModifier;
    writeKeysToFile();
  }
}
const KeyShortcut &Keys::getCodeKeyCreate() const { return code_key_create_; }
const KeyShortcut &Keys::getCodeKeyOpen() const { return code_key_open_; }
const KeyShortcut &Keys::getCodeKeySave() const { return code_key_save_; }
const KeyShortcut &Keys::getCodeKeyExit() const { return code_key_exit_; }

bool KeyShortcut::operator==(const KeyShortcut &right) const {
  if ((this->key_code == right.key_code) &&
      (this->key_modifier == right.key_modifier))
    return true;
  else
    return false;
}
void KeyShortcut::operator=(const KeyShortcut &right) {
  this->key_code = right.key_code;
  this->key_modifier = right.key_modifier;
}
bool Keys::setCodeKeySave(const KeyShortcut &key) {
  if ((key == code_key_open_) || (key == code_key_exit_) ||
      (key == code_key_create_) || (key == KeyShortcut())) {
    return false;
  }
  code_key_save_ = key;
  return true;
}
bool Keys::setCodeKeyOpen(const KeyShortcut &key) {
  if ((key == code_key_save_) || (key == code_key_exit_) ||
      (key == code_key_create_) || (key == KeyShortcut()))
    return false;
  code_key_open_ = key;
  return true;
}
bool Keys::setCodeKeyCreate(const KeyShortcut &key) {
  if ((key == code_key_save_) || (key == code_key_open_) ||
      (key == code_key_exit_) || (key == KeyShortcut()))
    return false;
  code_key_create_ = key;
  return true;
}
bool Keys::setCodeKeyExit(const KeyShortcut &key) {
  if ((key == code_key_save_) || (key == code_key_open_) ||
      (key == code_key_create_) || (key == KeyShortcut()))
    return false;
  code_key_exit_ = key;
  return true;
}
KeyShortcut::KeyShortcut()
    : key_code(Qt::Key_unknown), key_modifier(Qt::NoModifier) {}
void Keys::writeKeysToFile() {
  QFile key_file("keys/keys.txt");
  QTextStream ostream(&key_file);
  key_file.open(QIODevice::WriteOnly);
  ostream << code_key_create_.key_code << ' ' << code_key_create_.key_modifier
          << "\r\n";
  ostream << code_key_save_.key_code << ' ' << code_key_save_.key_modifier
          << "\r\n";
  ostream << code_key_open_.key_code << ' ' << code_key_open_.key_modifier
          << "\r\n";
  ostream << code_key_exit_.key_code << ' ' << code_key_exit_.key_modifier
          << "\r\n";
  key_file.close();
}
