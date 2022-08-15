#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Help : public QDialog {
  Q_OBJECT

public:
  explicit Help(QWidget *parent = nullptr);
  void translate(const QString &);
  void setHelpText(const QString &);
  ~Help();

private:
  Ui::Dialog *ui;
};

#endif // HELP_H
