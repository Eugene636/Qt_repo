#include "fileloader.h"
#include <QDate>
#include <QDebug>

FileLoader::FileLoader(QObject *parent) {
  file_.setFileName("Tasks.txt");
  file_.open(QIODevice::Append);
  // last_task_file_.setFileName("LastTask.txt");
}

FileLoader::~FileLoader() { file_.close(); }

bool FileLoader::saveTask(const QString &task_name, const QString &deadline,
                          const QString &task_overwrite) {
  QDate date = QDate::fromString(deadline, "dd.MM.yyyy");
  if (date.isValid()) {
    QTextStream in_file(&file_);
    in_file << '\n'
            << task_name << '\n'
            << deadline << '\n'
            << task_overwrite << '\n'
            << "__End_task__";
    return true;
  } else
    return false;
}

void FileLoader::writeTask(const QString &name, const QString &deadline,
                           const QString &task) {
  QFile lt("LastTask.txt");
  lt.open(QIODevice::WriteOnly | QIODevice::Truncate);
  QTextStream in_file(&lt);
  in_file << "__Task_Name:__" << '\n' << name << '\n';
  in_file << "__Deadline:__" << '\n' << deadline << '\n';
  in_file << "__Task:__" << '\n' << task << '\n';
}

QString FileLoader::getTaskName() {
  QFile lt("LastTask.txt");
  lt.open(QIODevice::ReadOnly);
  QTextStream out_file(&lt);
  QString s;
  while ((s != "__Task_Name:__") && (!out_file.atEnd())) {
    qDebug() << s;
    out_file >> s;
  }
  QString name;
  for (out_file >> s;
       (s != "__Deadline:__") && (s != "__Task:__") && (!out_file.atEnd());
       out_file >> s) {
    name += s;
  }
  qDebug() << name;
  lt.close();
  return name;
}
QString FileLoader::getDeadline() {
  QFile lt("LastTask.txt");
  lt.open(QIODevice::ReadOnly);
  QTextStream out_file(&lt);
  QString s;
  while ((s != "__Deadline:__") && (!out_file.atEnd())) {
    qDebug() << s;
    out_file >> s;
  }
  QString name;
  for (out_file >> s;
       (s != "__Task_Name:__") && (s != "__Task:__") && (!out_file.atEnd());
       out_file >> s) {
    name += s;
  }
  qDebug() << name;
  lt.close();
  return name;
}
QString FileLoader::getTask() {
  QFile lt("LastTask.txt");
  lt.open(QIODevice::ReadOnly);
  QTextStream out_file(&lt);
  QString s;
  while ((s != "__Task:__") && (!out_file.atEnd())) {
    qDebug() << s;
    out_file >> s;
  }
  QString name;
  for (out_file >> s;
       (s != "__Deadline:__") && (s != "__Task_Name:__") && (!out_file.atEnd());
       out_file >> s) {
    name += s;
  }
  qDebug() << name;
  lt.close();
  return name;
}
