#include "Damage_Class.h"
#include <sstream>
#include <fstream>
#include <boost/algorithm/string.hpp>

// Constructors
Damage_Class::Damage_Class() {
	id = 0;
	name = "";
	description = "";
	identifier = "";
}
Damage_Class::Damage_Class(int classID, std::string classIdentifier, std::string className, std::string classDescription) {
	id = classID;
	name = className;
	description = classDescription;
	identifier = classIdentifier;
}
// Destructor
Damage_Class::~Damage_Class() { }
// Accessors
int Damage_Class::getDamageClassID() {
	return id;
}
std::string Damage_Class::getDamageClassName() {
	return name;
}
std::string Damage_Class::getDamageClassDescription() {
	return description;
}
std::string Damage_Class::getDamageClassIdentifier() {
	return identifier;
}
// Modifiers


// Generate all Damage_Class objects, and then save into a vector
int load_Damage_Class() {
	std::string pathToFile = "";
	// Open file
	std::ifstream file (pathToFile.c_str());
	if (file.is_open()) {
		std::stringstream strStream;
		strStream << file.rdbuf(); // Read the file
		std::string readed = strStream.str(); // Convert to string
		
		// Split string on lines
		std::vector<std::string> lines;
		boost::split(lines, readed, boost::is_any_of("\n"));
		
		// Check that there's at least 2 lines, because otherwise nothing exists!
		if (lines.size() < 2) {
			return 2;
		}
		
		// Loop through the lines
		for (int i=0; i<lines.size(); i++) {
			std::vector<std::string> temp;
			boost::split(temp, lines.at(i), boost::is_any_of(","));
			
			// Check that we have 2 elements in this array
			if (temp.size() != 2) {
				return 3;
			}
			// Otherwise, let's create the Damage_Class!
			
		}
	} else {
		return 1;
	}
	file.close();
	return 0;
}
