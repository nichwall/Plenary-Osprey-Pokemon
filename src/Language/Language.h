// Used to make sure we load the correct frontend for a move

#ifndef LANGUAGE_LANGUAGE_H_
#define LANGUAGE_LANGUAGE_H_

#include "../Defines.h"

extern std::vector<std::string> languages;
extern int languageID;

// Constructors
int loadLanguages();
int loadLanguages(std::string pathToFile);
// Accessors
std::vector<int> getIDs();
std::string getLanguageName(int id, int locale);
// Modifiers
int setLanguage(int id);

#endif
