#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include <QDialog>
#include "database.h"
#include "productswiewwindow.h"
#include "basketviewwindow.h"
#include "myorderswindow.h"
#include "errorwindow.h"

namespace Ui {
class ClientMenu;
}

class ClientMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ClientMenu(QWidget *parent = 0,DataBase* = nullptr,std::string = "");
    ~ClientMenu();

private:
    Ui::ClientMenu *ui;
    DataBase* base;
    Client* crtClient;

private slots:
    void callProductsView();
    void callBasketView();
    void callOrdersView();
};

#endif // CLIENTMENU_H
