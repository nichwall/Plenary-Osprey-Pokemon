#include <string>
#include "Move.h"
#include "Abilities.h"

class BasePokemon {
	private:
		/* Keep track of the pokedexNumbers.
		 * To get the national Pokedex number, mod by
		 * 2^16, and to get the local Pokedex number
		 * divide by 2^16. */
		unsigned int pokedexNumbers;
		
		std::string name;
		std::string flavorText;
		
		/* Contains the base stats of the Pokemon */
		int baseStats [6];
		unsigned char baseFriendship;
		
		/* Contains base stats for Pokeathalon 
		 * "Initial" is what they start at, and "max" is the highest
		 * the Pokemon can go through Aprijuice or natures
		 * 
		 * 0-4:		Speed initial
		 * 5-9:		Speed max
		 * 10-14:	Power initial
		 * 15-19:	Power max
		 * 20-24:	Skill initial
		 * 25-29:	Skill max
		 * 30-34:	Stamina initial
		 * 35-39:	Stamina max
		 * 40-44:	Jump initial
		 * 45-49:	Jump max
		 * 
		 * 50-74:	(total) initial
		 * 75-100:	(total) max
		 */
		unsigned char pokeathalonBaseStats;
		
		/* Yeilds from defeating this Pokemon */
		unsigned char evYield [6];
		unsigned int expYield;
		
		/* Typing of the Pokemon */
		unsigned char firstType;
		unsigned char secondType;
		
		/* Keeps track of the Pokemon's abilities.
		 * index 0 is the first slot,
		 * index 1 is the second slot,
		 * index 2 is the first hidden slot,
		 * index 3 is the second hidden slot 
		 */
		unsigned char abilities [4];
		
		/* Keep track of the moves the Pokemon can
		 * learn and when/how */
		std::vector<unsigned int> leveledMoves;
		std::vector<unsigned char> levelMoveLearned;
		std::vector<unsigned int> eggMoves;
		std::vector<unsigned int> tutoredMoves;
		
		/* Speed of Experience gain, possible values are
		 * 1:	Erratic
		 * 2:	Fast
		 * 3:	Medium Fast
		 * 4:	Medium Slow
		 * 5:	Slow
		 * 6:	Fluctuating
		 */
		char experienceGainSpeed;
		
		/* Keep track of what values will return
		 * which gender */
		unsigned char genderThreshold;
		
		/* Evolution data structure. 
		 * Each index is a possible evolution tree,
		 * 
		 * 0x0-0x15:	Evolution Method
		 * 0x16-0x31:	Evolution Parameter
		 * 0x32-0x63:	Target Pokemon
		 */
		unsigned long evolutionStructure [10];
		
		/* Sizing things 
		 * 0-65535:		Weight, in KG. Divide by 10 for decimal
		 * 65535-end:	Height, in M. Divide by 10 for decimal
		 */
		unsigned int heightAndWeight;
		
		/* Catch rate */
		unsigned char catchRate;
		
		/* Body type.
		 * Footprint is obtained from checking the
		 * resources directory for the footprint, if
		 * none exists, just use the blank image.
		 * 
		 * Use these values to also get the pokedex
		 * color.
		 * 20:	Red
		 * 21:	Blue
		 * 22:	Yellow
		 * 23:	Green
		 * 24:	Black
		 * 25:	Brown
		 * 26:	Purple
		 * 27:	Gray
		 * 28:	White
		 * 29:	Pink
		 */
		unsigned char bodyAndColor;
		
		/* Egg data
		 * 
		 * 0-15:	Egg Group 1
		 * 16-31:	Egg Group 2
		 * 32-255:	Egg Cycles to Hatch
		 */
		unsigned char eggData;
		
	public:
		BasePokemon();
		BasePokemon(std::string constructionString);
		~BasePokemon();
		
		/* Accessor methods */
		std::string getName();
		std::string getPokedexString();
		unsigned int getPokedexNumber();
		int getNationalPokedexNumber();
		int getRegionalPokedexNumber();
		std::vector<int> getBaseStats();
		int getBaseFriendship();
		int getPokeathalonStats();
		std::vector<unsigned char> getEVYield();
		int getEXPYield();
		/* Accessor for abilities */
		std::vector<unsigned char> getAbilites();
		int getFirstAbility();
		int getSecondAbility();
		int getFirstHiddenAbility();
		int getSecondHiddenAbility();
		/* Move accessors */
		std::vector<unsigned int> getMovesLearnedByLevelUp();
		std::vector<unsigned char> getLevelsMovedLearned();
		std::vector<unsigned int> getEggMoves();
		std::vector<unsigned int> getTutoredMoves();
		std::vector<unsigned int> getMovesLearnedBeforeLevel(int level);
		/* Other accessors */
		int getExperienceGainSpeed();
		int getGenderThreshold();
		std::vector<unsigned long> getEvolutionStructure();
		unsigned int getHeightAndWeigth();
		double getHeight();
		double getWeight();
		int getBodyType();
		int getPokedexColor();
		int getEggGroup1();
		int getEggGroup2();
		int getEggCycles();
		int getCatchRate();
		int getFirstType();
		int getSecondType();
		int isType(int type);
};

class BoxPokemon : public BasePokemon {
	private:
		/* OT Name and ID */
		unsigned int trainerID;
		std::string trainerName;
		
		std::string nickname;
		
		/* Keeps track of abilities, nature, gender, shininess, etc
		 * See http://bulbapedia.bulbagarden.net/wiki/Personality_value
		 * for more information
		 */
		unsigned int personalityValue;
		
		/* Keep track of the markings on the Pokemon in the box. */
		unsigned char markings;
		
		/* Keep track of these thingys */
		unsigned int medals;
		unsigned int ribbons;
		
		/* Moves Pokemon knows */
		LearnedMove firstMove;
		LearnedMove secondMove;
		LearnedMove thirdMove;
		LearnedMove fourthMove;
		
		/* Keep track of the current experience the Pokemon
		 * has gained. */
		unsigned int exp;
		
		/* Keep track of the IV's/EV's of the Pokemon */
		unsigned char ivs [6];
		unsigned char evs [6];
		
		/* Pokerus remaining */
		unsigned char pokerusStatus;
	public:
		BoxPokemon();
		BoxPokemon(std::string constructionString);
		~BoxPokemon();
		
		/* Accessors */
		int getTrainerID();
		std::string getTrainerName();
		std::string getPokemonNickname();
		unsigned int getPersonalityValue();
		unsigned int getMarkings();
		unsigned int getCurrentEXP();
		std::vector<unsigned char> getIVs();
		unsigned char getIV(int iv);
		std::vector<unsigned char> getEVs();
		unsigned char getEV(int ev);
		unsigned char getPokerusStatus();
		std::vector<LearnedMove> getLearnedMoves();
		LearnedMove getMove(int index);
		
		int isMale();
		int isFemale();
		
		/* Modifiers */
		int toggleMarking(int markingIndex);
		int setNickname(std::string newNickname);
		int setMove(int moveIndex, LearnedMove newMove);
		int removeMove(int moveIndex);
		int resetIV(int iv, int isRandom, int toMax, int newValue);
		int modifyEV(int ev, int amount);
		int modifyPokerus(unsigned char newValue);
		int deltaEXP(int amount);
};

class PartyPokemon : public BoxPokemon {
	private:
		/* Keep track of level*/
		unsigned char pokemonLevel;
		
		/* Keep track of persistent status conditions */
		unsigned char statusCondition;
		
		/* Current HP */
		int currentHP;
		
		/* Current Stats */
		int attack;
		int defense;
		int specialAttack;
		int specialDefense;
		int speed;
		int hp;
	public:
		PartyPokemon();
		PartyPokemon(std::string constructionString);
		~PartyPokemon();
		
		/* Accessors */
		unsigned char getPokemonLevel();
		unsigned char getStatusCondition();
		int getStat(int stat);
		int getCurrentHP();
		int getAttack();
		int getDefense();
		int getSpecialAttack();
		int getSpecialDefense();
		int getSpeed();
		int getMaxHP();
		int getPersistentStatusCondition();
		
		/* Modifiers */
		int deltaHP(int amount);
		int setHP(int amount);
		int setStatusCondition(int condition);
		
		/* Recalculate things */
		int recalculateStats();
		int recalculateLevel();
};

class BattlePokemon : public PartyPokemon {
	private:
		/* Battle volatile status */
		std::vector<unsigned char> volatileStatus;
		std::vector<unsigned char> volatileBattleStatus;
		
		unsigned char attackStage;
		unsigned char defenseStage;
		unsigned char specialAttackStage;
		unsigned char specialDefenseStage;
		unsigned char speedStage;
		unsigned char evasionStage;
		unsigned char accuracyStage;
		
		int currentAttack;
		int currentDefense;
		int currentSpecialAttack;
		int currentSpecialDefense;
		int currentSpeed;
		int currentEvasion;
		int currentAccuracy;
		
		int isBadlyPoisoned;
	public:
		BattlePokemon();
		BattlePokemon(std::string constructionString);
		~BattlePokemon();
};

/* Keeps track of all moves in game. Probably need to find a
 * better place for this. */
extern std::vector<BasePokemon> pokemonInGame;
extern std::vector<BoxPokemon> obtainedPokemon;
