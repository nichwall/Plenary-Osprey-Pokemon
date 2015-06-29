#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>	/* floor */
#include <time.h>	/* time */
#include <fstream>
#include<unistd.h>

/* Defining every type number here */
#define NORMAL 1
#define FIGHT 2
#define FLYING 3
#define POISON 4
#define GROUND 5
#define ROCK 6
#define BUG 7
#define GHOST 8
#define STEEL 9
#define FIRE 10
#define WATER 11
#define GRASS 12 
#define ELECTRIC 13
#define PSYCHIC 14
#define ICE 15
#define DRAGON 16
#define DARK 17
#define FAIRY 18

/* Defines Egg Groups */
#define EGG_MONSTER		= 0
#define EGG_HUMAN_LIKE	= 1
#define EGG_WATER1		= 2
#define EGG_WATER2		= 3
#define EGG_WATER3		= 4
#define EGG_BUG			= 5
#define EGG_MINERAL		= 6
#define EGG_FLYING		= 7
#define EGG_AMORPHOUS	= 8
#define EGG_FIELD		= 9
#define EGG_FAIRY		= 10
#define EGG_DITTO		= 11
#define EGG_GRASS		= 12
#define EGG_DRAGON		= 13
#define EGG_UNDISCOVERED	= 14
#define EGG_GENDER_UNKNOWN	= 15

/* Defines persistent status conditions */
#define FAINT			1
#define BURN			2
#define FROZEN			4
#define PARALYZED		8
#define POISONED		16
#define BADLYPOISONED	32
#define SLEEP			64

/* Defines volatile status conditions */
#define CONFUSION		1
#define CURSE			2
#define EMBARGO			3
#define ENCORE			4
#define FLINCH			5
#define HEAL_BLOCK		6
#define IDENTIFICATION	7
#define INFATUATION		8
#define NIGHTMARE		9
#define PARTIALLY_TRAPPED	10
#define PERISH_SONG		11
#define SEEDING			12
#define TAUNT			13
#define TELEKINETIC_LEVITATION	14
#define TORMENT			15
#define TRAPPED			16

/* Defines volatile battle status */
#define AQUA_RING		1
#define BRACING			2
#define CENTER_OF_ATTENTION		3
#define DEFENSE_CURL	4
#define GLOWING			5
#define ROOTING			6
#define MAGIC_COAT		7
#define MAGNETIC_LEVITATION		8
#define MINIMIZE		9
#define PROTECTION		10
#define RECHARGING		11
#define SEMI_INVULNERABLE		12
#define SUBSTITUTE		13
#define TAKING_AIM		14
#define TAKING_IN_SUNLIGHT		15
#define WITHDRAWING		16
#define WHIPPING_UP_A_WHIRLWIND	17
#define CLOAKED_IN_HARSH_LIGHT	18

/* Defines IV/EV indices */
#define HP		0
#define ATK		1
#define DEF		2
#define SPATK	3
#define SPDEF	4
#define SPD		5
#define LVL		6

/* Experience Gain groups */
#define ERRATIC		0
#define FAST		1
#define MEDIUMFAST	2
#define MEDIUMSLOW	3
#define SLOW		4
#define FLUCTUATING	5

/* Abilities lookup. This is the InBattle Effects part */
/* Time activated */
#define ALL_TIME		0
#define END_OF_TURN		1
#define ENTER_FIELD		2
#define LEAVE_FIELD		3
#define ACQUIRES_STATUS	4
#define STAT_AFFECTING	5
#define HIT_BY_MOVE		6
#define CONTACT_MADE	7
/* InBattle Identifiers */
#define STAT_AFFECTED
#define WEATHER
//#define 

int checkBit(unsigned int number, int bitNumber);
std::vector<std::string> splitString(std::string toSplit);
std::vector<std::string> splitString(std::string toSplit, std::string delimeter);
