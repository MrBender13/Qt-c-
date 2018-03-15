#ifndef PRODUCTSREDACTOR_H
#define PRODUCTSREDACTOR_H

#include <QDialog>
#include "database.h"
#include "addingproductwindow.h"
#include "errorwindow.h"

namespace Ui {
class ProductsRedactor;
}

class ProductsRedactor : public QDialog
{
    Q_OBJECT

public:
    explicit ProductsRedactor(QWidget *parent = 0, DataBase* = nullptr,std::string = "");
    ~ProductsRedactor();

private:
    Ui::ProductsRedactor *ui;
    DataBase* base;
    std::string author;

private slots:
    void printProducts();
    void addNewProduct();
    void delProduct();
    void addButtonEnable();
    void delButtonEnable();
    void increaseProductsAmount();
    void decreaseProductsAmount();
    void enableButtons();
};

#endif // PRODUCTSREDACTOR_H
