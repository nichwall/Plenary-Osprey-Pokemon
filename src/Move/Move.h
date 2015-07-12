/* Class for Moves.
 * 
 * BaseMove:	Move data for the move, just actions, etc
 * LearnedMove:	Move data for a learned move, extends BaseMove
 * 				in order to add PP*/
#ifndef MOVE_MOVE_H_
#define MOVE_MOVE_H_

#include "Move_Metadata.h"

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
		
		int contestTypeID;
		int contestEffectID;
		int superContestEffectID;
	public:
		// Constructors
		BaseMove(int moveID, std::string moveIdentifier, int typeID, int PP, int power, int accuracy, int battlePriority, int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance, int contest_TypeID, int contest_EffectID, int superContest_EffectID);
		BaseMove(int moveID, std::string moveIdentifier, int type1ID, int type2ID, int PP, int power, int accuracy, int battlePriority, int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance, int contest_TypeID, int contest_EffectID, int superContest_EffectID);
		// Destructors
		//~BaseMove();
		// Accessors
		std::string getMoveName();
		std::string getMoveIdentifier();
		int getMoveID();
		int getMoveType1();
		int getMoveType2();
		int getMoveBasePP();
		int getMovePower();
		int getMoveAccuracty();
		int getMovePriority();
		int getMoveTargets();
		int getMoveDamageClass();
		int getMoveEffectID();
		int getMoveEffectChance();
		int getMoveContestTypeID();
		int getMoveContestEffectID();
		int getMoveSuperContestEffectID();
		// Modifiers
		void setMoveName(std::string moveName);
		
};

/*class LearnedMove : public BaseMove {
	private:
		
	public:
		
};*/

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
int constructBaseMoves(std::string pathToFile);

#endif
