#include "productsredactor.h"
#include "ui_productsredactor.h"

ProductsRedactor::ProductsRedactor(QWidget *parent, DataBase* newBase,std::string author) :
    QDialog(parent),
    ui(new Ui::ProductsRedactor)
{
    ui->setupUi(this);
    base = newBase;
    this->author = author;

    //at first all buttons should be disabled exept exit and adding new type of product
    ui->addButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);

    //printing list of products
    printProducts();
    //connecting add new product button with adding new product window
    connect(ui->addNewTypeButton,SIGNAL(clicked(bool)),this,SLOT(addNewProduct()));
    connect(ui->deleteAllButton,SIGNAL(clicked(bool)),this,SLOT(delProduct()));
    //regular expression for adding and deleting elements to/from base
    QRegExp redactorNumb("[1-9]{1}[0-9]{0,4}");
    ui->addInput->setValidator(new QRegExpValidator(redactorNumb));
    ui->deleteInput->setValidator(new QRegExpValidator(redactorNumb));

    //connecting slots that activate buttons
    connect(ui->addInput,SIGNAL(textChanged(QString)),this,SLOT(addButtonEnable()));
    connect(ui->deleteInput,SIGNAL(textChanged(QString)),this,SLOT(delButtonEnable()));
    connect(ui->deleteAllButton,SIGNAL(clicked(bool)),this,SLOT(enableButtons()));
    connect(ui->addNewTypeButton,SIGNAL(clicked(bool)),this,SLOT(enableButtons()));
    //connecting slots to increase/decrease amount of products
    connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(increaseProductsAmount()));
    connect(ui->deleteButton,SIGNAL(clicked(bool)),this,SLOT(decreaseProductsAmount()));
}

void ProductsRedactor::enableButtons() {
    //those buttons are enabled if there are existing products
    ui->deleteAllButton->setEnabled(base->isItemsEmpty());
    addButtonEnable();
    delButtonEnable();
}

void ProductsRedactor::increaseProductsAmount() {
    //getting selected item's name
    std::string name = ui->itemsList->currentItem()->text().toStdString();
    name.erase(name.find(' '));
    base->increaseItemAmount(name,ui->addInput->text().toInt());
    ui->addInput->clear();
    printProducts();
}

void ProductsRedactor::decreaseProductsAmount() {
    //getting selected item's name
    std::string name = ui->itemsList->currentItem()->text().toStdString();
    name.erase(name.find(' '));
    try {
        //deleting chosen product from base (pointed amount)
        base->decreaseItemAmount(name,ui->deleteInput->text().toInt());
        ui->deleteInput->clear();
        printProducts();
    } catch(lackOfItems err) {
        //if we are trying to delete more than exist
        ErrorWindow newWind(this,err.what());
        newWind.show();
        newWind.exec();
    }
}

void ProductsRedactor::addButtonEnable() {
    ui->addButton->setEnabled(base->isItemsEmpty() && ui->addInput->hasAcceptableInput());
}

void ProductsRedactor::delButtonEnable() {
     ui->deleteButton->setEnabled(base->isItemsEmpty() && ui->deleteInput->hasAcceptableInput());
}

void ProductsRedactor::delProduct() {
    //getting selected item's name
    std::string name = ui->itemsList->currentItem()->text().toStdString();
    name.erase(name.find(' '));
    base->delItem(name);
    printProducts();
}

void ProductsRedactor::addNewProduct() {
    AddingProductWindow newWind(this,base,author);
    newWind.show();
    newWind.exec();
    printProducts();
}

void ProductsRedactor::printProducts() {
    ui->itemsList->clear();
    std::list<Item> products = base->getItems();
    for(auto it : products) {
        std::string newItem = it.getName() + "  " + std::to_string(it.getPrise()) + "  " + std::to_string(it.getAmount()) + "  " + it.getAuthor();
        ui->itemsList->addItem(QString::fromStdString(newItem));
    }
    //by default first element is selected
    ui->itemsList->setCurrentRow(0);
}

ProductsRedactor::~ProductsRedactor()
{
    delete ui;
}
