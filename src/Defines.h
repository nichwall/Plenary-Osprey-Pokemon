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
#define STAT_NAN		8
#define STAT_HP			0
#define STAT_ATTACK		1
#define STAT_DEFENSE	2
#define STAT_SPEED		3
#define STAT_SP_ATTACK	4
#define STAT_SP_DEFENSE	5
#define STAT_EVASIVNESS	6
#define STAT_ACCURACY	7

// Define IV numbers for stats
#define IV_HP			0
#define IV_ATTACK		32
#define IV_DEFENSE		1024
#define IV_SPEED		32768
#define IV_SP_ATTACK	1048576
#define IV_SP_DEFENSE	33554432

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

// Box/Pokemon Markings
#define MARK_CIRCLE		1
#define MARK_TRIANGLE	2
#define MARK_SQUARE		4
#define MARK_HEART		8
#define MARK_STAR		16
#define MARK_DIAMOND	32

// Contest catagories
#define CONTEST_COOL	1
#define CONTEST_BEAUTY	2
#define CONTEST_CUTE	3
#define CONTEST_CLEVER	4
#define CONTEST_TOUGH	5

// Level up Speed
#define LV_ERRATIC		1
#define LV_FAST			2
#define LV_M_FAST		3
#define LV_M_SLOW		4
#define LV_SLOW			5
#define LV_FLUCTUATE	6

// Natures
#define NAT_HARDY		0
#define NAT_LONELY		1
#define NAT_BRAVE		2
#define NAT_ADAMANT		3
#define NAT_NAUGHTY		4
#define NAT_BOLD		5
#define NAT_DOCILE		7
#define NAT_RELAXED		8
#define NAT_IMPISH		9
#define NAT_LAX			10
#define NAT_TIMID		11
#define NAT_HASTY		12
#define NAT_SERIOUS		13
#define NAT_JOLLY		14
#define NAT_NAIVE		15
#define NAT_MODEST		16
#define NAT_MILD		17
#define NAT_QUIET		18
#define NAT_BASHFUL		19
#define NAT_RASH		20
#define NAT_CALM		21
#define NAT_GENTLE		22
#define NAT_SASSY		23
#define NAT_CAREFUL		24
#define NAT_QUIRKY		25

// Status Conditions (non-volatile)
#define STNV_NAN		0
#define STNV_SLEEP_1	1
#define STNV_SLEEP_2	2
#define STNV_SLEEP_3	3
#define STNV_POISON		4
#define STNV_BURN		5
#define STNV_PARALYSIS	6
#define STNV_FREEZE		7

#endif
