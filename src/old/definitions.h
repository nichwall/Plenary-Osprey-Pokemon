#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>	/* floor */
#include <time.h>	/* time */
#include <fstream>
#include<unistd.h>

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
