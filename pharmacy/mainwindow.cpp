#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //trying to create data base
    try {
        base = new DataBase;
    } catch(missingFile err) {
        ErrorWindow wind(this, err.what());
        wind.show();
        wind.exec();
        throw missingFile();
    }

    //at first "in" button should be disabled
    ui->inButton->setEnabled(false);
    //connect registration button and registration window
    connect(ui->registrationButton,SIGNAL(clicked(bool)),this,SLOT(callRegistrationWindow()));
    //setting regular expressions for login and password
    QRegExp logRegExp("[0-9A-Za-z_]{3,15}");
    QRegExp passRegExp("[0-9a-zA-Z]{4,20}");
    ui->loginInput->setValidator(new QRegExpValidator(logRegExp,this));
    ui->passwordInput->setValidator(new QRegExpValidator(passRegExp,this));
    //connecting input button and menu
    connect(ui->inButton,SIGNAL(clicked(bool)), this, SLOT(enter()));
    //connecting input fields with enter button activation
    connect(ui->loginInput,SIGNAL(textChanged(QString)),this,SLOT(enableEnterButton()));
    connect(ui->passwordInput,SIGNAL(textChanged(QString)),this,SLOT(enableEnterButton()));
}

void MainWindow::enableEnterButton() {
    ui->inButton->setEnabled(ui->loginInput->hasAcceptableInput() &&
                             ui->passwordInput->hasAcceptableInput());
}

void MainWindow::enter(){
    //checking if base has account with such login and passwor, if yes - open worker/client menu
    if(ui->loginInput->hasAcceptableInput() && ui->passwordInput->hasAcceptableInput()) {
        int result = base->isCorrect(ui->loginInput->text().toStdString(),ui->passwordInput->text().toStdString());
        if(result == NOT_FOUND) {
            ErrorWindow newWind(this,"Неверный логин или пароль!");
            newWind.show();
            newWind.exec();
            return;
        } else if (result == WORKER) {
            //open worker menu
            workerMenu newWind(this,base,ui->loginInput->text().toStdString());
            newWind.show();
            newWind.exec();
        } else {
            //open client menu
            ClientMenu newWind(this,base,ui->loginInput->text().toStdString());
            newWind.show();
            newWind.exec();
        }
    }
}

void MainWindow::callRegistrationWindow() {
    //call registration window to registrate new client
    bool registerClient = true;
    RegistrationWindow newWind(this, base, registerClient);
    newWind.show();
    newWind.exec();
}

MainWindow::~MainWindow()
{
    delete base;
    delete ui;
}
