#include "Item.h"

Item::Item() {
    number = 0;
    name = "Unknown";
    description = "A mysterious object that has no data.";

    pocketNumber = 0;
    maxInBag = 999;

    buyPrice = 0;
}


Item::~Item() {
}
int Item::getNumber() { return number; }
std::string Item::getName() { return name; }
std::string Item::getDescription() { return description; }
int Item::getPocketNumber() { return pocketNumber; }
int Item::getMaxNumber() { return maxInBag; }
int Item::getBuyPrice() { return buyPrice; }
int Item::getSellPrice() { return buyPrice/2; }
