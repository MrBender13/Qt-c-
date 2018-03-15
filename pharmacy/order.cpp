#include "order.h"

Order::Order(std::string name,std::string surname,std::string fathername,std::string phone,
             std::string adress,std::list<Item> items) {
    this->customerName = name;
    this->customerSurname = surname;
    this->customerFathername = fathername;
    this->customerPhone = phone;
    this->customerAdress = adress;
    this->items = items;
    this->id = std::rand() % MAX_ID;
    this->amount = items.size();
}

int Order::getSum() const {
    int sum = 0;
    for(auto it : items) {
        sum += it.getPrise() * it.getAmount();
    }
    return sum;
}
