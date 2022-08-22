#ifndef TREEVIEWFILE_H
#define TREEVIEWFILE_H

#include <QFileSystemModel>
#include <QPlainTextEdit>
#include <QTreeView>
#include <QWidget>
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
private slots:
    void selectionSlot(const QItemSelection& selected,
                       const QItemSelection& deselected);
    void setDirectory();
};

#endif // TREEVIEWFILE_H
