#ifndef DATABASE_H
#define DATABASE_H

#include "worker.h"
#include "client.h"
#include "item.h"
#include <list>
#include <fstream>
#include <string>
#include "order.h"

class DataBase
{
private:
    std::list<Worker> workers;
    std::list<Client> clients;
    std::list<Item> items;
    std::list<Order> orders;
public:
    DataBase();
    ~DataBase();
    void addClient(Client*);
    void addWorker(Worker*);
    bool isLoginUnique(std::string) const;
    int isCorrect(std::string,std::string) const;
    std::list<Item> getItems() const;
    void addItem(Item*);
    void delItem(std::string);
    bool hasItem(std::string) const;
    void increaseItemAmount(std::string,int);
    void decreaseItemAmount(std::string,int);
    bool isItemsEmpty() const;
    Client* getClientByLogin(std::string) const;
    Item* getItemByName(std::string) const;
    void addOrder(Order*);
    std::list<Order> getClientOrders(std::string) const;
    std::list<Order> getOrders() const;
};

const int NOT_FOUND = 0;
const int WORKER = 1;
const int CLIENT = 2;

class itemNotFound : std::exception {
public:
    std::string what() {return "Элемент не найден!";};
};

class notUniqueItem : std::exception {
public:
    std::string what() {return "Товар с данным именем уже существует, для добавления его на склад используйте редактор!";};
};

class missingFile : std::exception {
public:
    std::string what() {return "Добавьте файлы с данными в папку программы";};
};

#endif // DATABASE_H
