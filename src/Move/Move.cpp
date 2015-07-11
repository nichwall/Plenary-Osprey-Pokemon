#include "Move.h"

// Vector to store the base moves
std::vector<BaseMove> baseMoves;
std::vector<std::string> moveLines;
std::vector<std::string> moveNames;

BaseMove::BaseMove(int moveID, std::string moveIdentifier, int typeID, int pp, int power, int accuracy, int battlePriority, int battleTargets, std::string moveDamageClass, std::string moveEffectID, int moveEffectChance, int contest_TypeID, int contest_EffectID, int superContest_EffectID)
	: identifier(moveIdentifier),
	  id(moveID),
	  type1(typeID),
	  basePP(pp),
	  pow(power),
	  acc(accuracy),
	  priority(battlePriority),
	  targets(battleTargets),
	  damageClass(moveDamageClass),
	  effectID(moveEffectID),
	  effectChance(moveEffectChance),
	  contestTypeID(contest_TypeID),
	  contestEffectID(contest_EffectID),
	  superContestEffectID(superContest_EffectID)
{
	
}
BaseMove::BaseMove(int moveID, std::string moveIdentifier, int type1ID, int type2ID, int pp, int power, int accuracy, int battlePriority, int battleTargets, std::string moveDamageClass, std::string moveEffectID, int moveEffectChance, int contest_TypeID, int contest_EffectID, int superContest_EffectID)
	: identifier(moveIdentifier),
	  id(moveID),
	  type1(type1ID),
	  type2(type2ID),
	  basePP(pp),
	  pow(power),
	  acc(accuracy),
	  priority(battlePriority),
	  targets(battleTargets),
	  damageClass(moveDamageClass),
	  effectID(moveEffectID),
	  effectChance(moveEffectChance),
	  contestTypeID(contest_TypeID),
	  contestEffectID(contest_EffectID),
	  superContestEffectID(superContest_EffectID)
{
	
}
/*BaseMove::~BaseMove() {
	
}*/
std::string BaseMove::getMoveName() {
	return name;
}
std::string BaseMove::getMoveIdentifier() {
	return identifier;
}
int BaseMove::getMoveID() {
	return id;
}
int BaseMove::getMoveType1() {
	return type1;
}
int BaseMove::getMoveType2() {
	return type2;
}
int BaseMove::getMoveBasePP() {
	return basePP;
}
int BaseMove::getMovePower() {
	return pow;
}
int BaseMove::getMoveAccuracty() {
	return acc;
}
int BaseMove::getMovePriority() {
	return priority;
}
int BaseMove::getMoveTargets() {
	return targets;
}
std::string BaseMove::getMoveDamageClass() {
	return damageClass;
}
std::string BaseMove::getMoveEffectID() {
	return effectID;
}
int BaseMove::getMoveEffectChance() {
	return effectChance;
}
int BaseMove::getMoveContestTypeID() {
	return contestTypeID;
}
int BaseMove::getMoveContestEffectID() {
	return contestEffectID;
}
int BaseMove::getMoveSuperContestEffectID() {
	return superContestEffectID;
}


int loadMoves() {
	loadMoves("moves.csv");
}
int loadMoves(std::string pathToFile) {
	printf("Loading moves....");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip the first line, just the headers
		getline(file,line);
		// Temporary vector of read lines
		std::vector<std::string> tempLines;
		
		while ( getline(file,line)) {
			// Split the string
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(", "));
			
			// Check it's the right size
			if (words.size() != 15) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Otherwise, add the things!
			tempLines.push_back(line);
		}
		// Sort the vector of lines
		std::sort(tempLines.begin(), tempLines.end());
		
		// Insert the vector into vector "baseMoves"
		for (int i=0; i<tempLines.size(); i++) {
			moveLines.push_back(tempLines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

int constructBaseMoves() {
	constructBaseMoves("moves.csv");
}
int constructBaseMoves(std::string pathToFile) {
	if (loadMoves(pathToFile) != 0) {
		return -1;
	}
	printf("Creating base moves....");
	// Loop through all lines read from the file
	for (int i=0; i<baseMoves.size(); i++) {
		std::string line;
		// Split line based on comma
		std::vector<std::string> words;
		boost::split(words, line, boost::is_any_of(","));
		
		std::vector<int> conInt; // (con)verted (int)
		std::vector<std::string> conStr; // (con)verted (str)
		for (int i=0; i<words.size(); i++) {
			if (words.at(i).length() != 0) {
				if (isInteger(words.at(i))) {
					conInt.push_back( atoi(words.at(i).c_str()) );
				} else {
					conStr.push_back(words.at(i));
				}
			}
		}
		if (conStr.size()+conInt.size() == 15) {
			//BaseMove tempMove (words.at(0),words.at(1),words.at(3));
		}
	}
	printf("done\n");
	return 0;
}
