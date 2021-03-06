#ifndef ITEM_ITEM_H_
#define ITEM_ITEM_H_

#include "../Defines.h"
#include "../Pokemon/Pokemon.h"

// Defining the bits for useability
#define ITEM_WORLD  1
#define ITEM_BATTLE 2
#define ITEM_TRANSPORT  3
#define ITEM_CAVE   4
#define ITEM_INSIDE 5
#define ITEM_BIKE   6
#define ITEM_BASE   7

#define ITEM_TRADEABLE 1
#define ITEM_HOLDABLE 2
#define ITEM_NATURAL 3
#define ITEM_SELLABLE 4


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

        unsigned char locationUseableData; // Stores different locations where the item can be used. See ITEM defines
        unsigned char itemAttributes;      // Stores bits about an items use, such as if it's natural, holdable, etc

        unsigned char flingDamage;
        unsigned int flingEffect; // Need to get this structure figured out
        unsigned char itemType;
        
        // Berry-specific attributes
        unsigned char naturalGiftType;
        unsigned char naturalGiftPower;
        unsigned char color;
        unsigned char hoursToGrow;
        unsigned char minYield_maxYield;
        unsigned char contestType;
        unsigned char pokeblockRarity;
        unsigned char firmness;
        unsigned char size;
        unsigned char smoothness;
        std::vector<unsigned char> tastes;

        // Battle Effect Item-specific attributes
        std::vector<char> statRaised_BattleEffect;
        // Vitamin-specific attributes
        std::vector<char> statRaised_Vitamin;

        // Fossil-specific attributes
        int revivedPokemonNumber;

        // Recovery-specific attributes
        int deltaHP;
        double deltaHP_percent;
        unsigned char statusHealed;
        char deltaFriendship;

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
        int getItemType();
        int getMaxNumber();
        int getBuyPrice();
        int getSellPrice();
        // LocationUseableData accessors
        bool isUseableBattle();
        bool isUseableOverworld();
        bool isUseableCave();
        bool isUseableInside();
        bool isUseableBigTransport();
        bool isUseableSmallTransport();
        bool isUseableInBase();
        // ItemAtributes accessors
        bool isTradeable();
        bool isHoldable();
        bool isNatural();
        bool isSellable();
        // Fling data accessors
        unsigned char getFlingDamage();
        unsigned char getFlingEffect();
        // Berry accessors
        unsigned char getNaturalGiftType();
        unsigned char getNaturalGiftPower();
        unsigned char getBerryColor();
        unsigned char getHoursToGrow();
        unsigned char getMinYield();
        unsigned char getMaxYield();
        unsigned char getContestType();
        unsigned char getPokeblockRarity();
        unsigned char getBerryFirmness();
        unsigned char getBerrySize();
        std::vector<unsigned char> getBerryTaste();
        unsigned char getBerryTaste(unsigned char taste);
        unsigned char getBerryMaxTaste();
        unsigned char getBerrySmoothness();
        // Battle Effect Accessors
        std::vector<char> getStatRaised_battleEffect();
        char getStatRaised_battleEffect(int stat);
        // Vitamin attributes accessors
        std::vector<char> getStatRaised_vitamin();
        char getStatRaised_vitamin(int stat);
        // Fossil value accessors
        int getPokemonRaised();
        // HP and status affection accessors
        int getDeltaHP();
        int getDeltaHP_percent();
        char getDeltaFriendship();
        unsigned char getStatusHealed();
};

#endif
