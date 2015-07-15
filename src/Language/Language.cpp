#include "Language.h"

std::vector<std::string> languages;
int languageID;

// Constructors
int loadLanguages() {
	loadLanguages("Language/language_names.csv");
}
int loadLanguages(std::string pathToFile) {
	printf("Loading language data...");
	
	// Open file
	std::ifstream file (pathToFile.c_str());
	
	if (file.is_open()) {
		std::string line;
		// Skip first line of files
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
			// Otherwise, add the things!
			
			lines.push_back(line);
		}
		// Sort the type effects
		std::sort(lines.begin(), lines.end());
		
		languages.swap(lines);
	} else {
		printf("ERROR(1): Could not open file\n");
		return 1;
	}
	printf("done\n");
	return 0;
}
// Accessors
std::vector<int> getIDs() {
	std::vector<int> out;
	int lastID = -100;
	for (int i=0; i<languages.size(); i++) {
		std::vector<std::string> words;
		boost::split(words, languages.at(i), boost::is_any_of(","));
		
		int id = atoi(words.at(0).c_str());
		if ( id != lastID ) {
			out.push_back( id );
			lastID = id;
		}
	}
	return out;
}
std::string getLanguageName(int id, int locale) {
	for (int i=0; i<languages.size(); i++) {
		std::vector<std::string> words;
		boost::split(words, languages.at(i), boost::is_any_of(","));
		
		if ( atoi(words.at(0).c_str()) == id && atoi(words.at(1).c_str()) == locale) {
			return words.at(2);
		}
	}
	return "";
}
// Modifiers
int setLanguage(int id) {
	languageID = id;
}
