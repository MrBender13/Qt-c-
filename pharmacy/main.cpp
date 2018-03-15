#include "mainwindow.h"
#include <QApplication>
#include <database.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        MainWindow w;
        w.show();
        return a.exec();
    } catch(missingFile err) {

    };
    return 0;
}
