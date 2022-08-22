#include "treeviewfile.h"
#include <QDebug>
TreeViewFile::TreeViewFile(QWidget* parent)
    : QWidget(parent)
{
    text_ = new QPlainTextEdit(parent);
    view_ = new QTreeView(parent);
    filesystem_.setRootPath(QDir::currentPath());
    view_->setModel(&filesystem_);
    text_->setPlainText(filesystem_.rootPath());
    view_->setRootIndex(filesystem_.index(QDir::currentPath()));
    select_.setModel(&filesystem_);
    view_->setSelectionModel(&select_);
    connect(
        text_, &QPlainTextEdit::textChanged, this, &TreeViewFile::setDirectory);
    connect(&select_,
            &QItemSelectionModel::selectionChanged,
            this,
            &TreeViewFile::selectionSlot);
}

void TreeViewFile::resizeEvent(QResizeEvent* event)
{
    QRect r = geometry();
    int   h = r.height();
    text_->setGeometry(r.x(), r.y(), r.width(), 40);
    view_->setGeometry(r.x(), r.y() + 50, r.width(), h - 50);
}

void TreeViewFile::setDirectory()
{
    QString s = text_->toPlainText();
    QDir    d(s);
    if (d.exists())
    {
        view_->setRootIndex(filesystem_.index(d.absolutePath()));
    }
}
void TreeViewFile::selectionSlot(const QItemSelection& selected,
                                 const QItemSelection& deselected)
{
    qDebug() << "In selection event";
    QModelIndex l = select_.currentIndex();
    /*if (!l.isEmpty())
        qDebug() << "Is not selection";
    else*/
    view_->setRootIndex(l);
    QFileInfo f = filesystem_.fileInfo(l);
    text_->setPlainText(f.absolutePath());
}
TreeViewFile::~TreeViewFile() {}
