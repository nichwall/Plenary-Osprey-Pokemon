#include "Item.h"

Item::Item() {
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

unsigned char Item::getFlingDamage()    { return flingDamage; }
unsigned char Item::getFlingEffect()    { return flingEffect; }

unsigned char Item::getNaturalGiftType()  { return naturalGiftType;   }
unsigned char Item::getNaturalGiftPower() { return naturalGiftPower;  }
unsigned char Item::getBerryColor()       { return color;             }
unsigned char Item::getHoursToGrow()      { return hoursToGrow;       }
unsigned char Item::getMinYield()         { return minYield_maxYield; }
unsigned char Item::getMaxYield()         { return minYield_maxYield; }
unsigned char Item::getContestType()      { return contestType;       }
unsigned char Item::getPokeblockRarity()  { return pokeblockRarity;   }
unsigned char Item::getBerryFirmness()    { return firmness;          }
unsigned char Item::getBerrySize()        { return size;              }
//unsigned char[5] Item::getBerryTaste()    {}
unsigned char Item::getBerryTaste(unsigned char taste)    { return tastes[taste]; }
unsigned char Item::getBerryMaxTaste() {
    unsigned char max = 0; // Max value
    unsigned char t = 0;   // Taste with max value
    for (int i=0; i<5; i++) {
        if (tastes[i] > max) {
            max = tastes[i];
            t = i;
        }
    }
    return t;
}
unsigned char Item::getBerrySmoothness()  { return smoothness;        }
