#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T18:08:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pharmacy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    registrationwindow.cpp \
    person.cpp \
    item.cpp \
    database.cpp \
    worker.cpp \
    client.cpp \
    errorwindow.cpp \
    workermenu.cpp \
    productsredactor.cpp \
    addingproductwindow.cpp \
    clientmenu.cpp \
    productswiewwindow.cpp \
    order.cpp \
    basketviewwindow.cpp \
    myorderswindow.cpp \
    ordersviewwindow.cpp

HEADERS += \
        mainwindow.h \
    registrationwindow.h \
    person.h \
    item.h \
    database.h \
    worker.h \
    client.h \
    errorwindow.h \
    workermenu.h \
    productsredactor.h \
    addingproductwindow.h \
    clientmenu.h \
    productswiewwindow.h \
    order.h \
    basketviewwindow.h \
    myorderswindow.h \
    ordersviewwindow.h

FORMS += \
        mainwindow.ui \
    registrationwindow.ui \
    errorwindow.ui \
    workermenu.ui \
    productsredactor.ui \
    addingproductwindow.ui \
    clientmenu.ui \
    productswiewwindow.ui \
    basketviewwindow.ui \
    myorderswindow.ui \
    ordersviewwindow.ui
