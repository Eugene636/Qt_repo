#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
class QPropertyAnimation;
class Form : public QDialog {
  Q_OBJECT
public:
  explicit Form(QWidget *parent = nullptr);

signals:
  void trueSignal();

private:
  QVBoxLayout layout;
  QPushButton *button;
  QLineEdit *login;
  QLineEdit *password;
  QPropertyAnimation *a1;
  QPropertyAnimation *anim1;
  QPropertyAnimation *anim2;
  QPropertyAnimation *anim3;
  void draw(const QVariant &);
private slots:
  void buttonClicked();
  void quit();
  void color();
};

#endif // FORM_H
