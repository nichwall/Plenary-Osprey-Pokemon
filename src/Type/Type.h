/* Define the in game types of moves and Pokemon
 * 
 * Inherited by Pokemon, Moves
 */

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

// Variables
std::vector<std::string> typeNames;

// Functions
int loadTypes();
int loadTypes(int languageID);
int loadTypes(std::string pathToFile, int languageID);

std::string getTypeName(int typeIndex);
