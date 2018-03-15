#ifndef WORKERMENU_H
#define WORKERMENU_H

#include <QDialog>
#include "database.h"
#include "registrationwindow.h"
#include "productsredactor.h"
#include "ordersviewwindow.h"
#include "errorwindow.h"

namespace Ui {
    class workerMenu;
}

class workerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit workerMenu(QWidget *parent = 0,DataBase* = nullptr,std::string = "");
    ~workerMenu();

private:
    Ui::workerMenu *ui;
    DataBase* base;
    std::string account;
private slots:
    void registerNewWorker();
    void productRedactorCall();
    void ordersViewCall();
};

#endif // WORKERMENU_H
