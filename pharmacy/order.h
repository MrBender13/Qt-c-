#ifndef ORDER_H
#define ORDER_H

#include <person.h>
#include "item.h"
#include <list>
#include <random>
#include <time.h>

class Order
{
private:
   std::string customerName;
   std::string customerSurname;
   std::string customerFathername;
   std::string customerPhone;
   std::string customerAdress;
   std::list<Item> items;
   int id;
   int amount;
public:
   Order() {};
   Order(std::string,std::string,std::string,std::string,std::string,std::list<Item>);
   std::string getCustomerName() const {return customerName;};
   std::string getCustomerSurname() const {return customerSurname;};
   std::string getCustomerFathername() const {return customerFathername;};
   std::string getCustomerPhone() const {return customerPhone;};
   std::string getCustomerAdress() const {return customerAdress;};
   int getId() const {return id;};
   std::list<Item> getItems() {return std::list<Item>(items);};
   int getItemsAmount() const {return items.size();};
   int getSum() const;
};

const int MAX_ID = 100000;

class noActiveOrders : std::exception {
public:
    std::string what() {return "Нет ни одного активного заказа";};
};

#endif // ORDER_H
