#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database.h>
#include <errorwindow.h>
#include <registrationwindow.h>
#include <workermenu.h>
#include <clientmenu.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DataBase* base;

private slots:
    void callRegistrationWindow();
    void enter();
    void enableEnterButton();
};

#endif // MAINWINDOW_H
