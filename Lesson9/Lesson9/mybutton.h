#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QWidget>

class MyButton : public QPushButton {
  Q_OBJECT
public:
  MyButton(QWidget *parent = 0);
};

#endif // MYBUTTON_H
