#include "treeviewfile.h"

TreeViewFile::TreeViewFile(QWidget* parent)
    : QWidget(parent)
{
    text_       = new QPlainTextEdit(this);
    view_       = new QTreeView(this);
    name_       = new QPlainTextEdit(this);
    findButton_ = new QPushButton(this);
    finder_     = new Finder();
    findButton_->setText("Find");
    finder_->moveToThread(&findThread_);
    findThread_.start();
    findResults_ = new QPlainTextEdit(this);
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
    connect(
        findButton_, &QPushButton::clicked, this, &TreeViewFile::findSender);
    connect(this, &TreeViewFile::findStringSender, finder_, &Finder::Find);
    connect(finder_, &Finder::findString, this, &TreeViewFile::searchResults);
}

void TreeViewFile::resizeEvent(QResizeEvent* event)
{
    QRect r = geometry();
    int   h = r.height();
    text_->setGeometry(r.x(), r.y(), r.width() - 20, 40);
    name_->setGeometry(r.x(), r.y() + 50, r.width() - 20 - 100, 20);
    findButton_->setGeometry(
        r.x() + (r.width() - 20 - 100), r.y() + 50, 100, 20);
    view_->setGeometry(r.x(), r.y() + 80, r.width() - 20, h - 300);
    findResults_->setGeometry(r.x(), r.y() + h - 210, r.width() - 20, 210);
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
    QModelIndex l = select_.currentIndex();
    /*if (!l.isEmpty())
        qDebug() << "Is not selection";
    else*/
    view_->setRootIndex(l);
    QFileInfo f = filesystem_.fileInfo(l);
    text_->setPlainText(f.absolutePath());
}
TreeViewFile::~TreeViewFile()
{
    findThread_.quit();
    findThread_.wait();
}
void TreeViewFile::findSender()
{
    QRegExp r(name_->toPlainText());
    QString s = text_->toPlainText();
    QDir    d(s);
    findResults_->clear();
    emit    findStringSender(s, r);
}
void TreeViewFile::searchResults(const QString& s)
{
    findResults_->appendPlainText(s);
}
