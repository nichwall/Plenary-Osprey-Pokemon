/* Manages Pokemon classes */

#ifndef POKEMON_POKEMON_H_
#define POKEMON_POKEMON_H_

#include "../Language/Language.h"
#include "../Type/Type.h"
#include "../Move/Move.h"

// Define the evolution data structure
struct evolutionDataStructure {
	uint16_t method;
	uint16_t parameter;
	uint16_t target;
};

// Defines every Pokemon, but just what is required to define one
class BasePokemon {
	private:
		// Pokemon name
		std::string pokemonName;
		int pokedexNumber;
		int nationalPokedexNumber;
		// Species
		std::string species;
		// Types of the Pokemon
		char type1;
		char type2;
		// Evolution structs
		std::vector<evolutionDataStructure> evolutions;
		// EV Yeild
		char evYeild [6];
		unsigned int experienceYield;
		// Base stats
		std::array<unsigned char, 6> baseStats;
		// Level up rate
		char levelUpEquation;
		// Egg Group
		char eggGroup1;
		char eggGroup2;
		// Move structs
		std::vector<learnMoveDataStruct> learnableMoves;
		// Gender ratio
		unsigned char genderRatio;
		// Hatch time/Egg cycles
		unsigned char eggCylces;
		// Height and Weight
		unsigned int heightAndWeight;
		// Body Style
		unsigned char bodyStyle;
		// Pokedex Color
		unsigned char pokedexColor;
		// Base Friendship
		unsigned char baseFriendship;
		// Abilities Structs
		
	public:
		// Constructors
		BasePokemon();
		BasePokemon(std::string name, int regionNum, int nationalNum, std::string p_species, char firstType, char secondType,
					std::vector<evolutionDataStructure> p_evolutions, std::vector<char> evYeilds, unsigned int xpYeild,
					std::vector<unsigned char> p_baseStats, char growthRate, char p_eggGroup1, char p_eggGroup2,
					std::vector<learnMoveDataStruct> p_learnableMoves, unsigned char p_genderRatio, unsigned char p_eggCycles,
					unsigned int p_HeightAndWeight, unsigned char p_bodyStyle, unsigned char p_pokedexColor, unsigned char p_baseFriend);
		
		// Accessors
		std::string getPokemonName();
		int getRegionalPokedexNumber();
		int getNationalPokedexNumber();
		std::string getPokemonSpecies();
		char getFirstType();
		char getSecondType();
		std::vector<evolutionDataStructure> getEvolutions();
		std::array<char, 6> getEvYeild();
		char getEvYeild(int stat);
		unsigned int getXpYeild();
		std::array<unsigned char, 6> getBaseStats();
		unsigned char getBaseStats(int stat);
		char getGrowthRate();
		std::array<char, 2> getEggGroups();
		char getFirstEggGroup();
		char getSecondEggGroup();
		std::vector<learnMoveDataStruct> getLearnableMoves();
		//int canLearn(BaseMove& move);
		unsigned char getGenderRatio();
		unsigned char getBaseEggCycleCount();
		unsigned char getHeight();
		unsigned char getWeight();
		unsigned char getBodyStyle();
		unsigned char getPokedexColor();
		unsigned char getBaseFriendship();
		
		// Modifiers
		// None included so far
};

// Defines Pokemon that have been caught, extends base
class BoxPokemon: public BasePokemon {
	private:
		BasePokemon& base;
		// Nickname, if applicable
		std::string nickname;
		// IVs, egg, and ability number
		unsigned int ivs;
		// EVs gained
		unsigned char evs [6];
		// Experience
		unsigned int experience;
		// Personality Value
		unsigned int personalityValue;
		// Moves
		LearnedMove moves [4];
		// Held item
		unsigned int heldItem;
		// Friendship
		unsigned char friendship;
		// Contest stats
		unsigned char contestStats [6];
		// Pokerus
		unsigned char pokerusStatus;
		// Pokemon origin
		unsigned int pokemonOrigin;
		// Ribbons
		unsigned int ribbons;
	public:
		
};

// Defines Pokemon in the party, extends box
class PartyPokemon: public BoxPokemon {
	private:
		
	public:
		
};

// Defines Pokemon in battle, extends party
class BattlePokemon: public PartyPokemon {
	private:
		
	public:
		
};

#endif
