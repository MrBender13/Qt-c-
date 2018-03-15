#ifndef ITEM_H
#define ITEM_H

#include<string>

class Item
{
private:
    std::string name;
    int prise;
    int amount;
    std::string author;
public:
    Item() {};
    Item(std::string,int,int,std::string);
    Item(const Item&);
    ~Item() {};
    std::string getName() const {return name;};
    int getPrise() const {return prise;};
    int getAmount() const {return amount;};
    std::string getAuthor() const {return author;};
    void increaseAmount(int);
    void decreaseAmount(int);
    void setAmount(int n) {amount = n;};

};

class lackOfItems : std::exception {
  public:
    std::string what() {return "Недостаточно товара на складе";};
};

#endif // ITEM_H
