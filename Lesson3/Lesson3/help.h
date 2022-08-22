#ifndef HELP_H
#define HELP_H
/*вывод справки. Нашли вшитый файл и выбросили в текстовое поле textbrowser*/
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
