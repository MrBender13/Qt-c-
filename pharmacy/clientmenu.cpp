#include "clientmenu.h"
#include "ui_clientmenu.h"

ClientMenu::ClientMenu(QWidget *parent,DataBase* newBase,std::string account) :
    QDialog(parent),
    ui(new Ui::ClientMenu)
{
    ui->setupUi(this);
    this->base = newBase;
    this->crtClient = base->getClientByLogin(account);

    //connecting view products button with it's slot
    connect(ui->seeProductsButton,SIGNAL(clicked(bool)),this,SLOT(callProductsView()));
    connect(ui->buscketButton,SIGNAL(clicked(bool)),this, SLOT(callBasketView()));
    connect(ui->ordersButton,SIGNAL(clicked(bool)),this,SLOT(callOrdersView()));
}

void ClientMenu::callOrdersView() {
    try {
        MyOrdersWindow newWind(this,base,crtClient);
        newWind.show();
        newWind.exec();
    } catch (noActiveOrders err) {
        ErrorWindow newWind(this,err.what());
        newWind.show();
        newWind.exec();
    }
}

void ClientMenu::callBasketView() {
    BasketViewWindow newWind(this,base,crtClient);
    newWind.show();
    newWind.exec();
}

void ClientMenu::callProductsView() {
    ProductsWiewWindow newWind(this,base,crtClient);
    newWind.show();
    newWind.exec();
}

ClientMenu::~ClientMenu()
{
    delete ui;
}
