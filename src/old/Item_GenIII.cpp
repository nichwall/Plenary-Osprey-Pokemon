#include "Item_GenIII.h"

/* Constructor
 * We're going to take in the data for the item as
 * a tab delineated string
 * 
 * Indexes are as follows
 * 
 * 0: Item Number
 * 1: Pocket Number
 * 2: buyPrice
 * 3: sellModifier (default .5)
 * 4: positionData */


int Item::getItemType() {
	return type;
}

int Item::capturesPokemon(int location, BattlePokemon& targetPokemon, BattlePokemon& ownPokemon) {
//int Item::capturesPokemon(int location) {
	/* First, check if we're even using a Pokeball.
	 * If we're not, return -1 to let the game know */
	if (getItemType() != 0) {
		return -1;
	}
	
	/* Well, it looks like you're using a Pokeball.
	 * Now we need to start getting info from the
	 * Pokeball data structure. In this engine, the
	 * data is stored in is $parameters
	 * 
	 * The first index of this vector will contain
	 * some important info, such as default things
	 * that will occur if none of the other conditions
	 * are met.
	 * 
	 * 0x31:		Mods catch rate (False: capture rate
	 * 0x30:		Multiplies rate (False: adds)
	 * 
	 * 0x8-0x15:	Base Friendship
	 * 0x7:			Last part of set
	 * 0x0-0x6:		Catch rate (base/failed)
	 */
	
	/* Generate seed for random number generator */
	srand(time(NULL)); 
	
	unsigned int firstIndex = parameters.front();
	/* Get catch rate from the first index */
	unsigned char rate = firstIndex%128;
	
	/* Check status conditions of the target Pokemon
	 * to get bonusStatus */
	double bonusStatus = 1.0;
	switch (targetPokemon.getPersistentStatusCondition()) {
		default:
			break;
		case SLEEP:
		case FROZEN:
			bonusStatus = 2.0;
			break;
		case POISONED:
		case BADLYPOISONED:
		case PARALYZED:
		case BURN:
			bonusStatus = 1.5;
			break;
	}
	
	char hasFailed = 0;
	for (std::vector<unsigned int>::iterator it=parameters.begin(); it!=parameters.end(); ++it) {
		/* Check if this is the final check for the current 
		 * set in the vector. If it is, then check if it
		 * has failed any of the preivous parts of the set.
		 * If it has not failed and is the end, return whether
		 * we caught it. */
		if (hasFailed) {
			if ( checkBit(*it,7) ) {
				hasFailed=0;
			}
			continue;
		}
		/* Because we haven't failed, and we're not at the
		 * end, check whether this condition is met. */
		
		/* 0x29:		Target's Stat
		 * 0x28:		Own Pokemon's Stat
		 * 0x24-0x27:	Stat to check
		 * 0x16:		Target stat higher than user
		 * 0x8-0x15:	Min Stat Diff
		 */
		
		/* Are we checking stat differences? */
		if ( checkBit(*it,29) || checkBit(*it,28) ) {
			int statChecking = *it/(int)pow(2,24)%(int)pow(2,3);
			unsigned char firstStat = targetPokemon.getStat(statChecking);
			unsigned char secondStat = ownPokemon.getStat(statChecking);
			/* If we're not checking the opponents stat, reset it to 0 */
			if ( !checkBit(*it,29) ) {
				firstStat = 0;
			} else if ( !checkBit(*it,28) ) {
				secondStat = 0;
			}
			int differences = abs(firstStat-secondStat);
			int minDiff = *it/(int)pow(2,8)%(int)pow(2,8);
			char targetGreater = checkBit(*it,16);
			/* Check if not enough difference or if the
			 * target needs to be higher but we are. */
			if (minDiff>differences || (targetGreater && secondStat>firstStat) ) {
				hasFailed = 1;
			}
		}
		/* If we're not basing this off of stats, then check bits
		 * 24-29 to get which case we're using.
		 * 
		 * 1:	surf/dive/fishing
		 * 2:	fishing
		 * 3:	type based
		 * 4:	gender affects
		 * 5:	location based
		 * 6:	time based
		 * 7:	light based
		 * 8:	height based
		 * 9:	weight based
		 * 10:	evolves from [item]
		 * 11:	is a certain pokemon
		 * 12:	turn count based
		 */
		else {
			switch (*it/(int)pow(2,24)%(int)pow(2,6)) {
				default:
					break;
				case 1:
				{
					/* Check if we're fishing/diving/surfing.
					 * Check 0x23 of "location" to see if we're
					 * doing any of these.
					 * Also, 0x22 tells us if we're fishing
					 */
					if ( !checkBit(location,23) && !checkBit(location,22) ) {
						hasFailed = 1;
					}
					break;
				}
				case 2:
				{
					/* Check if we're fishing. 0x22 of "location" */
					if ( !checkBit(location,22) ) {
						hasFailed = 1;
					}
					break;
				}
				case 3:
				{
					/* Check opponents type. Type needed will be
					 * from 0x19-0x23. If it doesn't matter what
					 * type, the type in the ball will be 0. */
					int typeFromNumber = *it/(int)pow(2,19)%(int)pow(2,5);
					if (typeFromNumber) {
						if (!targetPokemon.isType(typeFromNumber)) {
							hasFailed = 1;
						}
					}
					/* Check own type. Type needed will be from 
					 * 0x14-0x18. If it doesn't matter what type,
					 * the type in the ball will be 0.
					 */
					typeFromNumber = *it/(int)pow(2,14)%(int)pow(2,5);
					if (typeFromNumber) {
						if (!ownPokemon.isType(typeFromNumber)) {
							hasFailed = 1;
						}
					}
					break;
				}
				case 4:
				{
					/* Check if the genders need to be a certain way.
					 * 0x23:	Opponent is Male
					 * 0x22:	Opponent is Female
					 * 0x21:	Self is Male
					 * 0x20:	Self is Female
					 * 0x19:	Just need to be different
					 */
					if ( checkBit(*it,23) && !targetPokemon.isMale()) {
						hasFailed = 1;
					} else if ( checkBit(*it,22) && !targetPokemon.isFemale()) {
						hasFailed = 1;
					} else if ( checkBit(*it,21) && !ownPokemon.isMale()) {
						hasFailed = 1;
					} else if ( checkBit(*it,20) && !ownPokemon.isFemale()) {
						hasFailed = 1;
					} else if ( checkBit(*it,19) ) {
						if (ownPokemon.isMale()==targetPokemon.isMale() || ownPokemon.isFemale()==targetPokemon.isFemale()) {
							hasFailed = 1;
						}
					}
					break;
				}
				case 5:
				{
					/* Location based.
					 * 
					 * Check if 0x16-0x23 in the vector don't match
					 * 0x16-0x23 in the location argument.
					 */
					if (location/(int)pow(2,23)%(int)pow(2,8) != *it/(int)pow(2,23)%(int)pow(2,8)) {
						hasFailed = 1;
					}
					break;
				}
				case 6:
				{
					/* Time based
					 * (hours)
					 * 
					 * Check if 0x11-0x15 in location argument is
					 * between the values stored in
					 * 0x19-0x23 and 0x14-0x18 in the vector.
					 * 
					 * 0x10 in location will invert the logic so
					 * overnight things will work.
					 */
					int currentTime = location/(int)pow(2,11)%(int)pow(2,5);
					int lowTime = *it/(int)pow(2,19)%(int)pow(2,5);
					int highTime = *it/(int)pow(2,14)%(int)pow(2,5);
					int wrong = 0;
					if (lowTime > currentTime || highTime < currentTime) {
						wrong = 1;
					}
					if (!checkBit(location,10)) {
						wrong = !wrong;
					}
					hasFailed = wrong;
					break;
				}
				case 7:
				{
					/* Light Based
					 * 
					 * Check whether it's dark.
					 * It will be dark in caves and during the night.
					 * Night is from 8PM to 8AM
					 * 
					 * 0x9:		location:	in cave
					 */
					int isDark = 0;
					int time = location/(int)pow(2,11)%(int)pow(2,5);
					if (checkBit(location,9)) {
						isDark = 1;
					} else if (time<8 || 20<=time) {
						isDark = 1;
					}
					/* Check whether we're supposed to be dark */
					if (!checkBit(*it,23)) {
						isDark = !isDark;
					}
					hasFailed = isDark;
					break;
				}
				case 8:
				{
					/* Height based
					 * (meters)
					 * 
					 * Check if the target Pokemon is larger
					 * than the desired height. Height is measured
					 * in meters, but in order to get decimals, all
					 * heights will be divided by 10 to get the
					 * 10ths digit.
					 * 
					 * 0x16-0x23:	Desired height
					 * 0x15:		Shorter than height
					 */
					if (targetPokemon.getHeight() > (double)(*it/(int)pow(2,16)%(int)pow(2,8)/10.0)) {
						if (checkBit(*it,15)) {
							hasFailed = 1;
						}
					} else if (!checkBit(*it,15)) {
						hasFailed = 1;
					}
					break;
				}
				case 9:
				{
					/* Weight based
					 * (kg)
					 * 
					 * Same as above, but use 0x8-0x23 in the current
					 * ball index.
					 * 0x8-0x22:	Desired weight
					 * 0x23:		Lighter than height
					 */
					if (targetPokemon.getWeight() > (double)(*it/(int)pow(2,8)%(int)pow(2,15)/10.0)) {
						if (checkBit(*it,23)) {
							hasFailed = 1;
						}
					} else if (!checkBit(*it,23)) {
						hasFailed = 1;
					}
					break;
				}
				case 10:
				{
					/* Item evolution based
					 * 
					 * Check if target Pokemon evolves from [item]
					 * sometime during it's evolution tree.
					 * 
					 * Still need to figure out how to do this
					 */
					 break;
				}
				case 11:
				{
					/* Check if Pokemon is a certain Pokemon.
					 * 
					 * 0x8-0x23:	NationalPokedexNumber
					 */
					if (targetPokemon.getPokedexNumber() != *it/(int)pow(2,8)%(int)pow(2,16)) {
						hasFailed = 1;
					}
					break;
				}
				case 12:
				{
					/* Turn count based
					 * 
					 * Vector:
					 * 0x8-0x23:	Turn number
					 * 0x10-0x11:	Relation
					 * 		0:	Equal to
					 * 		1:	Less Than
					 * 		2:	Greater Than
					 * 
					 * Location:
					 * 0x0-0x8:		Turn number
					 */
					int turnNumber = location%(int)pow(2,8);
					if (*it/(int)pow(2,10)%(int)pow(2,2) == 0 && turnNumber!=*it/(int)pow(2,8)%(int)pow(2,16)) {
						hasFailed = 1;
					} else if (*it/(int)pow(2,10)%(int)pow(2,2) == 1 && turnNumber>=*it/(int)pow(2,8)%(int)pow(2,16)) {
						hasFailed = 1;
					} else if (*it/(int)pow(2,10)%(int)pow(2,2) == 2 && turnNumber<=*it/(int)pow(2,8)%(int)pow(2,16)) {
						hasFailed = 1;
					}
					break;
				}
			}
		}
	}
	
	/* If everything fails, we'll just return things from the
	 * first index. Also, do this if there's only one index.
	 */
	
	/* Calculate modified catch rate A.
	 * If the flag for catch rate modification is true,
	 * then modify it instead of using the capture rate
	 */
	unsigned char a;
	if ( (firstIndex >> 0) & 1) {
		a = ((3*targetPokemon.getMaxHP()-2*targetPokemon.getCurrentHP())*targetPokemon.getCatchRate()*rate)/(3*targetPokemon.getMaxHP())*bonusStatus;
	} else {
		/* Check if RATE should be inverted */
		if ( (firstIndex >> 1) & 1) {
			rate *= -1;
		}
		unsigned int tempRate = targetPokemon.getCatchRate()+rate;
		/* Catch rate cannot be greater than 255 */
		if (tempRate>255) {
			tempRate = 255;
		}
		a = ((3*targetPokemon.getMaxHP()-2*targetPokemon.getCurrentHP())*tempRate)/(3*targetPokemon.getMaxHP())*bonusStatus;
	}
	/* If A is high enough, it catches the Pokemon regardless */
	unsigned char shakes = 0;
	if (a >= 255) {
		return 4;
	}
	/* Shake probability */
	unsigned char b = 1048560/sqrt(sqrt(16711680/a));
	// Generate random number from 0 to 65535, inclusive
	unsigned int shakeCheck = rand()%65536;
	
	/* Check if we ever fail a shake check.
	 * Add to "shakes" until we either succeed or fail. */
	while (shakes<4 && shakeCheck<b) {
		shakes++;
		shakeCheck = rand()%65536;
	}
	return shakes;
}
