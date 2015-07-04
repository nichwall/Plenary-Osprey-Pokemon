/* Keep track of the type effectiveness against each other
 */

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

// Variables
int numberOfTypes;
std::vector<std::string> typeEffectivenessMap;

// Functions
int loadTypeEffectivenessMap();
int loadTypeEffectivenessMap(std::string pathToFile);

int getEffectiveness(int attackType, int defenseType);
