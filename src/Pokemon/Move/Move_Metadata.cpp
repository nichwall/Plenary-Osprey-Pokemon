#include "Move_Metadata.h"

std::vector<MoveMeta> metas;
std::vector<std::string> moveMetaAilments;
std::vector<std::string> moveMetaCategories;
std::vector<std::string> moveMetaStatChanges;

MoveMeta::MoveMeta(int move_id, int catagory_id, std::string catagory_name, int ailment_id, std::string ailment_name,
				   int min_hits, int max_hits, int min_turns, int max_turns, int drain_perc, int heal_perc, int crit_rate,
				   int ailment_chance, int flinch_chance, int stat_chance, std::array<int, 8> stat_deltas)
	: moveID(move_id),
	  catagoryID(catagory_id),
	  catagory (catagory_name),
	  ailmentID (ailment_id),
	  ailment (ailment_name),
	  minHits (min_hits),
	  maxHits (max_hits),
	  minTurns (min_turns),
	  maxTurns (max_turns),
	  drain (drain_perc),
	  heal (heal_perc),
	  critRate (crit_rate),
	  ailmentChance (ailment_chance),
	  flinchChance (flinch_chance),
	  statChance (stat_chance),
	  statsChanged (stat_deltas)
{
	
}
int MoveMeta::getMoveID() {
	return moveID;
}
int MoveMeta::getMetaCatagoryID() {
	return catagoryID;
}
int MoveMeta::getMetaAilmentID() {
	return ailmentID;
}
int MoveMeta::getMinHits() {
	return minHits;
}
int MoveMeta::getMaxHits() {
	return maxHits;
}
int MoveMeta::getMinTurns() {
	return minTurns;
}
int MoveMeta::getMaxTurns() {
	return maxTurns;
}
int MoveMeta::getDrainPercent() {
	return drain;
}
int MoveMeta::getHealPercent() {
	return heal;
}
int MoveMeta::getCritRate() {
	return critRate;
}
int MoveMeta::getMetaAilmentChance() {
	return ailmentChance;
}
int MoveMeta::getFlinchChance() {
	return flinchChance;
}
int MoveMeta::getStatChangeChance() {
	return statChance;
}
std::array<int, 8> MoveMeta::getStatsChanged() {
	return statsChanged;
}
char MoveMeta::getStatDelta(unsigned int stat) {
	if (stat < 0 || stat > statsChanged.size()) {
		return 0;
	}
	return statsChanged.at(stat);
}

int loadMoveMetaAilments() {
	return loadMoveMetaAilments("Resources/move_meta_ailments.csv");
}
int loadMoveMetaAilments(std::string pathToFile) {
	printf("Loading Move Meta ailments...");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip first line
		getline(file,line);
		
		// Temporary vector of lines
		std::vector<std::string> tempLines;
		
		// Loop through file and get all the lines
		while ( getline(file,line) ) {
			// Split the staring
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(", "));
			
			// Check it's the right size
			if (words.size() != 2) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Otherwise, add the things!
			tempLines.push_back(line);
		}
		// Sort the lines
		std::sort(tempLines.begin(), tempLines.end());
		for (unsigned int i=0; i<tempLines.size(); i++) {
			moveMetaAilments.push_back(tempLines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}
int loadMoveMetaCategories() {
	return loadMoveMetaCategories("Resources/move_meta_categories.csv");
}
int loadMoveMetaCategories(std::string pathToFile) {
	printf("Loading Move Meta categories...");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip first line
		getline(file,line);
		
		// Temporary vector of lines
		std::vector<std::string> tempLines;
		
		// Loop through file and get all the lines
		while ( getline(file,line) ) {
			// Split the string
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(", "));
			
			// Check it's the right size
			if (words.size() != 2) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Otherwise, add the things!
			tempLines.push_back(line);
		}
		// Sort the lines
		std::sort(tempLines.begin(), tempLines.end());
		for (unsigned int i=0; i<tempLines.size(); i++) {
			moveMetaCategories.push_back(tempLines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}
int loadMoveMetaStatChanges() {
	return loadMoveMetaStatChanges("Resources/move_meta_stat_changes.csv");
}
int loadMoveMetaStatChanges(std::string pathToFile) {
	printf("Loading Move Meta stat changes...");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip first line
		getline(file,line);
		
		// Temporary vector of lines
		std::vector<std::string> tempLines;
		
		// Loop through file and get all the lines
		while ( getline(file,line) ) {
			// Split the string
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(","));
			
			// Check it's the right size
			if (words.size() != 3) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Otherwise, add the things!
			tempLines.push_back(line);
		}
		// Sort the lines
		std::sort(tempLines.begin(), tempLines.end());
		for (unsigned int i=0; i<tempLines.size(); i++) {
			moveMetaStatChanges.push_back(tempLines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

int loadMoveMeta() {
	return loadMoveMeta("Resources/move_meta_ailments.csv","Resources/move_meta_categories.csv","Resources/move_meta_stat_changes.csv","Resources/move_meta.csv");
}
int loadMoveMeta(std::string pathToAilments, std::string pathToCategories, std::string pathToStats, std::string pathToMeta) {
	if (loadMoveMetaAilments(pathToAilments) != 0) {
		return -1;
	}
	if (loadMoveMetaCategories(pathToCategories) != 0) {
		return -2;
	}
	if (loadMoveMetaStatChanges(pathToStats) != 0) {
		return -3;
	}
	
	// Load the move meta data file
	printf("Loading Move Meta...");
	// Open file
	std::ifstream file (pathToMeta.c_str());
	if (file.is_open()) {
		std::string line;
		getline(file,line);
		while (getline(file,line)) {
			// Split the string
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(","));
			
			// Check it's the right size
			if (words.size() != 13) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			
			// Get all of the meta parts ready
			int moveID = atoi(words.at(0).c_str());
			std::string ailment;
			std::string catagory;
			std::array<int, 8> stats;
			for (unsigned int i=0; i<moveMetaAilments.size(); i++) {
				std::vector<std::string> nestedWords;
				boost::split(nestedWords, moveMetaAilments.at(i), boost::is_any_of(","));
				if ( atoi(nestedWords.at(0).c_str()) == atoi(words.at(2).c_str()) ) {
					ailment = moveMetaAilments.at(i);
				}
			}
			for (unsigned int i=0; i<moveMetaCategories.size(); i++) {
				std::vector<std::string> nestedWords;
				boost::split(nestedWords, moveMetaCategories.at(i), boost::is_any_of(","));
				if ( atoi(nestedWords.at(0).c_str()) == atoi(words.at(1).c_str()) ) {
					catagory = moveMetaCategories.at(i);
				}
			}
			for (unsigned int i=0; i<moveMetaStatChanges.size(); i++) {
				std::vector<std::string> nestedWords;
				boost::split(nestedWords, moveMetaStatChanges.at(i), boost::is_any_of(","));
				if ( atoi(nestedWords.at(0).c_str()) == moveID ) {
					//stats = moveMetaStatChanges.at(i);
				}
			}
			
			std::vector<std::string> ailSplit;
			boost::split(ailSplit, ailment, boost::is_any_of(","));
			std::vector<std::string> catSplit;
			boost::split(catSplit, catagory, boost::is_any_of(","));
			
			MoveMeta tempMeta ( moveID, atoi(words.at(1).c_str()), catSplit.at(1), atoi(words.at(2).c_str()), ailSplit.at(1),
								atoi(words.at(3).c_str()), atoi(words.at(4).c_str()), atoi(words.at(5).c_str()),
								atoi(words.at(6).c_str()), atoi(words.at(7).c_str()), atoi(words.at(8).c_str()),
								atoi(words.at(9).c_str()), atoi(words.at(10).c_str()), atoi(words.at(11).c_str()),
								atoi(words.at(12).c_str()), stats );
			metas.push_back(tempMeta);
		}
	}
	printf("done\n");
	
	// Delete string vectors of metadata stuff, because it's just using up space
	moveMetaAilments.clear();
	moveMetaCategories.clear();
	moveMetaStatChanges.clear();
	
	return 0;
}
