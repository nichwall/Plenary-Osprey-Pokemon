// Stores move metadata, to be inherited by Move

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

#include "Move_Damage_Class.h"

extern std::vector<std::string> moveMetaAilments;
extern std::vector<std::string> moveMetaCategories;
extern std::vector<std::string> moveMetaStatChanges;

int loadMoveMetaAilments();
int loadMoveMetaAilments(std::string pathToFile);
int loadMoveMetaCategories();
int loadMoveMetaCategories(std::string pathToFile);
int loadMoveMetaStatChanges();
int loadMoveMetaStatChanges(std::string pathToFile);

inline bool isInteger(const std::string & s) {
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

