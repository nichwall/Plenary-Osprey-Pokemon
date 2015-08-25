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
		std::array<char, 6> evYeild;
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
		unsigned char eggCycles;
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
					std::vector<evolutionDataStructure> p_evolutions, std::array<char, 6> evYeilds, unsigned int xpYeild,
					std::array<unsigned char, 6> p_baseStats, char growthRate, char p_eggGroup1, char p_eggGroup2,
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
		//Abilites Accessor!
		
		// Modifiers
		// None included so far
};

// Defines Pokemon that have been caught, extends base
class BoxPokemon: public BasePokemon {
	private:
		BasePokemon * base;
		// Nickname, if applicable
		std::string nickname;
		// IVs, egg, and ability number
		unsigned int ivs;
		// EVs gained
		std::array<unsigned char, 6> evs;
		// Experience
		unsigned int experience;
		// Personality Value
		unsigned int personalityValue;
		// Moves
		std::array<LearnedMove, 4> moves;
		// Held item
		uint16_t heldItem;
		// Friendship, or remaining egg cycles for egg
		unsigned char friendship;
		// Contest stats
		std::array<unsigned char, 6> contestStats;
		// Pokerus
		unsigned char pokerusStatus;
		// Pokemon origin
		unsigned int pokemonOrigin;
		// Ribbons
		unsigned int ribbons;
		// Markings
		unsigned char markings;
	public:
		// Constructors
		BoxPokemon();
		BoxPokemon(BasePokemon pokemon, std::string nick, unsigned int p_ivs, std::array<unsigned char, 6> p_evs, unsigned int p_xp,
				   unsigned int p_personalityValue, std::array<LearnedMove, 4> p_moves, uint16_t p_heldItem, unsigned char p_friendship,
				   std::array<unsigned char, 6> p_contestStats, unsigned char p_pokerus, unsigned int origin,
				   unsigned int p_ribbons, unsigned char p_markings);
		// Accessors
		BasePokemon * getBase();
		std::string getNickname();
		unsigned int get_ivs();
		unsigned char get_iv(unsigned int stat);
		std::array<unsigned char, 6> get_evs();
		unsigned char get_evs(unsigned int stat);
		int get_stat(char stat);
		unsigned int get_experience();
		unsigned int get_level();
		unsigned int getPersonalityValue();
		char isMale();
		// Ability * getAbility();
		char getNature();
		char getShinyness();
		char getCharacteristic();
		
		std::array<LearnedMove, 4> getMoves();
		LearnedMove getMove(unsigned int moveIndex);
		uint16_t getHeldItem();
		unsigned char getFriendship();
		std::array<unsigned char, 6> getContestStats();
		unsigned char getPokerusStatus();
		unsigned char getPokerusStrain();
		unsigned char getPokerusRemaining();
		int isInfectedPokerus();
		int isCuredPokerus();
		unsigned int getOrigin();
		
		unsigned int getRibbons();
		unsigned char getMarkings();
		int hasMarking(unsigned int mark);
		// Modifiers
		int setNickname(std::string nick);
		int shuffleIVs();
		int deltaEV(unsigned char stat, char delta);
		int setXP(unsigned int newXP);
		int deltaXP(int delta);
		int setMove(LearnedMove move, int index);
		int deltaFriendship(char delta);
		uint16_t takeItem();
		int giveItem(uint16_t item);
		uint16_t swapItem(uint16_t newItem);
		int deltaContestStats(std::array<unsigned char, 6> deltas);
		int deltaContestStat(char delta, int stat);
		int setContestStats(std::array<unsigned char, 6> newStats);
		int setContestStat(unsigned char statValue, int stat);
		int pokerusAged();
		int setPokerusStrain(unsigned char strain);
		int setPokerusDuration(unsigned char age);
		int setPokerusStatus(unsigned char pokerus);
		int addRibbon(unsigned int ribbon);
		int removeRibbon(unsigned int ribbon);
		int addMarking(unsigned char mark);
		int removeMarking(unsigned char mark);
};

// Defines Pokemon in the party, extends box
class PartyPokemon: public BoxPokemon {
	private:
		BoxPokemon * box;
		// Battle stat info
		unsigned char level;
		std::array<uint16_t, 6> stats;
		// Current HP
		unsigned int currentHP;
		// Status condition
		/*
		 * In order to store sleep remaining, bits 0-2 are turns remaining
		 * Poison, Burn, Freeze, Paralysis follow
		 * 7 is used to denote nothing, as BadPoison will take that spot in Battle
		 */
		unsigned char statusCondition;
		
	public:
		// Constructors
		PartyPokemon();
		PartyPokemon(BoxPokemon box);
};

// Defines Pokemon in battle, extends party
class BattlePokemon: public PartyPokemon {
	private:
		
	public:
		
};

#endif
