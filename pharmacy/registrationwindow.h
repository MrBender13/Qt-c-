#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <database.h>
#include <errorwindow.h>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = 0,DataBase* = nullptr, bool = 1);
    ~RegistrationWindow();

private:
    Ui::RegistrationWindow *ui;
    DataBase* base;
    bool isClientRegistration;

 private slots:
    void registrationButtonEnable();
    void registerClient();
};

#endif // REGISTRATIONWINDOW_H
