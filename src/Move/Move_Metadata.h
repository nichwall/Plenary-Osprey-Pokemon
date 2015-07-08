// Stores move metadata, to be inherited by Move

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

std::vector<std::string> moveMetaAilments;
std::vector<std::string> moveMetaCategories;
std::vector<std::string> moveMetaStatChanges;

int loadMoveMetaAilments();
int loadMoveMetaAilments(std::string pathToFile);
int loadMoveMetaCategories();
int loadMoveMetaCategories(std::string pathToFile);
int loadMoveMetaStatChanges();
int loadMoveMetaStatChanges(std::string pathToFile);
