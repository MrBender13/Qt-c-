#include "myorderswindow.h"
#include "ui_myorderswindow.h"

MyOrdersWindow::MyOrdersWindow(QWidget *parent,DataBase* base,Client* crtClient) :
    QDialog(parent),
    ui(new Ui::MyOrdersWindow)
{
    ui->setupUi(this);
    this->base = base;
    this->crtClient = crtClient;
    this->crtPosition = 0;
    //getting list with orders of current client
    this->orders = base->getClientOrders(crtClient->getPhone());
    this->ordersAmount = orders.size();
    if(ordersAmount == 0) throw noActiveOrders();
    this->crtOrder = orders.begin();

    printOrders();
    //left scroll should be disabled at first cause current order is the first
    scrollButtonsEnable();
    //connecting scroll buttons and slots that enable them
    connect(ui->leftButton,SIGNAL(clicked(bool)),this,SLOT(scrollButtonsEnable()));
    connect(ui->rightButton,SIGNAL(clicked(bool)),this,SLOT(scrollButtonsEnable()));
    //connecting scroll buttons and slots that scroll orders
    connect(ui->leftButton,SIGNAL(clicked(bool)),this,SLOT(scrollLeft()));
    connect(ui->rightButton,SIGNAL(clicked(bool)),this,SLOT(scrollRight()));
}

void MyOrdersWindow::scrollLeft() {
    --crtOrder;
    crtPosition--;
    scrollButtonsEnable();
    printOrders();
}

void MyOrdersWindow::scrollRight() {
    ++crtOrder;
    crtPosition++;
    scrollButtonsEnable();
    printOrders();
}

void MyOrdersWindow::scrollButtonsEnable() {
    int minBorder = 0;
    //if current order is max left we should disable left scroll button
    ui->leftButton->setEnabled(crtPosition > minBorder);
    //if current order is max right we should disable right scroll button
    ui->rightButton->setEnabled(crtPosition < ordersAmount-1);
}

void MyOrdersWindow::printOrders() {
    ui->ordersOutput->clear();
    std::string res;
    for(auto it : crtOrder->getItems()) {
        res += it.getName() + " " + std::to_string(it.getPrise()) + " " + std::to_string(it.getAmount()) + "\n";
    }
    ui->ordersOutput->setText(QString::fromStdString(res));
    ui->sumLabel->setText(QString::fromStdString("Сумма заказа - " + std::to_string(crtOrder->getSum())));
}

MyOrdersWindow::~MyOrdersWindow()
{
    delete ui;
}
