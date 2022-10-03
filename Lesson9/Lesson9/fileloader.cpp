#include "fileloader.h"
#include <QDate>
#include <QDebug>
#include <QSqlQuery>

FileLoader::FileLoader(QObject *parent) {
  m_number_tasks = 0;
  db_ = QSqlDatabase::addDatabase("QSQLITE");
  db_.setDatabaseName("Tasks.sqlite");
  if (!db_.open()) {
    qDebug() << "Database not open";
  }
  QSqlQuery query;
  if (!query.exec(
          "create table if not exists Tasks(id integer "
          "primary key,TaskName "
          "varchar(100),Data varchar(16),TaskAbstract varchar(1024))")) {
    qDebug() << "Work table does not create";
  }
  if (!query.exec(
          "create table if not exists BackUp(TaskName "
          "varchar(100),Data varchar(16),TaskAbstract varchar(1024))")) {
    qDebug() << "Backup table does not create";
  }
  query.exec("select MAX (id) from Tasks");
  query.next();
  bool ok;
  int k = query.value(0).toInt(&ok);
  if (ok)
    m_number_tasks = k;
}

FileLoader::~FileLoader() { db_.close(); }

bool FileLoader::saveTask(const QString &task_name, const QString &deadline,
                          const QString &task_overwrite) {
  QDate date = QDate::fromString(deadline, "dd.MM.yyyy");
  if ((date.isValid()) && (!task_name.isEmpty()) &&
      (!task_overwrite.isEmpty())) {
    QSqlQuery query;
    m_number_tasks++;
    QString query_string = "INSERT INTO Tasks VALUES(";
    query_string += QString::number(m_number_tasks) + ", ";
    query_string += "\'" + task_name + "\'" + ", ";
    query_string += "\'" + deadline + "\', ";
    query_string += "\'" + task_overwrite + "\'";
    query_string += ")";
    if (!query.exec(query_string)) {
      qDebug() << "Insert task failed";
    }
    emit dbRenew();
    return true;
  } else
    return false;
}

void FileLoader::writeTask(const QString &name, const QString &deadline,
                           const QString &task) {
  QSqlQuery query;
  if (!query.exec("DELETE from BackUp")) {
    qDebug() << "Not Deleted";
  }
  QString query_string = "INSERT INTO BackUp VALUES(";
  query_string += "\'" + name + "\'" + ", ";
  query_string += "\'" + deadline + "\', ";
  query_string += "\'" + task + "\'";
  query_string += ")";
  query.exec(query_string);
}

QString FileLoader::getTaskName() {
  QString name;
  QSqlQuery query;
  query.exec("SELECT TaskName FROM BackUp");
  query.next();
  name = query.value(0).toString();
  return name;
}
QString FileLoader::getDeadline() {
  QString date;
  QSqlQuery query;
  query.exec("SELECT Data FROM BackUp");
  query.next();
  date = query.value(0).toString();
  return date;
}
QString FileLoader::getTask() {
  QString Task;
  QSqlQuery query;
  query.exec("SELECT TaskAbstract FROM BackUp");
  query.next();
  Task = query.value(0).toString();
  return Task;
}
QString FileLoader::getNumberTasks() {
  return (QString::number(m_number_tasks));
}
