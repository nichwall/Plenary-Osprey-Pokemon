/* Loads and manages all of the ribbons in the game */

#ifndef RIBBON_RIBBON_H_
#define RIBBON_RIBBON_H_

#include "../Defines.h"

// Struct of a Ribbon
struct Ribbon {
    int identifier;
    std::string name;
};

int loadRibbons();
int loadRibbons(std::string file);
std::string getRibbon(int id);
int getRibbon(std::string ribbonName);

#endif
