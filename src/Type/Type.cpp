#include "Type.h"

std::vector<std::string> typeNames;

int loadTypes() {
	loadTypes("Type/type_names.csv");
}
int loadTypes(std::string pathToFile) {
	printf("Loading Pokemon and Move types....");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	
	if (file.is_open()) {
		std::string line;
		// Skip first line of files
		getline(file,line);
		
		// Loop until end of file, putting all of correct language into vector
		std::vector<std::string> types;
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
			
			types.push_back(line);
		}
		// Sort the type effects
		std::sort(types.begin(), types.end());
		
		typeNames.swap(types);
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}

std::string getTypeName(int typeIndex) {
	for (int i=0; i<typeNames.size(); i++) {
		// Split the string
		std::vector<std::string> words;
		boost::split(words, typeNames.at(i), boost::is_any_of(", "));
		
		return words.at(2);
	}
	return "";
}
