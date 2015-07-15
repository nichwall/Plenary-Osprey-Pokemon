/* Define the in game types of moves and Pokemon
 * 
 * Inherited by Pokemon, Moves
 */

// Define guard!
#ifndef TYPE_TYPE_H_
#define TYPE_TYPE_H_

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

#include "TypeEfficiency.h"
#include "../Language/Language.h"

// Variables
extern std::vector<std::string> typeNames;

// Functions
int loadTypes();
int loadTypes(std::string pathToFile);

std::string getTypeName(int typeIndex);

#endif
