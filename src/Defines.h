// Defining global defines for the engine

#ifndef DEFINES_H_
#define DEFINES_H_

// Includes
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <math.h>
#include <algorithm>    // std::sort
#include <stdio.h>		// printf
#include <array>

// Egg Groups
#define EGG_MONSTER		1
#define EGG_WATER1		2
#define EGG_WATER2		3
#define EGG_WATER3		4
#define EGG_BUG			5
#define EGG_FLYING		6
#define EGG_FIELD		7
#define EGG_FAIRY		8
#define EGG_GRASS		9
#define EGG_HUMAN_LIKE	10
#define EGG_MINERAL		11
#define EGG_AMORPHOUS	12
#define EGG_DITTO		13
#define EGG_DRAGON		14
#define EGG_UNDISCOVERED	15
#define EGG_GENDER_UNKNOWN	16

// Evolution methods
#define E_FRIENDSHIP_ANY	1
#define E_FRIENDSHIP_DAY	2
#define E_FRIENDSHIP_NIGHT	3
#define E_LEVEL_UP			4
#define E_TRADE_NO_ITEM		5
#define E_TRADE_WITH_ITEM	6
#define E_ITEM_USED			7
#define E_TRADE_ATK_UP		8
#define E_TRADE_ATK_EQ		9
#define E_TRADE_ATK_DOWN	10
#define E_PERSONALITY_VALUE	11
#define E_MAY_SPAWN_ADDIT	12
#define E_SPAWNED			13
#define E_BEAUTY			14

// Defines Stat numbers
// Stat globals begin with "STAT_"
#define STAT_HP			0
#define STAT_ATTACK		1
#define STAT_DEFENSE	2
#define STAT_SP_ATTACK	3
#define STAT_SP_DEFENSE	4
#define STAT_SPEED		5
#define STAT_EVASIVNESS	6
#define STAT_ACCURACY	7

// Defines Pokedex colors
#define COLOR_RED		1
#define COLOR_BLUE		2
#define COLOR_YELLOW	3
#define COLOR_GREEN		4
#define COLOR_BLACK		5
#define COLOR_BROWN		6
#define COLOR_PURPLE	7
#define COLOR_GRAY		8
#define COLOR_WHITE		9
#define COLOR_PINK		10

// Defining learn methods
#define ML_LEVELUP	1
#define ML_TM		2
#define ML_HM		3
#define ML_BREED	4
#define ML_EVOLVED	5
#define ML_TUTOR	6

#endif
