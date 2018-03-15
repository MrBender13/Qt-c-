#ifndef BASKETVIEWWINDOW_H
#define BASKETVIEWWINDOW_H

#include <QDialog>
#include "database.h"
#include "order.h"

namespace Ui {
class BasketViewWindow;
}

class BasketViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BasketViewWindow(QWidget *parent = 0,DataBase* = nullptr,Client* = nullptr);
    ~BasketViewWindow();


private:
    Ui::BasketViewWindow *ui;
    DataBase* base;
    Client* crtClient;

private slots:
    void printProducts();
    void deleteFromBasket();
    void submitOrder();
};

#endif // BASKETVIEWWINDOW_H
