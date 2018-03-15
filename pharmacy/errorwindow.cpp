#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent, std::string mes) :
    QDialog(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
    ui->errorMessage->setText(QString::fromStdString(mes));
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}
