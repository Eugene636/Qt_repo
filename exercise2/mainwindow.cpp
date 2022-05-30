#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItem>

//#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow) {
  ui_->setupUi(this);

  ui_->listView->setModel(&model_);
  ui_->listView->setSelectionMode(QAbstractItemView::SingleSelection);
  QIcon cpp(":/cpp");
  QIcon java(":/java");
  QIcon python(":/python");
  QIcon csharp(":/charp");
  QIcon php(":/php");
  QIcon js(":/js");
  model_.appendRow(new QStandardItem(cpp, "C++"));
  model_.appendRow(new QStandardItem(java, "Java"));
  model_.appendRow(new QStandardItem(python, "Python"));
  model_.appendRow(new QStandardItem(csharp, "C#"));
  model_.appendRow(new QStandardItem(js, "JavaScript"));
  connect(ui_->removeButton, &QPushButton::clicked, this,
          &MainWindow::onRemoveButton);
  connect(ui_->addButton, &QPushButton::clicked, this,
          &MainWindow::onAddButton);

  setWindowTitle("Lang list");
}

MainWindow::~MainWindow() { delete ui_; }

void MainWindow::onRemoveButton() {
  auto selection_model = ui_->listView->selectionModel();
  if (selection_model->hasSelection()) {
    auto cur_ind = selection_model->currentIndex();
    if (cur_ind.isValid()) {
      model_.removeRow(cur_ind.row());
    }
  }
}

void MainWindow::onAddButton() {
  if (!ui_->langNameEdit->text().isEmpty()) {
    QIcon assembler(":/default");
    model_.appendRow(new QStandardItem(assembler, ui_->langNameEdit->text()));
    ui_->langNameEdit->clear();
  }
}
//

void MainWindow::on_IconView_stateChanged(int arg1) {
  if (ui_->IconView->isChecked())
    ui_->listView->setViewMode(QListView::IconMode);
  else
    ui_->listView->setViewMode(QListView::ListMode);
}
void MainWindow::on_up_b_clicked() {
  auto selection_model = ui_->listView->selectionModel();
  if (selection_model->hasSelection()) {
    int row = -1, all_rows = -1;
    auto cur_ind = selection_model->currentIndex();
    if (cur_ind.isValid()) {
      QStandardItem *it;
      int count = 0;
      for (it = model_.item(count); it; it = model_.item(count)) {
        if (model_.itemFromIndex(cur_ind) == it)
          row = count;
        count++;
      }
      all_rows = count;
      if (row != -1) {
        it = model_.takeItem(row);
        if (row > 0) {
          QStandardItem *it2 = model_.takeItem(row - 1);
          model_.setItem(row - 1, it);
          model_.setItem(row, it2);
        }
        if (row == 0) {
          QStandardItem *it2 = model_.takeItem(all_rows - 1);
          model_.setItem(all_rows - 1, it);
          model_.setItem(row, it2);
        }
        selection_model->clearSelection();
        ui_->listView->setSelectionModel(selection_model);
      }
    }
  }
}

void MainWindow::on_down_b_clicked() {
  auto selection_model = ui_->listView->selectionModel();
  if (selection_model->hasSelection()) {
    int row = -1, all_rows = -1;
    auto cur_ind = selection_model->currentIndex();
    if (cur_ind.isValid()) {
      QStandardItem *it;
      int count = 0;
      for (it = model_.item(count); it; it = model_.item(count)) {
        if (model_.itemFromIndex(cur_ind) == it)
          row = count;
        count++;
      }
      all_rows = count;
      if (row != -1) {
        it = model_.takeItem(row);
        if (row != all_rows - 1) {
          QStandardItem *it2 = model_.takeItem(row + 1);
          model_.setItem(row + 1, it);
          model_.setItem(row, it2);
        }
        if (row == all_rows - 1) {
          QStandardItem *it2 = model_.takeItem(0);
          model_.setItem(0, it);
          model_.setItem(row, it2);
        }
      }
      selection_model->clearSelection();
      ui_->listView->setSelectionModel(selection_model);
    }
  }
}

void MainWindow::on_lang_edit_b_clicked() {
  auto selection_model = ui_->listView->selectionModel();
  if (selection_model->hasSelection()) {
    auto cur_ind = selection_model->currentIndex();
    if (cur_ind.isValid()) {
      QString new_name = ui_->lang_name_edit->text();
      if (!new_name.isEmpty()) {
        QStandardItem *changing_lang = model_.itemFromIndex(cur_ind);
        changing_lang->setText(new_name);
      }
    }
    selection_model->clearSelection();
    ui_->listView->setSelectionModel(selection_model);
  }
}
