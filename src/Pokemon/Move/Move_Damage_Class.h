/* Keep track of which damage class */

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

#ifndef MOVE_MOVE_DAMAGECLASS_H_
#define MOVE_MOVE_DAMAGECLASS_H_

// Variables
extern std::vector<std::string> damageClass;

// Functions
int load_Damage_Class();
int load_Damage_Class(std::string pathToFile);
std::string getDamageClass(int damageClassID);

#endif
