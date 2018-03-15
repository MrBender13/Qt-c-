#include "database.h"

DataBase::DataBase() {
    std::string name, surname, fatherName, phone, adress, login, password,house;
    int age;
       
    //getting workers from file
    std::ifstream fin("workers.txt");
    if (!fin.is_open()) throw missingFile();
    while (!fin.eof())
    {
        fin >> surname >> name >> fatherName >> age >> phone >> adress >> house >> login >> password;
        Worker newWorker(surname, name, fatherName, age, phone, adress + " " + house, login, password);
        workers.push_back(newWorker);
    }
    fin.close();
       
    //getting clients from file
    fin.open("clients.txt");
    if (!fin.is_open()) throw missingFile();
    while (!fin.eof())
    {
        fin >> surname >> name >> fatherName >> age >> phone >> adress >> house >> login >> password;
        Client newClient(surname, name, fatherName, age, phone, adress + " " + house, login, password);
        clients.push_back(newClient);
    }
    fin.close();
       
    //getting products from file
    std::string type;
    int prise,amount;
    fin.open("products.txt");
    if (!fin.is_open()) throw missingFile();
    while (!fin.eof())
    {
        fin >> name >> prise >> amount >> type;
        Item newItem(name, prise, amount, type);
        items.push_back(newItem);
    }
    fin.close();

    //getting orders from file
    int id,itemPrise,itemAmount;
    std::string itemName;
    fin.open("orders.txt");
    if (!fin.is_open()) throw missingFile();
    while(!fin.eof()) {
        fin >> id >> surname >> name >> fatherName >> phone >> adress >> house >> amount;
        std::list<Item> newList;
        for(int i = 0; i < amount;i++) {
            fin >> itemName >> itemPrise >> itemAmount;
            //empty string indead of author of product
            Item newItem(itemName,itemPrise,itemAmount,"");
            newList.push_back(newItem);
        }
        Order newOrder(name,surname,fatherName,phone,adress+" " +house,newList);
        orders.push_back(newOrder);
    }
}

DataBase::~DataBase() {
    //saving clients into the file
    std::ofstream fout("clients.txt");
    if (!fout.is_open()) throw missingFile();
    for(std::list<Client>::iterator it = clients.begin(); it != clients.end();) {
        fout << it->getName() << " " << it->getSurname() << " " << it->getFathername() << " ";
        fout << it->getAge() << " " << it->getPhone() << " " << it->getAdress() << " ";
        fout << it->getLogin() << " " << it->getPassword();
        if(++it != clients.end()) {
            fout << "\n";
        }
    }
    fout.close();

    //saving workers to the file
    fout.open("workers.txt");
    if (!fout.is_open()) throw missingFile();
    for(std::list<Worker>::iterator it = workers.begin(); it != workers.end();) {
        fout << it->getName() << " " << it->getSurname() << " " << it->getFathername() << " ";
        fout << it->getAge() << " " << it->getPhone() << " " << it->getAdress() << " ";
        fout << it->getLogin() << " " << it->getPassword();
        if(++it != workers.end()) {
            fout << "\n";
        }
    }
    fout.close();

    //saving products into the file
    fout.open("products.txt");
    if (!fout.is_open()) throw missingFile();
    for(std::list<Item>::iterator it = items.begin(); it != items.end();) {
        fout << it->getName() << " " << it->getPrise() << " " << it->getAmount() << " " << it->getAuthor();
        if(++it != items.end()) {
            fout << "\n";
        }
    }
    fout.close();

    //saving orders into the file
    fout.open("orders.txt");
    if(!fout.is_open()) throw missingFile();
    for(std::list<Order>::iterator it = orders.begin(); it != orders.end();) {
        fout << it->getId() << " " << it->getCustomerSurname() << " " << it->getCustomerName() << " ";
        fout << it->getCustomerFathername() << " " << it->getCustomerPhone() << " ";
        fout << it->getCustomerAdress() << " " << it->getItemsAmount() << " ";
        std::list<Item> crtList = it->getItems();
        for(std::list<Item>::iterator crt = crtList.begin(); crt != crtList.end();) {
            fout << crt->getName() << " " << crt->getPrise() << " " << crt->getAmount();
            if(++crt != crtList.end()) {
                fout << " ";
            }
        }
        if(++it != orders.end()) {
            fout << "\n";
        }
    }
}

std::list<Order> DataBase::getClientOrders(std::string phone) const{
    std::list<Order> result;
    for(auto it : orders) {
        if(it.getCustomerPhone() == phone) {
            result.push_back(Order(it));
        }
    }
    return result;
}

void DataBase::addClient(Client* newClient) {
    clients.push_back(*newClient);
}

void DataBase::addWorker(Worker* newWorker) {
    workers.push_back(*newWorker);
}

bool DataBase::isLoginUnique(std::string toCheck) const {
    for(auto it : clients) {
        if(it.getLogin() == toCheck) return false;
    }
    for(auto it : workers) {
        if(it.getLogin() == toCheck) return false;
    }
    return true;
}

int DataBase::isCorrect(std::string login,std::string password) const {
    for (auto it : clients) {
        if(it.getLogin() == login && it.getPassword() == password) return CLIENT;
    }
    for (auto it : workers) {
        if(it.getLogin() == login && it.getPassword() == password) return WORKER;
    }
    return NOT_FOUND;
}

std::list<Item> DataBase::getItems() const {
    return std::list<Item>(items);
}

bool DataBase::hasItem(std::string name) const {
    for(auto it : items) {
        if(it.getName() == name) return true;
    }
    return false;
}

void DataBase::addItem(Item* newItem) {
    if(this->hasItem(newItem->getName())) throw notUniqueItem();
    items.push_back(*(newItem));
}

void DataBase::delItem(std::string name) {
    for(std::list<Item>::iterator it = items.begin();it != items.end();++it) {
        if(it->getName() == name) {
            items.erase(it);
            return;
        }
    }
}

void DataBase::increaseItemAmount(std::string name,int amount) {
//    for(auto it : items) {
//        if(it.getName() == name) {
//            it.increaseAmount(amount);
//            return;
//        }
//    }
    for(std::list<Item>::iterator it = items.begin();it != items.end();++it) {
        if(it->getName() == name) {
            it->increaseAmount(amount);
            return;
        }
    }
    throw itemNotFound();
}

void DataBase::decreaseItemAmount(std::string name,int amount) {
    for(std::list<Item>::iterator it = items.begin();it != items.end();++it) {
        if(it->getName() == name) {
            it->decreaseAmount(amount);
            return;
        }
    }
    throw itemNotFound();
}

bool DataBase::isItemsEmpty() const {
    return items.size() > 0 ? true : false;
}

Client* DataBase::getClientByLogin(std::string login) const {
    for(auto it : clients) {
        if(it.getLogin() == login) {
            return new Client(it);
        }
    }
    return nullptr;
}

Item* DataBase::getItemByName(std::string name) const {
    for(auto it : items) {
        if(it.getName() == name) {
            return new Item(it);
        }
    }
    return nullptr;
}

void DataBase::addOrder(Order* newOrder) {
    orders.push_back(*newOrder);
}

std::list<Order> DataBase::getOrders() const{
    return std::list<Order>();
}
