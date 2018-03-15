#ifndef PRODUCTSWIEWWINDOW_H
#define PRODUCTSWIEWWINDOW_H

#include <QDialog>
#include "database.h"
#include "errorwindow.h"

namespace Ui {
class ProductsWiewWindow;
}

class ProductsWiewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProductsWiewWindow(QWidget *parent = 0,DataBase* = nullptr,Client* = nullptr);
    ~ProductsWiewWindow();

private:
    Ui::ProductsWiewWindow *ui;
    DataBase* base;
    Client* crtClient;

private slots:
    void printProducts();
    void addButtonEnable();
    void addToBasket();
};

#endif // PRODUCTSWIEWWINDOW_H
