#include "client.h"

Client::Client(const Client &toCopy) {
    this->name = toCopy.getName();
    this->surname = toCopy.getSurname();
    this->fathername = toCopy.getFathername();
    this->age = toCopy.getAge();
    this->phone = toCopy.getPhone();
    this->adress = toCopy.getAdress();
    this->login = toCopy.getLogin();
    this->password = toCopy.getPassword();
}

Client::Client(std::string name,std::string surname,std::string fathername,int age,
               std::string phone,std::string adress,std::string login,std::string password)
    : Person(name,surname,fathername,age,phone,adress,login,password){
}


void Client::freeBasket() {
    basket.clear();
}

int Client::getBasketSum() const {
    int sum = 0;
    for(auto it : basket) {
        sum += it.getPrise() * it.getAmount();
    }
    return sum;
}

int Client::getItemAmoutByName(std::string name) {
    for(std::list<Item>::iterator it = basket.begin();it != basket.end();++it) {
        if(it->getName() == name) {
            return it->getAmount();
        }
    }
}

void Client::addToBasket(Item* toAdd) {
    for(std::list<Item>::iterator it = basket.begin(); it != basket.end();++it) {
        if(it->getName() == toAdd->getName()) {
            it->increaseAmount(toAdd->getAmount());
            return;
        }
    }
    basket.push_back(*toAdd);
}

std::list<Item> Client::getBasket() const {
    return std::list<Item>(basket);
}

void Client::delFromBasket(std::string name) {
    for(std::list<Item>::iterator it = basket.begin(); it != basket.end();++it) {
        if(it->getName() == name) {
            basket.erase(it);
            return;
        }
    }
}
