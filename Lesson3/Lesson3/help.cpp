#include "help.h"
#include "ui_help.h"
#include <QTranslator>

Help::Help(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Help::~Help() { delete ui; }

void Help::setHelpText(const QString &s) { ui->help_text->setText(s); }

void Help::translate(const QString &language) {
  QTranslator translator;
  translator.load("Qt_Language_" + language);
  qApp->installTranslator(&translator);
  setWindowTitle(tr("Dialog"));
}
