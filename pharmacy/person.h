#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
protected:
    std::string name;
    std::string surname;
    std::string fathername;
    int age;
    std::string adress;
    std::string phone;
    std::string login;
    std::string password;
public:
    Person(){};
    Person(std::string,std::string,std::string,int,std::string,std::string,std::string,std::string);
    std::string getName() const {return name;};
    std::string getSurname() const {return surname;};
    std::string getFathername() const {return fathername;};
    int getAge() const {return age;};
    std::string getAdress() const {return adress;};
    std::string getLogin() const {return login;};
    std::string getPassword() const {return password;};
    std::string getPhone() const {return phone;};
    virtual bool isWorker() const = 0;
};

#endif // PERSON_H
