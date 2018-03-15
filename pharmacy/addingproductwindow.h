#ifndef ADDINGPRODUCTWINDOW_H
#define ADDINGPRODUCTWINDOW_H

#include <QDialog>
#include <database.h>
#include <errorwindow.h>

namespace Ui {
class AddingProductWindow;
}

class AddingProductWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddingProductWindow(QWidget *parent = 0,DataBase* = nullptr,std::string = "");
    ~AddingProductWindow();

private:
    Ui::AddingProductWindow *ui;
    DataBase* base;
    std::string author;

private slots:
    void saveEnable();
    void addItem();
};

#endif // ADDINGPRODUCTWINDOW_H
