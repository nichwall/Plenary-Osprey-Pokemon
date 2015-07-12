/* Used to calculate type effectivenesses between types */

#include "TypeEfficiency.h"

// Variables
int numberOfTypes;
std::vector<std::string> typeEffectivenessMap;

// Functions

// Default configuration
int loadTypeEffectivenessMap() {
	return loadTypeEffectivenessMap("Type/type_effectiveness.csv");
}
// Custom configuration
int loadTypeEffectivenessMap(std::string pathToFile) {
	printf("Loading Type Effectiveness Map....");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip the first row, because column headers
		getline(file,line);
		
		// Temporary type effectiveness string vector
		std::vector<std::string> tempEffects;
		
		// Loop through file and get all of the lines
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
			tempEffects.push_back(line);
		}
		// Sort the type effects
		std::sort(tempEffects.begin(), tempEffects.end());
		
		// Get the square root of the effectiveness count
		// If the number of lines does not have an integer square root,
		// then oops. Fail and return
		float typeCount = sqrt(tempEffects.size());
		if (typeCount != floor(typeCount)) {
			printf("ERROR(3): Invalid CSV file\n");
			return 3;
		}
		numberOfTypes = typeCount;
		for (int i=0; i<tempEffects.size(); i++) {
			typeEffectivenessMap.push_back(tempEffects.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

/* Returns the percentage to multiply the damage by
 * Negative answer indicates error
 */
int getEffectiveness(int attackType, int defenseType) {
	for (int i=0; i<typeEffectivenessMap.size(); i++) {
		// Split the string
		std::vector<std::string> words;
		boost::split(words, typeEffectivenessMap.at(i), boost::is_any_of(", "));
		
		// Attack type doesn't match
		if ( atoi(words.at(0).c_str()) != attackType) {
			continue;
		}
		// Defense type doesn't match
		if ( atoi(words.at(1).c_str()) != defenseType) {
			continue;
		}
		// Worked! Return damage
		return atoi(words.at(2).c_str());
	}
	// Oops. Didn't find anything, return -1
	return -1;
}
