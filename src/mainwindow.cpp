#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new TransactionModel(this);
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->transactionsView->setModel(proxyModel);

    connect(ui->actionImport, &QAction::triggered,
            this, &MainWindow::import);
}


void MainWindow::import(bool checked)
{
    model->layoutAboutToBeChanged();
    importExample();
    model->layoutChanged();
}
