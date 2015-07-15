// Stores move metadata, to be inherited by Move

#ifndef MOVE_MOVE_METADATA_H_
#define MOVE_MOVE_METADATA_H_

#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf

#include "Move_Damage_Class.h"
#include "../Language/Language.h"

class MoveMeta {
	private:
		int moveID;
		int catagoryID;
		std::string catagory;
		int ailmentID;
		std::string ailment;
		
		int minHits;
		int maxHits;
		int minTurns;
		int maxTurns;
		
		// Percents
		int drain;
		int heal;
		int critRate;
		int ailmentChance;
		int flinchChance;
		int statChance;
		
		// Stat changes
		std::vector<int> statsChanged;
	public:
		// Constructor
		MoveMeta(int move_id, int catagory_id, std::string catagory_name, int ailment_id, std::string ailment_name, int min_hits, int max_hits, int min_turns, int max_turns, int drain_perc, int heal_perc, int crit_rate, int ailment_chance, int flinch_chance, int stat_chance, std::vector<int> stat_deltas);
		// Destructor
		//~MoveMeta();
		// Accessor
		int getMoveID();
		int getMetaCatagoryID();
		int getMetaAilmentID();
		int getMinHits();
		int getMaxHits();
		int getMinTurns();
		int getMaxTurns();
		int getDrainPercent();
		int getHealPercent();
		int getCritRate();
		int getMetaAilmentChance();
		int getFlinchChance();
		int getStatChangeChance();
		std::vector<int> getStatsChanged();
		int getStatDelta(int stat);
		// Modifier
};

extern std::vector<MoveMeta> metas;
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

int loadMoveMeta();
int loadMoveMeta(std::string pathToAilments, std::string pathToCategories, std::string pathToStats, std::string pathToMeta);

#endif
