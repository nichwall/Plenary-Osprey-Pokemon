#ifndef ITEM_ITEM_H_
#define ITEM_ITEM_H_

#include "../Defines.h"

// Defining the bits for useability
#define ITEM_WORLD  1
#define ITEM_BATTLE 2
#define ITEM_TRANSPORT  4
#define ITEM_CAVE   8
#define ITEM_INSIDE 16
#define ITEM_BIKE   32
#define ITEM_BASE   64


class Item {
    private:
        int number;
        std::string name;
        std::string description;
        // Bag data
        int pocketNumber;
        int maxInBag;
        // Sale
        int buyPrice;

        bool isTradable; // Can it be traded
        bool isNatural;  // Pokemon can use of own accord during battle?
        bool isHoldable; // Pokemon can hold?
        bool isSellable;

        bool useableInWorld;  // Ovenword stuff? Don't use things like X-Accuracy
        bool useableInBattle; // In battle? No bikes!
        bool useableOnTransport; // Trains, boats, etc. Might be cool to have planes
        bool useableInCave;  // Useable underground
        bool useableInside;  // In buildings?
        bool useableOnBike;  // On bike or during surf?
        bool useableInBase;  // Decorations? Won't be in bag, will be in special one
    public:
        // Constructor
        Item();
        // Destructor
        ~Item();
        //Accessors
        int getNumber();
        std::string getName();
        std::string getDescription();
        int getPocketNumber();
        int getMaxNumber();
        int getBuyPrice();
        int getSellPrice();
};

#endif
