#ifndef MYORDERSWINDOW_H
#define MYORDERSWINDOW_H

#include <QDialog>
#include "database.h"
#include "order.h"

namespace Ui {
class MyOrdersWindow;
}

class MyOrdersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MyOrdersWindow(QWidget *parent = 0,DataBase* = nullptr,Client* = nullptr);
    ~MyOrdersWindow();

private:
    Ui::MyOrdersWindow *ui;
    DataBase* base;
    Client* crtClient;
    std::list<Order> orders;
    std::list<Order>::iterator crtOrder;
    int ordersAmount;
    int crtPosition;
private slots:
    void printOrders();
    void scrollLeft();
    void scrollRight();
    void scrollButtonsEnable();
};



#endif // MYORDERSWINDOW_H
