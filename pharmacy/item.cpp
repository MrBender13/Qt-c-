#include "item.h"

Item::Item(const Item &toCopy) {
    this->name = toCopy.getName();
    this->prise = toCopy.getPrise();
    this->amount = toCopy.getAmount();
    this->author = toCopy.getAuthor();
}

Item::Item(std::string name,int prise, int amount,std::string author)
{
    this->name = name;
    this->prise = prise;
    this->amount = amount;
    this->author = author;
}

void Item::increaseAmount(int numb) {
    amount += numb;
}

void Item::decreaseAmount(int numb) {
    if(numb > amount) throw lackOfItems();
    amount -= numb;
}
