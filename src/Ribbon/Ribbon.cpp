/* Adds the ribbon instructions */

#include "Ribbon.h"

std::vector<Ribbon> ribbons;

int loadRibbons() {
    return loadRibbons("Resourses/ribbons.csv");
}
int loadRibbons(std::string pathToFile) {
    printf("Loading Ribbons...");

    // Open file
    std::ifstream file (pathToFile.c_str());
    if (file.is_open()) {
        std::string line;
        // Skip the first line
        getline(file, line);

        // Temporary vector of the lines
        std::vector<Ribbon> tempRibbon;
        
        // Loop through the file and get all the lines
        while ( getline(file,line) ) {
            // Split the string
            std::vector<std::string> words;
            boost::split(words, line, boost::is_any_of(","));

            // Check that the vector is the right size
            if (words.size() != 2) {
                printf("ERROR(2): Invalid CSV file\n");
                return 2;
            }
            // Otherwise, add the things!
            Ribbon a;
            if ( is_number(words.at(0)) ) {
                int id = atoi( words.at(0).c_str() );
                a.identifier = id;
                a.name = words.at(1);
                tempRibbon.push_back(a);
            } else {
                printf("ERROR(2): Invalid CSV file\n");
                return 2;
            }
        }
        ribbons.swap(tempRibbon);
        tempRibbon.clear();
    }
}
std::string getRibbon(int id) {
    for (unsigned int i=0; i<id && i<ribbons.size(); i++) {
        if (id == ribbons.at(i).identifier) {
            return ribbons.at(i).name;
        }
    }
    return nullptr;
}
int getRibbon(std::string ribbonName) {
    for (unsigned int i=0; i<ribbons.size(); i++) {
        if ( ribbonName.compare(ribbons.at(i).name) == 0 ) {
            return i;
        }
    }
    return -1;
}
