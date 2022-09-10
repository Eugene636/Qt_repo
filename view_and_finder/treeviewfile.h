#ifndef TREEVIEWFILE_H
#define TREEVIEWFILE_H

#include <QDebug>
#include <QDir>
#include <QFileSystemModel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRegExp>
#include <QThread>
#include <QTreeView>
#include <QWidget>
class Finder : public QObject
{
    Q_OBJECT
public:
    Finder(QObject* parent = 0)
        : QObject(parent){};
public slots:
    void Find(const QString& s, const QRegExp& shortcut)
    {
        QDir    d(s);
        QString pattern = shortcut.pattern();
        if (pattern.isEmpty())
            return;
        QFileInfoList lst =
            d.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);
        for (auto n : lst)
        {
            if (n.isDir())
            {
                QDir new_d(n.absoluteFilePath());
                Find(n.absoluteFilePath(), shortcut);
            }

            shortcut.exactMatch(n.fileName());
            if (pattern.size() == shortcut.matchedLength())
            {
                emit findString(n.absoluteFilePath());
            }
        }
    }
signals:
    void findString(const QString& string);
};

class TreeViewFile : public QWidget
{
    Q_OBJECT
public:
    TreeViewFile(QWidget* parent);
    ~TreeViewFile();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QTreeView*          view_;
    QPlainTextEdit*     text_;
    QFileSystemModel    filesystem_;
    QItemSelectionModel select_;
    QPlainTextEdit*     name_;
    QPushButton*        findButton_;
    QPlainTextEdit*     findResults_;
    Finder*             finder_;
    QThread             findThread_;
signals:
    void findStringSender(const QString& d, const QRegExp& shortcut);
private slots:
    void findSender();
    void selectionSlot(const QItemSelection& selected,
                       const QItemSelection& deselected);
    void setDirectory();
public slots:
    void searchResults(const QString&);
};

#endif // TREEVIEWFILE_H
