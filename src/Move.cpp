#include "Move.h"

BaseMove::BaseMove() {
	
}
/* For when we're initializing all of the moves during startup
 * Tab seperated, with the following indices of the line being the following
 * 
 * 0:	Move Name
 * 1:	Move Type
 * 2:	Contest Type
 * 3:	Move Power
 * 4:	Move Accuracy
 * 5:	
 */
BaseMove::BaseMove(std::string lineFromFile) {
	std::vector<std::string> splitted = splitString(lineFromFile,"\t");
	/*for (std::vector<std::string>::iterator it = splitted.begin(); it!=splitted.end(); ++it) {
		
	}*/
	moveTitle = splitted.at(0).c_str();
	moveNumber = atoi(splitted.at(1).c_str());
	type = atoi(splitted.at(2).c_str());
	power = atoi(splitted.at(3).c_str());
	accuracy = atoi(splitted.at(4).c_str());
	basePP = atoi(splitted.at(5).c_str());
	
	std::vector<std::string> tempParametersSplit = splitString(splitted.at(6)," ");
	for (int i=0; i<tempParametersSplit.size(); i++) {
		parameters.push_back(atoi(tempParametersSplit.at(i).c_str()));
	}
	persistentStatus = atoi(splitted.at(7).c_str());
	volatileStatus = atoi(splitted.at(8).c_str());
	volatileBattleStatus = atoi(splitted.at(9).c_str());
	targets = atoi(splitted.at(10).c_str());
	attackPriority = atoi(splitted.at(11).c_str());
}
BaseMove::~BaseMove() {
	
}
/* Accessors */
std::string BaseMove::getMoveName() {
	return moveTitle;
}
std::string BaseMove::getDescription() {
	return description;
}
unsigned int BaseMove::getMoveNumber() {
	return moveNumber;
}
int BaseMove::getType() {
	return type;
}
int BaseMove::getPower() {
	return power;
}
int BaseMove::getAccuracy() {
	return accuracy;
}
int BaseMove::getTargets() {
	return targets;
}
int BaseMove::getPP() {
	return basePP;
}
/* Return what volatile status to give to the target */
int BaseMove::getVolatileStatus() {
	// Generate seed for random number
	srand(time(NULL));
	// Generate random number from 0 to 100, inclusive
	unsigned int randomlyGeneratedNumber = rand()%101;
	
	if (volatileStatus%128==0 || randomlyGeneratedNumber<volatileStatus%128) {
		for (int i=16; i<32; i++) {
			if ( (volatileStatus >> i)&1 ) {
				return (int)pow(2,i);
			}
		}
	}
	
	return 0;
}
int BaseMove::getVolatileBattleStatus() {
	return volatileBattleStatus;
}
/* This will return which status to give target Pokemon. The
 * check for which to give will be done in here and the
 * random number will also be created in here. */
int BaseMove::getPersistentStatus() {
	// Generate seed for random number
	srand(time(NULL));
	// Generate random number from 0 to 10, inclusive
	unsigned int randomlyGeneratedNumber = rand()%100+1;
	
	// Check if the move will cause the status condition
	if (randomlyGeneratedNumber < (persistentStatus%128)) {
		unsigned int tempStat = persistentStatus/128;
		/* If the status condition is successful, then
		 * check which condition will occur if there's
		 * only one possibility.
		 */
		switch (tempStat) {
			default:
				break;
			case 0:
				return 0;
			case FAINT:
				return FAINT;
			case BURN:
				return BURN;
			case PARALYZED:
				return PARALYZED;
			case POISONED:
				return POISONED;
			case BADLYPOISONED:
				return BADLYPOISONED;
			case SLEEP:
				return SLEEP;
			case FROZEN:
				return FROZEN;
		}
		/* But some moves have more than one possible effect,
		 * so we'll generate another random number to see
		 * which one is applied. This number will be generated
		 * until it equals one of the conditions.
		 * If it doesn't pick one after 10 iterations, just
		 * default to the highest.
		 */
		for (int i=0; i<20; i++) {
			randomlyGeneratedNumber = rand()%7;
			if ( (tempStat >> randomlyGeneratedNumber) & 1 ) {
				return (int)pow(2,randomlyGeneratedNumber);
			}
		}
		/* Well, you've failed your status condition rolls.
		 * We're just going to loop through until you get
		 * a valid one, starting from the top.
		 */
		for (int i=1; i<8; i++) {
			if ( (tempStat >> i) & 1 ) {
				return (int)pow(2,i);
			}
		}
		return 0;
	}
}
/* Checks the effectiveness of this move against a given type */
double BaseMove::effectiveness(int targetType) {
	/* Check own type */
	switch(type%64) {
		default:
			return 1;
		case NORMAL:
			switch(targetType) {
				default:
					return 1.0;
				case ROCK:
				case STEEL:
					return 0.5;
				case GHOST:
					return 0.0;
			}
		case FIGHT:
			switch(targetType) {
				default:
					return 1;
				case NORMAL:
				case ROCK:
				case STEEL:
				case ICE:
				case DARK:
					return 2.0;
				case FLYING:
				case POISON:
				case BUG:
				case PSYCHIC:
				case FAIRY:
					return 0.5;
				case GHOST:
					return 0.0;
			}
		case FLYING:
			switch(targetType) {
				default:
					return 1.0;
				case FIGHT:
				case BUG:
				case GRASS:
					return 2.0;
				case ROCK:
				case STEEL:
				case ELECTRIC:
					return 0.5;
			}
		case POISON:
			switch(targetType) {
				default:
					return 1.0;
				case GRASS:
				case FAIRY:
					return 2.0;
				case POISON:
				case GROUND:
				case ROCK:
				case GHOST:
					return 0.5;
				case STEEL:
					return 0.0;
			}
		case GROUND:
			switch(targetType) {
				default:
					return 1.0;
				case POISON:
				case ROCK:
				case STEEL:
				case FIRE:
				case ELECTRIC:
					return 2.0;
				case BUG:
				case GRASS:
					return 0.5;
				case FLYING:
					return 0.0;
			}
		case ROCK:
			switch(targetType) {
				default:
					return 1.0;
				case FLYING:
				case BUG:
				case FIRE:
				case ICE:
					return 2.0;
				case FIGHT:
				case GROUND:
				case STEEL:
					return 0.5;
			}
		case BUG:
			switch(targetType) {
				default:
					return 1.0;
				case GRASS:
				case PSYCHIC:
				case DARK:
					return 2.0;
				case FIGHT:
				case FLYING:
				case POISON:
				case GHOST:
				case STEEL:
				case FIRE:
				case FAIRY:
					return 0.5;
			}
		case GHOST:
			switch(targetType) {
				default:
					return 1.0;
				case GHOST:
				case PSYCHIC:
					return 2.0;
				case DARK:
					return 0.5;
				case NORMAL:
					return 0.0;
			}
		case STEEL:
			switch(targetType) {
				default:
					return 1.0;
				case ROCK:
				case ICE:
				case FAIRY:
					return 2.0;
				case STEEL:
				case FIRE:
				case WATER:
				case ELECTRIC:
					return 0.5;
			}
		case FIRE:
			switch(targetType) {
				default:
					return 1.0;
				case BUG:
				case STEEL:
				case GRASS:
				case ICE:
					return 2.0;
				case ROCK:
				case FIRE:
				case WATER:
				case DRAGON:
					return 0.5;
			}
		case WATER:
			switch(targetType) {
				default:
					return 1.0;
				case GROUND:
				case ROCK:
				case FIRE:
					return 2.0;
				case WATER:
				case GRASS:
				case DRAGON:
					return 0.5;
			}
		case GRASS:
			switch(targetType) {
				default:
					return 1.0;
				case GROUND:
				case ROCK:
				case WATER:
					return 2.0;
				case FLYING:
				case POISON:
				case BUG:
				case STEEL:
				case FIRE:
				case GRASS:
				case DRAGON:
					return 0.5;
			}
		case ELECTRIC:
			switch(targetType) {
				default:
					return 1.0;
				case FLYING:
				case WATER:
					return 2.0;
				case GRASS:
				case ELECTRIC:
				case DRAGON:
					return 0.5;
				case GROUND:
					return 0.0;
			}
		case PSYCHIC:
			switch(targetType) {
				default:
					return 1.0;
				case FIGHT:
				case POISON:
					return 2.0;
				case STEEL:
				case PSYCHIC:
					return 0.5;
				case DARK:
					return 0.0;
			}
		case ICE:
			switch(targetType) {
				default:
					return 1.0;
				case FLYING:
				case GROUND:
				case GRASS:
				case DRAGON:
					return 2.0;
				case STEEL:
				case FIRE:
				case WATER:
				case ICE:
					return 0.5;
			}
		case DRAGON:
			switch(targetType) {
				default:
					return 1.0;
				case DRAGON:
					return 2.0;
				case STEEL:
					return 0.5;
				case FAIRY:
					return 0.0;
			}
		case DARK:
			switch(targetType) {
				default:
					return 1.0;
				case GHOST:
				case PSYCHIC:
					return 2.0;
				case FIGHT:
				case DARK:
				case FAIRY:
					return 0.5;
			}
		case FAIRY:
			switch(targetType) {
				default:
					return 1.0;
				case FIGHT:
				case DRAGON:
				case DARK:
					return 2.0;
				case POISON:
				case STEEL:
				case FIRE:
					return 0.5;
			}
	}
}



LearnedMove::LearnedMove() {
	ppUpUsed = 0;
	currentPP = getPP();
	BaseMove();
}
LearnedMove::LearnedMove(std::string constructionString) {
	
}
LearnedMove::~LearnedMove() {
	
}
/* Add to PP Up. Remember that we can't have more
 * than 3 used per Move */
int LearnedMove::addToPPUp(int deltaPP) {
	if (ppUpUsed==3) {
		/* Don't want players wasting PP ups on moves that
		 * can't be used. */
		return -1;
	}
	ppUpUsed += deltaPP;
	if (ppUpUsed>3) {
		ppUpUsed = 3;
	}
	return 0;
}
int LearnedMove::getCurrentPP() {
	return currentPP;
}
int LearnedMove::getMaxPP() {
	return getPP()+(5+ppUpUsed)/5;
}
void LearnedMove::deltaPP(int PPchange) {
	currentPP += PPchange;
	/* Coerce PP to legal limits */
	if (currentPP<0) {
		currentPP = 0;
	} else if (currentPP>getMaxPP()) {
		currentPP = getMaxPP();
	}
}
void LearnedMove::healPP() {
	currentPP = getMaxPP();
}

std::vector<BaseMove> movesInGame;
