#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <QObject>

class MathFunctions : public QObject {
  Q_OBJECT
public:
  MathFunctions(QObject *parent = 0);
  Q_INVOKABLE
  QString square(const QString &, const QString &, const QString &,
                 const QString &);
};

#endif // MATHFUNCTIONS_H
