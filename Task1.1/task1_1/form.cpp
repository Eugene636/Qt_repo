#include "form.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include <chrono>

Form::Form(QWidget *parent) : QDialog(parent) {
  button = new QPushButton(this);
  login = new QLineEdit(this);
  password = new QLineEdit(this);
  password->setEchoMode(QLineEdit::EchoMode::Password);
  // this->setStyleSheet("QLineEdit {color: red}");
  layout.addWidget(login);
  layout.addWidget(password);
  layout.addWidget(button);
  setLayout(&layout);
  connect(button, &QPushButton::clicked, this, &Form::buttonClicked);
}
void Form::buttonClicked() {
  QString login_string = login->text();
  QString password_string = password->text();
  if ((login_string == "login") && (password_string == "password")) {
    a1 = new QPropertyAnimation(this, "windowOpacity");
    a1->setDuration(2000);
    a1->setStartValue(1);
    a1->setEndValue(0);
    connect(a1, &QVariantAnimation::valueChanged, this, &Form::draw);
    emit trueSignal();
    a1->start();
    QTimer::singleShot(2000, this, SLOT(quit()));
  } else {
    const int duration = 100;
    this->setStyleSheet("QLineEdit {color: red}");
    login->update(login->visibleRegion());
    QTimer::singleShot(duration, this, SLOT(color()));
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    anim1 = new QPropertyAnimation(this, "pos");
    anim2 = new QPropertyAnimation(this, "pos");
    anim3 = new QPropertyAnimation(this, "pos");
    anim1->setDuration(duration / 2);
    anim1->setStartValue(QPoint(this->x(), this->y()));
    anim1->setEndValue(QPoint(this->x() - 20, this->y()));
    anim2->setDuration(duration);
    anim2->setStartValue(QPoint(this->x() - 20, this->y()));
    anim2->setEndValue(QPoint(this->x() + 20, this->y()));
    anim3->setDuration(duration / 2);
    anim3->setStartValue(QPoint(this->x() + 20, this->y()));
    anim3->setEndValue(QPoint(this->x(), this->y()));
    group->addAnimation(anim1);
    group->addAnimation(anim2);
    group->addAnimation(anim3);
    group->start();
  }
}

void Form::quit() { this->close(); }

void Form::draw(const QVariant &value) { update(this->visibleRegion()); }
void Form::color() {
  this->setStyleSheet("QLineEdit {color: black}");
  login->update(login->visibleRegion());
}
