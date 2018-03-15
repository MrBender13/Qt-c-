#include "basketviewwindow.h"
#include "ui_basketviewwindow.h"

BasketViewWindow::BasketViewWindow(QWidget *parent,DataBase* base,Client* crtClient) :
    QDialog(parent),
    ui(new Ui::BasketViewWindow)
{
    ui->setupUi(this);
    this->base = base;
    this->crtClient = crtClient;

    printProducts();

    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteFromBasket()));
    connect(ui->submitButton,SIGNAL(clicked(bool)),this,SLOT(submitOrder()));

}

void BasketViewWindow::submitOrder() {
    Order newOrder(crtClient->getName(),crtClient->getSurname(),crtClient->getFathername(),
                   crtClient->getPhone(),crtClient->getAdress(),crtClient->getBasket());
    base->addOrder(&newOrder);
    crtClient->freeBasket();
    this->close();
}

void BasketViewWindow::deleteFromBasket() {
    //getting selected item's name
    std::string name = ui->itemsList->currentItem()->text().toStdString();
    name.erase(name.find(' '));
    //delete from basket and add back to base
    base->increaseItemAmount(name,crtClient->getItemAmoutByName(name));
    crtClient->delFromBasket(name);
    printProducts();
}

void BasketViewWindow::printProducts() {
    ui->itemsList->clear();
    std::list<Item> products = crtClient->getBasket();
    for(auto it : products) {
        std::string newItem = it.getName() + "  " + std::to_string(it.getPrise()) + "  " + std::to_string(it.getAmount());
        ui->itemsList->addItem(QString::fromStdString(newItem));
    }
    //by default first element is selected
    ui->itemsList->setCurrentRow(0);
    //if basket is empty submit and delete buttons are disabled
    ui->deleteButton->setEnabled(crtClient->isBasketEmpty());
    ui->submitButton->setEnabled(crtClient->isBasketEmpty());
    //printing sum of products in basket
    ui->sumLabel->setText(QString::fromStdString("Сумма вашего заказа - " + std::to_string(crtClient->getBasketSum())));
}

BasketViewWindow::~BasketViewWindow()
{
    delete ui;
}
