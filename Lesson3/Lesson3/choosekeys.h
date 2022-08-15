#ifndef CHOOSEKEYS_H
#define CHOOSEKEYS_H

#include "keys.h"
#include <QDialog>
namespace Ui {
class ChooseKeys;
}
class QPlainTextEdit;
class QRadioButton;
class ChooseKeys : public QDialog {
  Q_OBJECT

public:
  explicit ChooseKeys(Keys *, QWidget *parent = nullptr);
  ~ChooseKeys();
  void translate(const QString &);

protected:
  virtual void keyPressEvent(QKeyEvent *event) override;

private:
  KeyShortcut change_keys(QKeyEvent *);
  Ui::ChooseKeys *ui;
  void keysForUser();
  void keysToTextField(const KeyShortcut &, QPlainTextEdit *);
  Keys *hot_keys_;
};

#endif // CHOOSEKEYS_H
