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
int Item::getNumber()               { return number;        }
std::string Item::getName()         { return name;          }
std::string Item::getDescription()  { return description;   }
int Item::getPocketNumber()         { return pocketNumber;  }
int Item::getItemType()             { return itemType;      }
int Item::getMaxNumber()            { return maxInBag;      }
int Item::getBuyPrice()             { return buyPrice;      }
int Item::getSellPrice()            { return buyPrice/2;    }
bool Item::isUseableBattle()        { return ((locationUseableData >> ITEM_BATTLE)    & 1); }
bool Item::isUseableOverworld()     { return ((locationUseableData >> ITEM_WORLD)     & 1); }
bool Item::isUseableCave()          { return ((locationUseableData >> ITEM_CAVE)      & 1); }
bool Item::isUseableInside()        { return ((locationUseableData >> ITEM_INSIDE)    & 1); }
bool Item::isUseableBigTransport()  { return ((locationUseableData >> ITEM_TRANSPORT) & 1); }
bool Item::isUseableSmallTransport(){ return ((locationUseableData >> ITEM_BIKE)      & 1); }
bool Item::isUseableInBase()        { return ((locationUseableData >> ITEM_BASE)      & 1); }
bool Item::isTradeable()            { return ((itemAttributes >> ITEM_TRADEABLE) & 1); }
bool Item::isHoldable()             { return ((itemAttributes >> ITEM_HOLDABLE)  & 1); }
bool Item::isNatural()              { return ((itemAttributes >> ITEM_NATURAL)   & 1); }
bool Item::isSellable()             { return ((itemAttributes >> ITEM_SELLABLE)  & 1); }
