#ifndef ORDERSVIEWWINDOW_H
#define ORDERSVIEWWINDOW_H

#include <QDialog>
#include "database.h"

namespace Ui {
class OrdersViewWindow;
}

class OrdersViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OrdersViewWindow(QWidget *parent = 0,DataBase* = nullptr);
    ~OrdersViewWindow();

private:
    Ui::OrdersViewWindow *ui;
    DataBase* base;
    std::list<Order> orders;
    std::list<Order>::iterator crtOrder;
    int ordersAmount;
    int crtPosition;
private slots:
    void printOrders();
};

#endif // ORDERSVIEWWINDOW_H
