#include "addingproductwindow.h"
#include "ui_addingproductwindow.h"

AddingProductWindow::AddingProductWindow(QWidget *parent,DataBase* newBase,std::string author) :
    QDialog(parent),
    ui(new Ui::AddingProductWindow)
{
    ui->setupUi(this);
    base = newBase;
    this->author = author;

    //at first button save should be disabled
    ui->saveButton->setEnabled(false);
    //regular expression for name
    QRegExp nameRegExp("[a-zA-Z]{3,20}");
    ui->nameInput->setValidator(new QRegExpValidator(nameRegExp));
    //regular expression for prise
    QRegExp priseRegExp("[1-9]{1}[0-9]{0,10}");
    ui->priseInput->setValidator(new QRegExpValidator(priseRegExp));
    //regular expression for amount
    QRegExp amountRegExp("[0-9]{1,10}");
    ui->amountInput->setValidator(new QRegExpValidator(amountRegExp));
    //connecting input lines with save button
    connect(ui->nameInput,SIGNAL(textChanged(QString)),this,SLOT(saveEnable()));
    connect(ui->priseInput,SIGNAL(textChanged(QString)),this, SLOT(saveEnable()));
    connect(ui->amountInput,SIGNAL(textChanged(QString)),this,SLOT(saveEnable()));
    //connecting save button with cteation of new product
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(addItem()));

}

void AddingProductWindow::addItem() {
    //this method is called when we have the info and now we can add a product
    Item newItem(ui->nameInput->text().toStdString(), ui->priseInput->text().toInt(),
                 ui->amountInput->text().toInt(),this->author);

    try {
        base->addItem(&newItem);
    } catch(notUniqueItem err) {
       ErrorWindow newWind(this,err.what());
       newWind.show();
       newWind.exec();
    }
    this->close();
}

void AddingProductWindow::saveEnable() {
    //if info is correct we can enable save button
    ui->saveButton->setEnabled(ui->nameInput->hasAcceptableInput() &&
                               ui->priseInput->hasAcceptableInput() &&
                               ui->amountInput->hasAcceptableInput());
}

AddingProductWindow::~AddingProductWindow()
{
    delete ui;
}
