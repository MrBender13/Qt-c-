#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent, DataBase* newBase, bool registerClient) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    //getting base and type of registration
    base = newBase;
    isClientRegistration = registerClient;
    //at first registration button should be disabled
    ui->registerButton->setEnabled(false);

    //regular expressions for surname,name,fathername
    QRegExp fioRegExp("[A-Z]{1}[a-z]{1,15}");
    ui->surnameInput->setValidator(new QRegExpValidator(fioRegExp,this));
    ui->nameInput->setValidator(new QRegExpValidator(fioRegExp,this));
    ui->fatherNameInput->setValidator(new QRegExpValidator(fioRegExp,this));
    //regular expression for age
    QRegExp ageRegExp("[1-9]{1}[0-9]{1,2}");
    ui->ageInput->setValidator(new QRegExpValidator(ageRegExp,this));
    //regular expression for phone
    QRegExp phoneRegExp("[0-9]{11}");
    ui->phoneInput->setValidator((new QRegExpValidator(phoneRegExp,this)));
    //regular expression for adress
    QRegExp adressRegExp("[A-Z]{1}[a-z]{2,15}[' ']{1}[0-9]{1,4}");
    ui->adressInput->setValidator(new QRegExpValidator(adressRegExp,this));
    //regular expression for login
    QRegExp logRegExp("[0-9A-Za-z_]{3,15}");
    ui->loginInput->setValidator(new QRegExpValidator(logRegExp,this));
    //regular expression for password
    QRegExp passRegExp("[0-9a-zA-Z]{4,20}");
    ui->passwordInput->setValidator(new QRegExpValidator(passRegExp,this));

    //connecting input lines with activation of registration button
    connect(ui->surnameInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->nameInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->fatherNameInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->ageInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->phoneInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->adressInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->loginInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));
    connect(ui->passwordInput,SIGNAL(textChanged(QString)),this,SLOT(registrationButtonEnable()));


    //registration after pressing registraton button
    connect(ui->registerButton,SIGNAL(clicked(bool)),this,SLOT(registerClient()));
}

void RegistrationWindow::registerClient() {
    //checking if login is not unique

    if(base->isLoginUnique(ui->loginInput->text().toStdString()) == false) {
        ErrorWindow newWind(this,"Пользователь с таким логином уже существует");
        newWind.show();
        newWind.exec();
        return;
    }

    //if all is ok we can register
    if(isClientRegistration) {
        //transfering info from input lines to Client constructor and adding new client to base
        Client newClient(ui->surnameInput->text().toStdString(),
                         ui->nameInput->text().toStdString(),
                         ui->fatherNameInput->text().toStdString(),
                         ui->ageInput->text().toInt(),
                         ui->phoneInput->text().toStdString(),
                         ui->adressInput->text().toStdString(),
                         ui->loginInput->text().toStdString(),
                         ui->passwordInput->text().toStdString());
        base->addClient(&newClient);
    } else {
        //transfering info from input lines to Worker constructor and adding new worker to base
        Worker newWorker(ui->surnameInput->text().toStdString(),
                         ui->nameInput->text().toStdString(),
                         ui->fatherNameInput->text().toStdString(),
                         ui->ageInput->text().toInt(),
                         ui->phoneInput->text().toStdString(),
                         ui->adressInput->text().toStdString(),
                         ui->loginInput->text().toStdString(),
                         ui->passwordInput->text().toStdString());
        base->addWorker(&newWorker);
    }
    this->close();
}

void RegistrationWindow::registrationButtonEnable() {
    //checking if information is correct and activating registration button
    ui->registerButton->setEnabled(ui->surnameInput->hasAcceptableInput() &&
                                   ui->nameInput->hasAcceptableInput() &&
                                   ui->fatherNameInput->hasAcceptableInput() &&
                                   ui->ageInput->hasAcceptableInput() &&
                                   ui->phoneInput->hasAcceptableInput() &&
                                   ui->adressInput->hasAcceptableInput() &&
                                   ui->loginInput->hasAcceptableInput() &&
                                   ui->passwordInput->hasAcceptableInput());
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}
