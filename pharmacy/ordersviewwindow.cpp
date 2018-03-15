#include "ordersviewwindow.h"
#include "ui_ordersviewwindow.h"

OrdersViewWindow::OrdersViewWindow(QWidget *parent,DataBase* newBase) :
    QDialog(parent),
    ui(new Ui::OrdersViewWindow)
{
    ui->setupUi(this);
    //assuming fields of class
    this->base = base;
    this->orders = base->getOrders();
    this->crtOrder = orders.begin();
    this->crtPosition = 0;
    this->ordersAmount = orders.size();
    if(ordersAmount == 0) throw noActiveOrders();

    printOrders();
}

void OrdersViewWindow::printOrders() {
    ui->ordersOutput->clear();
    std::string res = "Информация о заказчике: \n";
    res += crtOrder->getCustomerSurname() + "\n" + crtOrder->getCustomerName() + "\n";
    res += crtOrder->getCustomerFathername() + "\n" + crtOrder->getCustomerPhone() + "\n";
    res += crtOrder->getCustomerAdress() + "\n" + "Заказ: \n";
    for(auto it : crtOrder->getItems()) {
        res += it.getName() + " " + std::to_string(it.getPrise()) + " " + std::to_string(it.getAmount()) + "\n";
    }
    ui->ordersOutput->setText(QString::fromStdString(res));
    ui->sumLabel->setText(QString::fromStdString("Сумма заказа - " + std::to_string(crtOrder->getSum())));
}

OrdersViewWindow::~OrdersViewWindow()
{
    delete ui;
}
