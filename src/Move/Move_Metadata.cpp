#include "Move_Metadata.h"

std::vector<std::string> moveMetaAilments;
std::vector<std::string> moveMetaCategories;
std::vector<std::string> moveMetaStatChanges;

int loadMoveMetaAilments() {
	return loadMoveMetaAilments("move_meta_ailments.csv");
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
		for (int i=0; i<tempLines.size(); i++) {
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
	loadMoveMetaCategories("move_meta_categories.csv");
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
		for (int i=0; i<tempLines.size(); i++) {
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
	loadMoveMetaStatChanges("move_meta_stat_changes.csv");
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
			boost::split(words, line, boost::is_any_of(", "));
			
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
		for (int i=0; i<tempLines.size(); i++) {
			moveMetaStatChanges.push_back(tempLines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}
