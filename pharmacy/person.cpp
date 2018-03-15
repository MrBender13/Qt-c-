#include "person.h"

Person::Person(std::string name,std::string surname,std::string fathername,int age,
               std::string phone,std::string adress,std::string login,std::string password) {
    this->name = name;
    this->surname = surname;
    this->fathername = fathername;
    this->age = age;
    this->phone = phone;
    this->adress = adress;
    this->login = login;
    this->password = password;
}
