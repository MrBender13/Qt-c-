#include "productswiewwindow.h"
#include "ui_productswiewwindow.h"

ProductsWiewWindow::ProductsWiewWindow(QWidget *parent,DataBase* newBase,Client* client) :
    QDialog(parent),
    ui(new Ui::ProductsWiewWindow)
{
    ui->setupUi(this);
    this->crtClient = client;
    this->base = newBase;
    printProducts();
    //at first add button should be disabled
    ui->addButton->setEnabled(false);

    //regular expression for amount of product to add
    QRegExp amountRegExp("[0-9]{1,10}");
    ui->addInput->setValidator(new QRegExpValidator(amountRegExp));
    //if info is correct - activate add button
    connect(ui->addInput,SIGNAL(textChanged(QString)),this,SLOT(addButtonEnable()));
    //add button calls adding to busket
    connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(addToBasket()));

}

void ProductsWiewWindow::addToBasket() {
    //getting selected item's name
    std::string name = ui->itemsList->currentItem()->text().toStdString();
    name.erase(name.find(' '));

    try {
        //getting Item by is's name and pushing it to crt client basket. Repainting products list
        base->decreaseItemAmount(name, ui->addInput->text().toInt());
        Item* crt = base->getItemByName(name);
        crt->setAmount(ui->addInput->text().toInt());
        crtClient->addToBasket(crt);
        printProducts();
    } catch(lackOfItems err) {
        //if we are trying to add more than exist
        ErrorWindow newWind(this,err.what());
        newWind.show();
        newWind.exec();
    }
    ui->addInput->clear();
}

void ProductsWiewWindow::printProducts() {
    ui->itemsList->clear();
    std::list<Item> products = base->getItems();
    for(auto it : products) {
        std::string newItem = it.getName() + "  " + std::to_string(it.getPrise()) + "  " + std::to_string(it.getAmount());
        ui->itemsList->addItem(QString::fromStdString(newItem));
    }
    //by default first element is selected
    ui->itemsList->setCurrentRow(0);
}

void ProductsWiewWindow::addButtonEnable() {
    ui->addButton->setEnabled(ui->addInput->hasAcceptableInput());
}

ProductsWiewWindow::~ProductsWiewWindow()
{
    delete ui;
}
