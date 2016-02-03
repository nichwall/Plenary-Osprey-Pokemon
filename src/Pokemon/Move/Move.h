/* Class for Moves.
 * 
 * BaseMove:	Move data for the move, just actions, etc
 * LearnedMove:	Move data for a learned move, extends BaseMove
 * 				in order to add PP*/
#ifndef MOVE_MOVE_H_
#define MOVE_MOVE_H_

#include "Move_Metadata.h"
#include "../../Language/Language.h"

class BaseMove {
	private:
		std::string name;
		std::string identifier;
		int id;
		// Types
		int type1;
		int type2;
		
		// Base PP
		int basePP;
		// Power, Accuracy, etc
		int pow;
		int acc;
		int priority;
		int targets;
		
		// Identifier, checks against prewritten ids
		int damageClass;
		int effectID;
		int effectChance;
		
		// Contest Data
		int contestTypeID;
		int contestEffectID;
		int superContestEffectID;
		
		// Meta data
		MoveMeta meta;
	public:
		// Constructors
		BaseMove(int moveID, std::string moveIdentifier, int typeID, int PP, int power, int accuracy, int battlePriority,
				 int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance, int contest_TypeID,
				 int contest_EffectID, int superContest_EffectID, MoveMeta metadata);
/*		BaseMove(int moveID, std::string moveIdentifier, int type1ID, int type2ID, int PP, int power, int accuracy,
				 int battlePriority, int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance,
				 int contest_TypeID, int contest_EffectID, int superContest_EffectID, MoveMeta metadata);*/
		// Destructors
		~BaseMove();
		// Accessors
		std::string getMoveName()         { return name; }
		std::string getMoveIdentifier()   { return identifier; }
		int getMoveID()                   { return id; }
		int getMoveType1()                { return type1; }
		int getMoveType2()                { return type2; }
		int getMovePP()                   { return basePP; }
		int getMovePower()                { return pow; }
        int getMoveAccuracty()            { return acc; }
		int getMovePriority()             { return priority; }
		int getMoveTargets()              { return targets; }
		int getMoveDamageClass()          { return damageClass; }
		int getMoveEffectID()             { return effectID; }
		int getMoveEffectChance()         { return effectChance; }
		int getMoveContestTypeID()        { return contestTypeID; }
		int getMoveContestEffectID()      { return contestEffectID; }
		int getMoveSuperContestEffectID() { return superContestEffectID; }
		MoveMeta getMoveMeta()            { return meta; }
		// Modifiers
		void setMoveName(std::string moveName);
		
};

class LearnedMove {
	private:
		BaseMove * base;
		int ppUsed;
	public:
		// Constructor
		LearnedMove ();
		LearnedMove (BaseMove baseMove);
		// Accessor
		BaseMove * move();
		int getMovePP();
		// Modifier
		void usePPUp(int amount);
};

// Vector to store the base moves
extern std::vector<BaseMove> baseMoves;
extern std::vector<std::string> moveLines;
extern std::vector<std::string> moveNames;

// Functions to load all of the moves from the files
int loadMoves();
int loadMoves(std::string pathToFile);
int loadMoveNames();
int loadMoveNames(std::string pathToFile);
int constructBaseMoves();
int constructBaseMoves(std::string pathToMoves, std::string pathToNames);

// Struct for BasePokemon
struct learnMoveDataStruct {
	BaseMove move;
	uint16_t method;
	uint16_t data;
};

#endif
