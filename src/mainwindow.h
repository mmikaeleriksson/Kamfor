#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "importTemplate.h"
#include "transactionsModel.h"

namespace Ui {
    class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void import(bool checked);

private:
    Ui::MainWindow *ui;
    TransactionModel* model;
    QSortFilterProxyModel* proxyModel;
};


#endif // MAINWINDOW_H
