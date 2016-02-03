/* Manages Pokemon classes */

#ifndef POKEMON_POKEMON_H_
#define POKEMON_POKEMON_H_

#include "../Language/Language.h"
#include "Type/Type.h"
#include "Move/Move.h"

// Define the evolution data structure
struct evolutionDataStructure {
	uint16_t method;
	uint16_t parameter;
	uint16_t target;
};
struct natureEffectStructure {
	char raised;
	char lowered;
};

// Defines every Pokemon, but just what is required to define one
class BasePokemon {
	private:
		// Pokemon name
		std::string pokemonName;
		int16_t pokedexNumber;
		int16_t nationalPokedexNumber;
		// Species
		std::string species;
		// Types of the Pokemon
		int8_t type1;
		int8_t type2;
		// Evolution structs
		std::vector<evolutionDataStructure> evolutions;
		// EV Yeild
		std::array<int8_t, 6> evYeild;
		uint32_t experienceYield;
		// Base stats
		std::array<uint8_t, 6> baseStats;
		// Level up rate
		int8_t levelUpEquation;
		// Egg Group
		int8_t eggGroup1;
		int8_t eggGroup2;
		// Move structs
		std::vector<learnMoveDataStruct> learnableMoves;
		// Gender ratio
		uint8_t genderRatio;
		// Hatch time/Egg cycles
		uint8_t eggCycles;
		// Height and Weight
		uint8_t heightAndWeight;
		// Body Style
		uint8_t bodyStyle;
		// Pokedex Color
		uint8_t pokedexColor;
		// Base Friendship
		uint8_t baseFriendship;
		// Abilities Structs
		
	public:
		// Constructors
		BasePokemon();
		BasePokemon(std::string name, int16_t regionNum, int16_t nationalNum, std::string p_species, int8_t firstType, int8_t secondType,
					std::vector<evolutionDataStructure> p_evolutions, std::array<int8_t, 6> evYeilds, uint32_t xpYeild,
					std::array<uint8_t, 6> p_baseStats, int8_t growthRate, int8_t p_eggGroup1, int8_t p_eggGroup2,
					std::vector<learnMoveDataStruct> p_learnableMoves, uint8_t p_genderRatio, uint8_t p_eggCycles,
					uint32_t p_HeightAndWeight, uint8_t p_bodyStyle, uint8_t p_pokedexColor, uint8_t p_baseFriend);
		~BasePokemon();

		// Accessors
		inline std::string getPokemonName()        { return pokemonName; }
		inline int16_t getRegionalPokedexNumber()  { return pokedexNumber; }
		inline int16_t getNationalPokedexNumber()  { return nationalPokedexNumber; }
		inline std::string getPokemonSpecies()     { return species; }
		inline int8_t getFirstType()       { return type1; }
		inline int8_t getSecondType()      { return type2; }
		inline std::vector<evolutionDataStructure> getEvolutions() { return evolutions; }
		inline std::array<int8_t, 6> getEvYeild()    { return evYeild; }
		inline int8_t getEvYeild(int stat)           { return evYeild[stat]; }
		inline uint32_t getXpYeild()                 { return experienceYield; }
		inline std::array<uint8_t, 6> getBaseStats() { return baseStats; }
		inline uint8_t getBaseStats(int stat)        { return baseStats[stat]; }
		inline int8_t getGrowthRate()                { return levelUpEquation; }
		inline std::array<int8_t, 2> getEggGroups();
		inline int8_t getFirstEggGroup()   { return eggGroup1; }
		inline int8_t getSecondEggGroup()  { return eggGroup2; }
		inline std::vector<learnMoveDataStruct> getLearnableMoves() { return learnableMoves; }
		//int canLearn(BaseMove& move);
		inline uint8_t getGenderRatio()        { return genderRatio; }
		inline uint8_t getBaseEggCycleCount()  { return eggCycles;   }
		inline uint8_t getHeight()     { return heightAndWeight / 65536; }
		inline uint8_t getWeight()     { return heightAndWeight % 65536; }
		inline uint8_t getBodyStyle()  { return bodyStyle; }
		inline uint8_t getPokedexColor()           { return pokedexColor; }
		inline uint8_t getBaseFriendship()   { return baseFriendship; }
		//Abilites Accessor!
		
		// Modifiers
		// None included so far
};

// Defines Pokemon that have been caught, extends base
class BoxPokemon: public BasePokemon {
	private:
		BasePokemon base;
		// Nickname, if applicable
		std::string nickname;
		// Trainer data
		int32_t trainerID;
		int32_t secretTrainerID;
		// IVs, egg, and ability number
		uint32_t ivs;
		// EVs gained
		std::array<uint8_t, 6> evs;
		// Experience
		uint32_t experience;
		// Personality Value
		uint32_t personalityValue;
		// Moves
		std::array<LearnedMove, 4> moves;
		// Held item
		uint16_t heldItem;
		// Friendship, or remaining egg cycles for egg
		uint8_t friendship;
		// Contest stats
		std::array<unsigned char, 6> contestStats;
		// Pokerus
		uint8_t pokerusStatus;
		// Pokemon origin
		uint32_t pokemonOrigin;
		// Ribbons
		uint32_t ribbons;
		// Markings
		uint8_t markings;
	public:
		// 
		BoxPokemon();
		BoxPokemon(BasePokemon pokemon, std::string nick, unsigned int p_ivs, std::array<unsigned char, 6> p_evs, unsigned int p_xp,
				   unsigned int p_personalityValue, std::array<LearnedMove, 4> p_moves, uint16_t p_heldItem, unsigned char p_friendship,
				   std::array<unsigned char, 6> p_contestStats, unsigned char p_pokerus, unsigned int origin,
				   unsigned int p_ribbons, unsigned char p_markings);
		// Accessors
		BasePokemon getBase()       { return base; }
		std::string getNickname()   { return nickname; }
		uint32_t get_ivs()          { return ivs; }
		uint8_t get_iv(unsigned int stat);
		std::array<uint8_t, 6> get_evs()   { return evs; }
		uint8_t get_evs(unsigned int stat) { return evs[stat]; }
		uint16_t get_stat(char stat);
		uint32_t get_experience() { return experience; }
		uint32_t get_level();
		
		uint32_t getPersonalityValue() { return personalityValue; }
		char isMale();
        char isFemale();
		// Ability * getAbility();
		char getNature() { return personalityValue%25; }
		natureEffectStructure getNatureEffect(char nature);
		double getNatureEffect(char nature, char stat);
		char getShinyness();
		char getCharacteristic();
		char getSize();
		
		std::array<LearnedMove, 4> getMoves()   { return moves; }
		LearnedMove getMove(unsigned int moveIndex) { return moves[moveIndex]; }
		uint16_t getHeldItem()          { return heldItem; }
		unsigned char getFriendship()   { return friendship; }
		std::array<unsigned char, 6> getContestStats()  { return contestStats; }
		unsigned char getPokerusStatus();
		unsigned char getPokerusStrain();
		unsigned char getPokerusRemaining();
		int isInfectedPokerus();
		int isCuredPokerus();
		unsigned int getOrigin()    { return pokemonOrigin; }
		
		unsigned int getRibbons()   { return ribbons; }
		unsigned char getMarkings() { return markings; }
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
        // Pokerus Data
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
		BoxPokemon box;
		// Battle stat info
		unsigned char level;
		std::array<uint16_t, 6> stats;
		// Current HP
		int currentHP;
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
		PartyPokemon(BoxPokemon box, unsigned char statCondition);
		PartyPokemon(BoxPokemon box, int cHP);
		PartyPokemon(BoxPokemon box, int cHP, unsigned char statCondition);
		// Get the level
		//BoxPokemon * getBox();
        BoxPokemon getBox();
		unsigned char getLevel();
		int getHP();
		unsigned char getStatusCondition();
		// Reload things
		void reloadLevel();
		void reloadStats();
		int deltaHealth(int delta);
		int updateStatusCondition();
		void clearStatusCondition();
};

// Defines Pokemon in battle, extends party
class BattlePokemon: public PartyPokemon {
	private:
		PartyPokemon party;
	public:
		// Constructors
		BattlePokemon();
		BattlePokemon(PartyPokemon pokemon);
		// Accessors
		//PartyPokemon * getParty();
        PartyPokemon getPart();
};

#endif
