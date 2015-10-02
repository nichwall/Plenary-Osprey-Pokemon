#include "Move_Damage_Class.h"

std::vector<std::string> damageClass;

int load_Damage_Class() {
	return load_Damage_Class("move_damage_classes.csv");
}
int load_Damage_Class(std::string pathToFile) {
	printf("Loading Damage classes....");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::string line;
		// Skip the first row, because column headers
		getline(file,line);
		
		std::vector<std::string> lines;
		
		while ( getline(file,line) ) {
			std::vector<std::string> words;
			boost::split(words, line, boost::is_any_of(", "));
			
			// Check it's the right size
			if (words.size() != 2) {
				printf("ERROR(2): Invalid CSV file\n");
				return 2;
			}
			// Otherwise, add the things!
			lines.push_back(line);
		}
		// Sort the lines
		std::sort(lines.begin(), lines.end());
		
		for (unsigned int i=0; i<lines.size(); i++) {
			damageClass.push_back(lines.at(i));
		}
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

std::string getDamageClass(int damageClassID) {
	for (unsigned int i=0; i<damageClass.size(); i++) {
		// Split the string
		std::vector<std::string> words;
		boost::split(words, damageClass.at(i), boost::is_any_of(", "));
		
		// Check that the IDs match
		if (damageClassID != atoi(words.at(0).c_str()) ) {
			continue;
		}
		return words.at(1);
	}
	return ("");
}
