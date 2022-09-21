#ifndef CHOOSEKEYS_H
#define CHOOSEKEYS_H
/*Диалоговое меню выбора горячих клавиш. */
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
  Ui::ChooseKeys *ui;
  void keysForUser(); //вывод всех в текстовые поля UI
protected:
  virtual void keyPressEvent(QKeyEvent *event) override;

private:
  KeyShortcut
  change_keys(QKeyEvent *); //функция для получения значений keymodifier и
                            // keycode. поскольку не нашлось функции
  //для прямого приcвоения qt::keymodifiers

  void
  keysToTextField(const KeyShortcut &,
                  QPlainTextEdit *); //вывод конкретного значения keyshortcut в
                                     //конкретное текстовое поле
  Keys *hot_keys_;
};

#endif // CHOOSEKEYS_H
