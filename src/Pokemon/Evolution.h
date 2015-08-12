// Handles evolution structures

#ifndef POKEMON_EVOLUTION_H_
#define POKEMON_EVOLUTION_H_

// Defining the method types
// Evolution defines begin with "E_"
#define E_FRIENDSHIP_ANY	1
#define E_FRIENDSHIP_DAY	2
#define E_FRIENDSHIP_NIGHT	3
#define E_LEVEL_UP			4
#define E_TRADE_NO_ITEM		5
#define E_TRADE_WITH_ITEM	6
#define E_ITEM_USED			7
#define E_TRADE_ATK_UP		8
#define E_TRADE_ATK_EQ		9
#define E_TRADE_ATK_DOWN	10
#define E_PERSONALITY_VALUE	11
#define E_MAY_SPAWN_ADDIT	12
#define E_SPAWNED			13
#define E_BEAUTY			14

// Define the evolution data structure
struct evolutionDataStructure {
	uint16_t method;
	uint16_t parameter;
	uint16_t target;
};

#endif
