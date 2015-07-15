/* Keep track of the type effectiveness against each other
 */

#ifndef TYPE_TYPE_EFFICIENCY_H_
#define TYPE_TYPE_EFFICIENCY_H_

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

#include "../Language/Language.h"

// Variables
extern int numberOfTypes;
extern std::vector<std::string> typeEffectivenessMap;

// Functions
int loadTypeEffectivenessMap();
int loadTypeEffectivenessMap(std::string pathToFile);

int getEffectiveness(int attackType, int defenseType);

#endif
