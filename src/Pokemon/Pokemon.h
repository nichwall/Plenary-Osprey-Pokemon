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
		virtual std::string getPokemonName();
		virtual int getRegionalPokedexNumber();
		virtual int getNationalPokedexNumber();
		virtual std::string getPokemonSpecies();
		virtual char getFirstType();
		virtual char getSecondType();
		virtual std::vector<evolutionDataStructure> getEvolutions();
		virtual std::array<char, 6> getEvYeild();
		virtual char getEvYeild(int stat);
		virtual unsigned int getXpYeild();
		virtual std::array<unsigned char, 6> getBaseStats();
		virtual unsigned char getBaseStats(int stat);
		virtual char getGrowthRate();
		virtual std::array<char, 2> getEggGroups();
		virtual char getFirstEggGroup();
		virtual char getSecondEggGroup();
		virtual std::vector<learnMoveDataStruct> getLearnableMoves();
		//int canLearn(BaseMove& move);
		virtual unsigned char getGenderRatio();
		virtual unsigned char getBaseEggCycleCount();
		virtual unsigned char getHeight();
		virtual unsigned char getWeight();
		virtual unsigned char getBodyStyle();
		virtual unsigned char getPokedexColor();
		virtual unsigned char getBaseFriendship();
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
		int trainerID;
		int secretTrainerID;
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
		//BasePokemon * getBase();
		virtual std::string getNickname();
		virtual unsigned int get_ivs();
		virtual unsigned char get_iv(unsigned int stat);
		virtual std::array<unsigned char, 6> get_evs();
		virtual unsigned char get_evs(unsigned int stat);
		virtual uint16_t get_stat(char stat);
		virtual unsigned int get_experience();
		virtual unsigned int get_level();
		
		virtual unsigned int getPersonalityValue();
		virtual char isMale();
		// Ability * getAbility();
		virtual char getNature();
		virtual natureEffectStructure getNatureEffect(char nature);
		virtual double getNatureEffect(char nature, char stat);
		virtual char getShinyness();
		virtual char getCharacteristic();
		virtual char getSize();
		
		virtual std::array<LearnedMove, 4> getMoves();
		virtual LearnedMove getMove(unsigned int moveIndex);
		virtual uint16_t getHeldItem();
		virtual unsigned char getFriendship();
		virtual std::array<unsigned char, 6> getContestStats();
		virtual unsigned char getPokerusStatus();
		virtual unsigned char getPokerusStrain();
		virtual unsigned char getPokerusRemaining();
		virtual int isInfectedPokerus();
		virtual int isCuredPokerus();
		virtual unsigned int getOrigin();
		
		virtual unsigned int getRibbons();
		virtual unsigned char getMarkings();
		virtual int hasMarking(unsigned int mark);
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
		virtual unsigned char getLevel();
		virtual int getHP();
		virtual unsigned char getStatusCondition();
		// Reload things
		virtual void reloadLevel();
		virtual void reloadStats();
		virtual int deltaHealth(int delta);
		virtual int updateStatusCondition();
		virtual void clearStatusCondition();
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
};

#endif
