#include "Pokemon.h"

/* Base Pokemon Stuff */
BasePokemon::BasePokemon() {
	
}
BasePokemon::BasePokemon(std::string constructionString) {
	/* Splits the string based on tabs */
	std::vector<std::string> temp = splitString(constructionString);
	/* Indexes of things in the vector
	 * 
	 * 0:		Pokedex number
	 * 1:		Pokemon name
	 * 2-7:		Base stats
	 * 8:		Base friendship
	 * 9-14:	EV Yield
	 * 15:		Exp Yield
	 * 16:		Ability 1
	 * 17:		Ability 2
	 * 18:		Hidden Ability 1
	 * 19:		Hidden Ability 2
	 * 20:		Experince gain graph
	 * 21:		Gender Threshold
	 * 22:		Height/Weight
	 * 23-32:	Evolution 1-10
	 * 33:		Begin move identifiers ("Move")
	 * 35+n:	Begin move identifiers ("EggMoves")
	 * 36+n:	Begin move identifiers ("TutoredMoves")
	 */
	
	/* Gets the Pokedex number.
	 * atoi:	convert to int
	 * substr:	substring
	 * c_str:	used to convert std::string to c_str, which atoi needs */
	pokedexNumbers = atoi(temp.at(0).c_str());
	/* Creates Pokmeon name */
	name = temp.at(1);
	/* Gets the base stats of the Pokemon */
	for (int i=0; i<6; i++) {
		baseStats[i] = atoi(temp.at(i+2).c_str());
	}
	/* Gets base friendship */
	baseFriendship = atoi(temp.at(8).c_str());
	/* Get EV yield of Pokemon */
	for (int i=0; i<6; i++) {
		evYield[i] = atoi(temp.at(i+9).c_str());
	}
	/* Get exp yield of Pokemon */
	expYield = atoi(temp.at(15).c_str());
	/* What abilities can it have? */
	for (int i=0; i<4; i++) {
		abilities[i] = atoi(temp.at(i+16).c_str());
	}
	
	/* Speed of experience gain */
	experienceGainSpeed = atoi(temp.at(20).c_str());
	/* Gender Threshold */
	genderThreshold = atoi(temp.at(21).c_str());
	/* Size of Pokemon */
	heightAndWeight = atoi(temp.at(22).c_str());
	/* Evolution data structure */
	for (int i=0; i<10; i++) {
		evolutionStructure[i] = atoi(temp.at(i+23).c_str());
	}
	/* Move learnsets */
	int i=0; // For looping on the moves and stuff
	// Get the regular moves, stop when we reach EggMoves
	while (!temp.at(i).compare("EggMoves")) {
		/* Figure out what the element in the "Moves" vector is
		 * Loop through until we get the correct Move, then add
		 * this index to the "move" vectors for easy access later.
		 * Also add the level this move can be learned to the
		 * "levelMovedLearned" vector.
		 */
		for (int j=0; j<movesInGame.size(); j++) {
			if (movesInGame.at(j).getMoveNumber() == atoi(temp.at(i).c_str())) {
				leveledMoves.push_back(j);
				levelMoveLearned.push_back(atoi(temp.at(i+1).c_str()));
				i++;i++;
				break;
			}
		}
	}
	// Get egg moves, stop when we reach TutoredMoves
	while (!temp.at(i).compare("TutoredMoves")) {
		/* Figure out what the element in the "Moves" vector is
		 * Loop through until we get the correct Move, then add
		 * this index to the "eggMoves" vector for easy access later
		 */
		for (int j=0; j<movesInGame.size(); j++) {
			if (movesInGame.at(j).getMoveNumber() == atoi(temp.at(i).c_str())) {
				leveledMoves.push_back(j);
				i++;
				break;
			}
		}
	}
	// Get tutored moves, stop when we reach the end of the array
	while (i<temp.size()) {
		/* Figure out what the element in the "Moves" vector is
		 * Loop through until we get the correct Move, then add
		 * this index to the "eggMoves" vector for easy access later
		 */
		for (int j=0; j<movesInGame.size(); j++) {
			if (movesInGame.at(j).getMoveNumber() == atoi(temp.at(i).c_str())) {
				tutoredMoves.push_back(j);
				i++;
				break;
			}
		}
	}
}
BasePokemon::~BasePokemon() {
	
}

unsigned int BasePokemon::getPokedexNumber() {
	return pokedexNumbers;
}
std::string BasePokemon::getName() {
	return name;
}
int BasePokemon::getCatchRate() {
	return catchRate;
}
int BasePokemon::getFirstType() {
	return firstType;
}
int BasePokemon::getSecondType() {
	return secondType;
}
int BasePokemon::isType(int type) {
	return type==firstType ||  type==secondType;
}
int BasePokemon::getGenderThreshold() {
	return genderThreshold;
}
unsigned int BasePokemon::getHeightAndWeigth() {
	return heightAndWeight;
}
double BasePokemon::getHeight() {
	int height = heightAndWeight/(int)pow(2,31);
	return height/10.0;
}
double BasePokemon::getWeight() {
	int weight = heightAndWeight%(int)pow(2,31);
	return weight/10.0;
}

/* Box Pokemon Stuff */
BoxPokemon::BoxPokemon() {
	
}
BoxPokemon::BoxPokemon(std::string constructionString) {
	
}
BoxPokemon::~BoxPokemon() {
	
}
int BoxPokemon::isMale() {
	unsigned char genderVal = personalityValue%256;
	/* Check if it's genderless */
	if (genderVal==255) {
		return 0;
	}
	/* Otherwise, check if we're above the gender threshold */
	return genderVal>=getGenderThreshold();
}
int BoxPokemon::isFemale() {
	unsigned char genderVal = personalityValue%256;
	/* Check if it's genderless */
	if (genderVal==255) {
		return 0;
	}
	/* Otherwise, check if we're below the gender threshold */
	return genderVal<getGenderThreshold();
}

/* Party Pokemon Stuff! */
PartyPokemon::PartyPokemon() {
	
}
PartyPokemon::PartyPokemon(std::string constructionString) {
	
}
PartyPokemon::~PartyPokemon() {
	
}
int PartyPokemon::getStat(int stat) {
	switch (stat) {
		case HP:
			return getMaxHP();
		case ATK:
			return getAttack();
		case DEF:
			return getDefense();
		case SPATK:
			return getSpecialAttack();
		case SPDEF:
			return getSpecialDefense();
		case SPD:
			return getSpeed();
		default:
			return -1;
	}
}
int PartyPokemon::getAttack() {
	return attack;
}
int PartyPokemon::getDefense() {
	return defense;
}
int PartyPokemon::getSpecialAttack() {
	return specialAttack;
}
int PartyPokemon::getSpecialDefense() {
	return specialDefense;
}
int PartyPokemon::getSpeed() {
	return speed;
}
int PartyPokemon::getMaxHP() {
	return hp;
}
int PartyPokemon::getCurrentHP() {
	return currentHP;
}

int PartyPokemon::getPersistentStatusCondition() {
	return statusCondition;
}

BattlePokemon::BattlePokemon() {
	
}
BattlePokemon::BattlePokemon(std::string constructionString) {
	
}
BattlePokemon::~BattlePokemon() {
	
}

std::vector<BasePokemon> pokemonInGame;
std::vector<BoxPokemon> obtainedPokemon;
