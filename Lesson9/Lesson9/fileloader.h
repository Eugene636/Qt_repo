#ifndef FILELOADER_H
#define FILELOADER_H

#include <QDir>
#include <QFile>
#include <QObject>
#include <QTextStream>

class FileLoader : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString number_tasks READ getNumberTasks)
public:
  FileLoader(QObject *parent = 0);
  Q_INVOKABLE
  bool saveTask(const QString &, const QString &, const QString &);
  Q_INVOKABLE
  QString getTaskName();
  Q_INVOKABLE
  QString getDeadline();
  Q_INVOKABLE
  QString getTask();
  Q_INVOKABLE
  void writeTask(const QString &, const QString &, const QString &);
  ~FileLoader();
  int m_number_tasks;
  QString getNumberTasks();

private:
  QFile file_;
  // QFile last_task_file_;
};

#endif // FILELOADER_H
