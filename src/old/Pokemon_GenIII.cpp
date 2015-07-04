#include "Pokemon_GenIII.h"
#include <string>

Pokemon::Pokemon(std::string) {
	
}

int Pokemon::getPersistentStatusCondition() {
	return 0;
}
int Pokemon::getMaxHP() {
	if (baseStats[0]==0) {
		return 1;
	}
	return (ivs[0]+baseStats[0]+sqrt(evs[0])/8+50)*getCurrentLevel()/50+10;
}
int Pokemon::getStat(int statIndex) {
	if (statIndex == HP) {
		return getMaxHP();
	} else if (statIndex == LVL) {
		return getCurrentLevel();
	}
	return (ivs[0]+baseStats[0]+sqrt(evs[0])/8)*getCurrentLevel()/50+5;
}
int Pokemon::getCurrentHP() {
	return currentHealth;
}
int Pokemon::getCatchRate() {
	return catchRate;
}
int Pokemon::getCurrentLevel() {
	/* Get the experience gain of the Pokemon */
	switch(egg/1024%8) {
		default:
			return 0;
		case ERRATIC:
			if (experience<131324) {
				/* Loop through the levels until we find a level that works */
				for (int i=1; i<50; i++) {
					if (i*i*i*(100-i)/50 < experience) {
						return i;
					}
				}
				return 50;
			} else if (experience<267406) {
				for (int i=50; i<68; i++) {
					if (i*i*i*(150-i)/100 < experience) {
						return i;
					}
				}
				return 68;
			} else if (experience<583539) {
				for (int i=68; i<98; i++) {
					if (i*i*i*(int)((1911-10*i)/3)/500) {
						return i;
					}
				}
				return 98;
			} else {
				for (int i=98; i<100; i++) {
					if (i*i*i*(160-i)/100 < experience) {
						return i;
					}
				}
				return 100;
			}
		case FAST:
			return 5/4*pow(experience,0.33333);
		case MEDIUMFAST:
			return pow(experience,0.33333);
		case MEDIUMSLOW:
			for (int i=1; i<100; i++) {
				if (6/5*i*i*i-15*i*i+100*i-140 < experience) {
					return i;
				}
			}
			return 100;
		case SLOW:
			return 4/5*pow(experience,0.33333);
		case FLUCTUATING:
			/* Check which range of experience we're in */
			if (experience < 2000) {
				for (int i=1; i<15; i++) {
					if (i*i*i*((int)((i+1)/3)+24)/50 < experience) {
						return i;
					}
				}
				return 15;
			} else if (experience < 50000) {
				for (int i=15; i<36; i++) {
					if (i*i*i*(i+14)/50 < experience) {
						return i;
					}
				}
				return 36;
			} else {
				for (int i=36; i<100; i++) {
					if (i*i*i*((int)((i/3)+32)/50) < experience) {
						return i;
					}
				}
				return 100;
			}
	}
}
int Pokemon::XPforLevel(int level) {
	switch(egg/1024%8) {
		default:
			return 0;
		case ERRATIC:
			if (level<50) {
				return pow(level,3)*(100-level)/50;
			} else if (level<68) {
				return pow(level,3)*(150-level)/100;
			} else if (level<98) {
				return pow(level,3)*(int)((1911-10*level)/3)/500;
			} else {
				return pow(level,3)*(160-level)/100;
			}
		case FAST:
			return 4/5*pow(level,3);
		case MEDIUMFAST:
			return pow(level,3);
		case MEDIUMSLOW:
				return 6/5*pow(level,3)-15*pow(level,2)+100*level-140;
		case SLOW:
			return 5/4*pow(level,3);
		case FLUCTUATING:
			/* Check which range of experience we're in */
			if (level < 15) {
				return pow(level,3)*((int)((level+1)/3)+24)/50;
			} else if (level < 36) {
				return pow(level,3)*(level+14)/50;
			} else {
				return pow(level,3)*((int)((level/3)+32)/50);
			}
	}
}
int Pokemon::getTotalXP() {
	return experience;
}
int Pokemon::getXPtoNextLevel() {
	return XPforLevel(getCurrentLevel()+1) - experience;
}

int Pokemon::getType1() {
	return type%(int)pow(2,5);
}
int Pokemon::getType2() {
	return type/(int)pow(2,5)%(int)pow(2,5);
}
int Pokemon::isType(int targetType) {
	return (targetType == getType1() || targetType == getType2());
}
double Pokemon::getHeight() {
	return (double)(dimensions%(int)pow(2,8)/10.0);
}
double Pokemon::getWeight() {
	return (double)(dimensions/(int)pow(2,8)%(int)pow(2,16)/10.0);
}
int Pokemon::isMale() {
	return checkBit(egg,13);
}
int Pokemon::isFemale() {
	return checkBit(egg,14);
}

int Pokemon::canEvolve() {
	
}
int Pokemon::evolvesInto() {
	
}
int Pokemon::getPokedexNumber() {
	return pokedexNum;
}
