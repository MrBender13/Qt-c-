#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include <item.h>
#include <list>

class Client : public Person
{
private:
    std::list<Item> basket;
public:
    bool isWorker() const {return false;};
    Client() {};
    Client(const Client&);
    Client(std::string,std::string,std::string,int,std::string,std::string,std::string,std::string);
    void addToBasket(Item*);
    void delFromBasket(std::string);
    int getItemAmoutByName(std::string);
    std::list<Item> getBasket() const;
    int isBasketEmpty() const {return basket.empty() == 0 ? true : false;};
    int getBasketSum() const;
    void freeBasket();
};

#endif // CLIENT_H
