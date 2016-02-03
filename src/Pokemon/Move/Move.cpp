#include "Move.h"

// Vector to store the base moves
std::vector<BaseMove> baseMoves;
std::vector<std::string> moveLines;
std::vector<std::string> moveNames;

BaseMove::BaseMove(int moveID, std::string moveIdentifier, int typeID, int pp, int power, int accuracy, int battlePriority,
				   int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance, int contest_TypeID,
				   int contest_EffectID, int superContest_EffectID, MoveMeta metadata)
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
	  superContestEffectID(superContest_EffectID),
	  meta(metadata)
{
	
}
/*BaseMove::BaseMove(int moveID, std::string moveIdentifier, int type1ID, int type2ID, int pp, int power, int accuracy,
				   int battlePriority, int battleTargets, int moveDamageClass, int moveEffectID, int moveEffectChance,
				   int contest_TypeID, int contest_EffectID, int superContest_EffectID, MoveMeta metadata)
	: id(moveID),
	  identifier(moveIdentifier),
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
	  superContestEffectID(superContest_EffectID),
	  meta(metadata)
{
	
}*/
BaseMove::~BaseMove() {
	
}
void BaseMove::setMoveName(std::string moveName) {
	name = moveName;
}

LearnedMove::LearnedMove() {
	base = 0;
	ppUsed = 0;
}
LearnedMove::LearnedMove(BaseMove baseMove) {
	base = &baseMove;
	ppUsed = 0;
}
BaseMove * LearnedMove::move() {
	return base;
}
int LearnedMove::getMovePP() {
	return base->getMovePP() * (5+ppUsed) / 5;
}
void LearnedMove::usePPUp(int amount) {
	ppUsed += amount;
	// Coerce to [0,3]
	if (ppUsed > 3) {
		ppUsed = 3;
	} else if (ppUsed < 0) {
		ppUsed = 0;
	}
}
		
int loadMoves() {
	return loadMoves("Resources/moves.csv");
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
		moveLines.swap(tempLines);
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

int loadMoveNames() {
	return loadMoveNames("Resources/move_names.csv");
}
int loadMoveNames(std::string pathToFile) {
	printf("Loading move names....");
	// Open file
	std::ifstream file (pathToFile.c_str());
	
	if (file.is_open()) {
		std::string line;
		// Skip first line
		getline(file,line);
		
		// Loop until end of file, putting all of correct language into vector
		std::vector<std::string> lines;
		while ( getline(file,line) ) {
			// Split the string
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(","));
			
			// Check it's the right size
			if (words.size() != 3) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Check that it's the right language
			if ( atoi(words.at(1).c_str()) != languageID) {
				continue;
			}
			// Otherwise, add the things!
			
			lines.push_back(line);
		}
		// Sort the type effects
		std::sort(lines.begin(), lines.end());
		moveNames.swap(lines);
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

int constructBaseMoves() {
	return constructBaseMoves("Resources/moves.csv", "Resources/move_names.csv");
}
int constructBaseMoves(std::string pathToMoves, std::string pathToNames) {
	if ( loadMoves(pathToMoves)!=0 || loadMoveNames(pathToNames)!=0 ) {
		return -1;
	}
	
	printf("Creating base moves....");
	// Loop through all lines read from the file
	for (unsigned int i=0; i<moveLines.size(); i++) {
		// Split line based on comma
		std::vector<std::string> words;
		boost::split(words, moveLines.at(i), boost::is_any_of(","));
		if (words.size() == 15) {
			// Convert to a nice vector
			std::vector<int> conInt; // (con)verted (ints)
			for (unsigned int j=0; j<words.size(); j++) {
				if (j!=1) {
					conInt.push_back( atoi(words.at(j).c_str()) );
				}
			}
			
			// variable for loop for move names
			int z = 0;
			for (unsigned int j=0; j<metas.size(); j++) {
				if (metas.at(j).getMoveID() == conInt.at(0)) {
					// Construct the moves!
					BaseMove tempMove ( conInt.at(0), words.at(1), conInt.at(2), conInt.at(4), conInt.at(3), conInt.at(5),
										conInt.at(6), conInt.at(7), conInt.at(8), conInt.at(9), conInt.at(10), conInt.at(11),
										conInt.at(12), conInt.at(13), metas.at(j) );
					// Add the names to the moves!
					// Loop until we find the right move id
					std::vector<std::string> moveNamesSplit;
					boost::split(moveNamesSplit, moveNames.at(z++), boost::is_any_of(","));
					while ( tempMove.getMoveID() != atoi(moveNamesSplit.at(0).c_str()) ) {
						boost::split(moveNamesSplit, moveNames.at(z++), boost::is_any_of(","));
					}
					tempMove.setMoveName(moveNamesSplit.at(2));
					baseMoves.push_back( tempMove );
				}
			}
		}
	}
	printf("done\n");
	
	// Clean up vectors
	moveLines.clear();
	moveNames.clear();
	
	return 0;
}
