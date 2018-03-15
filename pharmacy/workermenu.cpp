#include "workermenu.h"
#include "ui_workermenu.h"

workerMenu::workerMenu(QWidget *parent,DataBase* newBase, std::string accountLogin) :
    QDialog(parent),
    ui(new Ui::workerMenu)
{
    ui->setupUi(this);
    base = newBase;
    account = accountLogin;

    connect(ui->registerButton,SIGNAL(clicked(bool)),this,SLOT(registerNewWorker()));
    connect(ui->pruductsRedactorButton,SIGNAL(clicked(bool)), this, SLOT(productRedactorCall()));
    connect(ui->activeOrdersButton,SIGNAL(clicked(bool)),this,SLOT(ordersViewCall()));
}

void workerMenu::ordersViewCall() {
    try {
        OrdersViewWindow newWind(this,base);
        newWind.show();
        newWind.exec();
    } catch(noActiveOrders err) {
        ErrorWindow newWind(this,err.what());
        newWind.show();
        newWind.exec();
    }
}

void workerMenu::registerNewWorker() {
    //false in registration window constructor means - register new worker
    bool registerWorker = false;
    RegistrationWindow newWind(this,base,registerWorker);
    newWind.show();
    newWind.exec();
}

void workerMenu::productRedactorCall() {
    ProductsRedactor newWind(this,base,account);
    newWind.show();
    newWind.exec();
}

workerMenu::~workerMenu()
{
    delete ui;
}
