// Pokemon classes

#include "Pokemon.h"

/***********************************************************************************************************************
*	Base Pokemon																									   *
************************************************************************************************************************/

// Constructors
BasePokemon::BasePokemon () {
	
}
BasePokemon::BasePokemon (std::string name, int regionNum, int nationalNum, std::string p_species, char firstType, char secondType,
						  std::vector<evolutionDataStructure> p_evolutions, std::array<char, 6> evYeilds, unsigned int xpYeild,
						  std::array<unsigned char, 6> p_baseStats, char growthRate, char p_eggGroup1, char p_eggGroup2,
						  std::vector<learnMoveDataStruct> p_learnableMoves, unsigned char p_genderRatio, unsigned char p_eggCycles,
						  unsigned int p_HeightAndWeight, unsigned char p_bodyStyle, unsigned char p_pokedexColor,
						  unsigned char p_baseFriend)
	: pokemonName(name),
	  pokedexNumber(regionNum),
	  nationalPokedexNumber(nationalNum),
	  species(p_species),
	  type1(firstType),
	  type2(secondType),
	  evolutions(p_evolutions),
	  evYeild(evYeilds),
	  experienceYield(xpYeild),
	  baseStats(p_baseStats),
	  levelUpEquation(growthRate),
	  eggGroup1(p_eggGroup1),
	  eggGroup2(p_eggGroup2),
	  learnableMoves(p_learnableMoves),
	  genderRatio(p_genderRatio),
	  eggCycles(p_eggCycles),
	  heightAndWeight(p_HeightAndWeight),
	  bodyStyle(p_bodyStyle),
	  pokedexColor(p_pokedexColor),
	  baseFriendship(p_baseFriend)
{
	
}

// Accessors
inline std::string BasePokemon::getPokemonName() {
	return pokemonName;
}
inline int BasePokemon::getRegionalPokedexNumber() {
	return pokedexNumber;
}
inline int BasePokemon::getNationalPokedexNumber() {
	return nationalPokedexNumber;
}
inline std::string BasePokemon::getPokemonSpecies() {
	return species;
}
inline char BasePokemon::getFirstType() {
	return type1;
}
inline char BasePokemon::getSecondType() {
	return type2;
}
inline std::vector<evolutionDataStructure> BasePokemon::getEvolutions() {
	return evolutions;
}
inline std::array<char, 6> BasePokemon::getEvYeild() {
	return evYeild;
}
inline char BasePokemon::getEvYeild(int stat) {
	return evYeild.at(stat);
}
inline unsigned int BasePokemon::getXpYeild() {
	return experienceYield;
}
inline std::array<unsigned char, 6> BasePokemon::getBaseStats() {
	return baseStats;
}
inline unsigned char BasePokemon::getBaseStats(int stat) {
	return baseStats.at(stat);
}
inline char BasePokemon::getGrowthRate() {
	return levelUpEquation;
}
inline std::array<char, 2> BasePokemon::getEggGroups() {
	std::array<char, 2> array = { eggGroup1 , eggGroup2 };
	return array;
}
inline char BasePokemon::getFirstEggGroup() {
	return eggGroup1;
}
inline char BasePokemon::getSecondEggGroup() {
	return eggGroup2;
}
inline std::vector<learnMoveDataStruct> BasePokemon::getLearnableMoves() {
	return learnableMoves;
}
//int canLearn(BaseMove& move);
inline unsigned char BasePokemon::getGenderRatio() {
	return genderRatio;
}
inline unsigned char BasePokemon::getBaseEggCycleCount() {
	return eggCycles;
}
inline unsigned char BasePokemon::getHeight() {
	return heightAndWeight / 65536;
}
inline unsigned char BasePokemon::getWeight() {
	return heightAndWeight % 65536;
}
inline unsigned char BasePokemon::getBodyStyle() {
	return bodyStyle;
}
inline unsigned char BasePokemon::getPokedexColor() {
	return pokedexColor;
}
inline unsigned char BasePokemon::getBaseFriendship() {
	return baseFriendship;
}

/***********************************************************************************************************************
*	Box Pokemon																										   *
************************************************************************************************************************/
BoxPokemon::BoxPokemon() {
	
}

BoxPokemon::BoxPokemon(BasePokemon pokemon, std::string nick, unsigned int p_ivs, std::array<unsigned char, 6> p_evs,
					   unsigned int p_xp, unsigned int p_personalityValue, std::array<LearnedMove, 4> p_moves,
					   uint16_t p_heldItem, unsigned char p_friendship, std::array<unsigned char, 6> p_contestStats,
					   unsigned char p_pokerus, unsigned int origin, unsigned int p_ribbons, unsigned char p_markings)
	: base(pokemon),
	  nickname(nick),
	  ivs(p_ivs),
	  evs(p_evs),
	  experience(p_xp),
	  personalityValue(p_personalityValue),
	  moves(p_moves),
	  heldItem(p_heldItem),
	  friendship(p_friendship),
	  contestStats(p_contestStats),
	  pokerusStatus(p_pokerus),
	  pokemonOrigin(origin),
	  ribbons(p_ribbons),
	  markings(p_markings)
{
	
}
// Accessors
inline BasePokemon BoxPokemon::getBase() {
	return base;
}
inline std::string BoxPokemon::getNickname() {
	return nickname;
}
inline unsigned int BoxPokemon::get_ivs() {
	return ivs;
}
inline unsigned char BoxPokemon::get_iv(unsigned int stat) {
	// FINISH
	switch (stat) {
		case IV_HP:
		case IV_ATTACK:
		case IV_DEFENSE:
		case IV_SPEED:
		case IV_SP_ATTACK:
		case IV_SP_DEFENSE:
			break;
		default:
			return 0;
	}
	return (ivs/stat) % 32;
}
inline std::array<unsigned char, 6> BoxPokemon::get_evs() {
	return evs;
}
inline unsigned char BoxPokemon::get_evs(unsigned int stat) {
	return evs.at(stat);
}
inline uint16_t BoxPokemon::get_stat(char stat) {
	// Calculate HP stat
	if ( stat == STAT_HP ) {
		return ( ( ( get_iv(stat) + (2*getBaseStats(stat)) + (get_evs(stat)/4) + 100 ) * get_level() ) / 100 ) + 10;
	}
	// Otherwise, use the right formula
	return ( ( ( ( get_iv(stat) + (2*getBaseStats(stat)) + (get_evs(stat)/4) ) * get_level() ) / 100 ) + 5 ) * getNatureEffect(stat,getNature());
}
inline unsigned int BoxPokemon::get_experience() {
	return experience;
}
unsigned int BoxPokemon::get_level() {
	int tempLevel = 1;
	unsigned int tempExp = 0;
	
	switch( getGrowthRate() ) {
		case LV_ERRATIC:
			
		case LV_FAST:
			return ( pow((experience * 5/4), 1/3) );
		case LV_M_FAST:
			return ( pow( experience, 1/3) );
		case LV_M_SLOW:
			while ( tempExp < experience ) {
				tempLevel++;
				tempExp = (6/5)*pow(tempLevel,3) - 15*pow(tempLevel,2) + 100*tempLevel - 140;
			}
			return tempLevel;
		case LV_SLOW:
			return ( pow( (experience)*(4/5), 1/3 ) );
		case LV_FLUCTUATE:
			
		default:
			break;
	}
	return 0;
}
inline unsigned int BoxPokemon::getPersonalityValue() {
	return personalityValue;
}
inline char BoxPokemon::isMale() {
	unsigned char genderVal = personalityValue%256;
	// Check if genderless
	if (getGenderRatio() == 255) {
		return -1;
	}
	
	// Return TRUE if male
	return (genderVal > getGenderRatio() );
}
inline char BoxPokemon::isFemale() {
    unsigned char genderVal = personalityValue%256;
    // Check if genderless
    if (getGenderRatio() == 255) {
        return -1;
    }

    // Return TRUE if female
    return (genderVal <= getGenderRatio() );
}
/*
Ability BoxPokemon::getAbility() {
	
}
*/
inline char BoxPokemon::getNature() {
	return personalityValue%25;
}
inline natureEffectStructure BoxPokemon::getNatureEffect(char nature) {
	char statRaised, statLowered;
	// Switch to find the raised stats
	switch (nature) {
		case NAT_LONELY:
		case NAT_BRAVE:
		case NAT_ADAMANT:
		case NAT_NAUGHTY:
			statRaised = STAT_ATTACK;
			break;
		case NAT_BOLD:
		case NAT_RELAXED:
		case NAT_IMPISH:
		case NAT_LAX:
			statRaised = STAT_DEFENSE;
			break;
		case NAT_TIMID:
		case NAT_HASTY:
		case NAT_JOLLY:
		case NAT_NAIVE:
			statRaised = STAT_SPEED;
			break;
		case NAT_MODEST:
		case NAT_MILD:
		case NAT_QUIET:
		case NAT_RASH:
			statRaised = STAT_SP_ATTACK;
			break;
		case NAT_CALM:
		case NAT_GENTLE:
		case NAT_SASSY:
		case NAT_CAREFUL:
			statRaised = STAT_SP_DEFENSE;
			break;
		default:
			statRaised = STAT_NAN;
			break;
	}
	// Switch to find the lowered stat
	switch (nature) {
		case NAT_LONELY:
		case NAT_HASTY:
		case NAT_MILD:
		case NAT_GENTLE:
			statLowered = STAT_DEFENSE;
			break;
		case NAT_BRAVE:
		case NAT_RELAXED:
		case NAT_QUIET:
		case NAT_SASSY:
			statLowered = STAT_SPEED;
			break;
		case NAT_ADAMANT:
		case NAT_IMPISH:
		case NAT_JOLLY:
		case NAT_CAREFUL:
			statLowered = STAT_SP_ATTACK;
			break;
		case NAT_NAUGHTY:
		case NAT_LAX:
		case NAT_NAIVE:
		case NAT_RASH:
			statLowered = STAT_SP_DEFENSE;
			break;
		case NAT_BOLD:
		case NAT_TIMID:
		case NAT_MODEST:
		case NAT_CALM:
			statLowered = STAT_ATTACK;
			break;
		default:
			statLowered = STAT_NAN;
			break;
	}
	// Returning value
	natureEffectStructure temp;
	temp.raised = statRaised;
	temp.lowered = statLowered;
	return temp;
}
inline double BoxPokemon::getNatureEffect(char nature, char stat) {
	// Figure out stat effects
	natureEffectStructure affected = getNatureEffect(nature);
	if (affected.lowered == stat) {
		return 0.9;
	} else if (affected.raised == stat) {
		return 1.1;
	}
	return 1.0;
}
inline char BoxPokemon::getShinyness() {
	// Split the personality value
	int highEnd = personalityValue/65536;
	int lowEnd = personalityValue%65536;
	
	// Get the xor's 	^
	int result = highEnd ^ lowEnd ^ trainerID ^ secretTrainerID;
	
	// Check if it's less than the threshold and return that
	return result < 16;
}
char BoxPokemon::getCharacteristic() {
	char start = personalityValue%6;
	char highestStat = start;
	int highestStatVal = get_stat(start);
	for (char i=++start; i<6; i++) {
		if (get_stat(i) > highestStatVal) {
			highestStat = i;
			highestStatVal = get_stat(i);
		}
	}
	for (char i=0; i<start; i++) {
		if (get_stat(i) > highestStatVal) {
			highestStat = i;
			highestStatVal = get_stat(i);
		}
	}
	return highestStat;
}
char BoxPokemon::getSize() {
	// Get vals from personality value
	int red  = (personalityValue/256) % 256;
	int blue = personalityValue % 256;
	
	// Get stats
	int atk		= get_stat(STAT_ATTACK)%16,
		def		= get_stat(STAT_DEFENSE)%16,
		spd		= get_stat(STAT_SPEED)%16,
		hp		= get_stat(STAT_HP)%16,
		sp_atk	= get_stat(STAT_SP_ATTACK)%16,
		sp_def	= get_stat(STAT_SP_DEFENSE)%16;
		
	// First step
	int s = ( ( (atk ^ def) * hp ) ^ blue ) * 256+ ( ( (sp_atk ^ sp_def) * spd ) ^ red);
	int x,y,z;
	// Lookup tables for the second steps equation!
	switch (s) {
		case 0 ... 9:
			x = 290;
			y = 1;
			z = 0;
			break;
		case 10 ... 109:
			x = 300;
			y = 1;
			z = 10;
			break;
		case 110 ... 309:
			x = 400;
			y = 2;
			z = 110;
			break;
		case 310 ... 709:
			x = 500;
			y = 4;
			z = 310;
			break;
		case 710 ... 2709:
			x = 600;
			y = 20;
			z = 710;
			break;
		case 2710 ... 7709:
			x = 700;
			y = 50;
			z = 2710;
			break;
		case 7710 ... 17709:
			x = 800;
			y = 100;
			z = 7710;
			break;
		case 17710 ... 32709:
			x = 900;
			y = 150;
			z = 17710;
			break;
		case 32710 ... 47709:
			x = 1000;
			y = 150;
			z = 32710;
			break;
		case 47710 ... 57709:
			x = 1100;
			y = 100;
			z = 47710;
			break;
		case 57710 ... 62709:
			x = 1200;
			y = 50;
			z = 57710;
			break;
		case 62710 ... 64709:
			x = 1300;
			y = 20;
			z = 62710;
			break;
		case 64710 ... 65209:
			x = 1400;
			y = 5;
			z = 64710;
			break;
		case 65210 ... 65409:
			x = 1500;
			y = 2;
			z = 65210;
			break;
		case 65410 ... 65535:
			x = 1700;
			y = 1;
			z = 65510;
			break;
	}
	
	// Size in mm, add converter later
	int size = (int)( (s-z) / y + x) * getHeight() / 10;
	return size;
}

inline std::array<LearnedMove, 4> BoxPokemon::getMoves() {
	return moves;
}
inline LearnedMove BoxPokemon::getMove(unsigned int moveIndex) {
	return moves.at(moveIndex);
}
inline uint16_t BoxPokemon::getHeldItem() {
	return heldItem;
}
inline unsigned char BoxPokemon::getFriendship() {
	return friendship;
}
inline std::array<unsigned char, 6> BoxPokemon::getContestStats() {
	return contestStats;
}
inline unsigned char BoxPokemon::getPokerusStatus() {
	return pokerusStatus;
}
inline unsigned char BoxPokemon::getPokerusStrain() {
	return pokerusStatus/16%4;
}
inline unsigned char BoxPokemon::getPokerusRemaining() {
	return pokerusStatus%16;
}
inline int BoxPokemon::isInfectedPokerus() {
	return ( (pokerusStatus/16) != 0 );
}
inline int BoxPokemon::isCuredPokerus() {
	return ( isInfectedPokerus() && ( getPokerusRemaining() == 0) );
}
inline unsigned int BoxPokemon::getOrigin() {
	return pokemonOrigin;
}

inline unsigned int BoxPokemon::getRibbons() {
	return ribbons;
}
inline unsigned char BoxPokemon::getMarkings() {
	return markings;
}
int BoxPokemon::hasMarking(unsigned int mark) {
	switch (mark) {
		case MARK_CIRCLE:
		case MARK_TRIANGLE:
		case MARK_SQUARE:
		case MARK_HEART:
		case MARK_STAR:
		case MARK_DIAMOND:
			break;
		default:
			return -1;
	}
	return ( markings >> mark ) & 1;
}
// Modifiers
inline int BoxPokemon::setNickname(const std::string nick) {
	nickname = nick;
	return 0;
}
// Used to allow items that randomize IVs to work
inline int BoxPokemon::shuffleIVs() {
	return 0;
}
int BoxPokemon::deltaEV(const unsigned char stat, const char delta) {
	switch (stat) {
		case STAT_HP:
		case STAT_ATTACK:
		case STAT_DEFENSE:
		case STAT_SPEED:
		case STAT_SP_ATTACK:
		case STAT_SP_DEFENSE:
			break;
		default:
			return -1;
	}
	if ( (stat < 0) || (stat >= evs.size()) ) {
		return -2;
	}
	if ( ( evs.at(stat) + delta ) > 255 ) {
		evs.at(stat) = 255;
		return 0;
	}
	evs.at(stat) += delta;
	return 0;
}
inline int BoxPokemon::setXP(const unsigned int newXP) {
	experience = newXP;
	return 0;
}
inline int BoxPokemon::deltaXP(const int delta) {
	experience += delta;
	return 0;
}
inline int BoxPokemon::setMove(const LearnedMove move, const int index) {
	unsigned int temp = index;
	if ( (index <0) || (temp >= moves.size()) ) {
		return -2;
	}
	moves.at(index) = move;
	return 0;
}
inline int BoxPokemon::deltaFriendship(const char delta) {
	if ( (delta+friendship) > 255 ) {
		friendship = 255;
		return 0;
	}
	if ( (delta+friendship) < 0 ) {
		friendship = 0;
		return 0;
	}
	friendship += delta;
	return 0;
}
inline uint16_t BoxPokemon::takeItem() {
	uint16_t item = heldItem;
	heldItem = 0;
	return item;
}
inline int BoxPokemon::giveItem(const uint16_t item) {
	// Destroys held item!
	heldItem = item;
	return 0;
}
inline uint16_t BoxPokemon::swapItem(const uint16_t newItem) {
	uint16_t item = heldItem;
	heldItem = newItem;
	return item;
}
int BoxPokemon::deltaContestStats(std::array<unsigned char, 6> deltas) {
	if ( deltas.size() != contestStats.size() ) {
		return -1;
	}
	for (unsigned int i=0; i<deltas.size(); i++) {
		if ( (contestStats.at(i) + deltas.at(i)) > 255 ) {
			contestStats.at(i) = 255;
		} else {
			contestStats.at(i) += deltas.at(i);
		}
	}
	return 0;
}
int BoxPokemon::deltaContestStat(const char delta, const int stat) {
	unsigned int temp = stat;
	if ( (stat < 0) || (temp >= contestStats.size()) ) {
		return -2;
	}
	if (contestStats.at(stat) + delta > 255) {
		contestStats.at(stat) = 255;
		return 0;
	}
	if (contestStats.at(stat) + delta < 0) {
		contestStats.at(stat) = 0;
		return 0;
	}
	contestStats.at(stat) += delta;
	return 0;
}
int BoxPokemon::setContestStats(std::array<unsigned char, 6> newStats) {
	if ( newStats.size() != contestStats.size() ) {
		return -1;
	}
	for (unsigned int i=0; i<newStats.size(); i++) {
		contestStats.at(i) = newStats.at(i);
	}
	return 0;
}
int BoxPokemon::setContestStat(const unsigned char statValue, const int stat) {
	unsigned int temp = stat;
	if ( (stat < 0) || (temp >= contestStats.size()) ) {
		return -2;
	}
	contestStats.at(stat) = statValue;
	return 0;
}
inline int BoxPokemon::pokerusAged() {
	pokerusStatus--;
	return 0;
}
inline int BoxPokemon::setPokerusStrain(const unsigned char strain) {
	pokerusStatus += strain;
	return 0;
}
inline int BoxPokemon::setPokerusDuration(const unsigned char age) {
	pokerusStatus += age;
	return 0;
}
inline int BoxPokemon::setPokerusStatus(const unsigned char pokerus) {
	pokerusStatus = pokerus;
	return 0;
}
inline int BoxPokemon::addRibbon(const unsigned int ribbon) {
	// Need to add, but ribbons aren't critical
	return 0;
}
inline int BoxPokemon::removeRibbon(const unsigned int ribbon) {
	// See above
	return 0;
}
int BoxPokemon::addMarking(const unsigned char mark) {
	switch (mark) {
		case MARK_CIRCLE:
		case MARK_TRIANGLE:
		case MARK_SQUARE:
		case MARK_HEART:
		case MARK_STAR:
		case MARK_DIAMOND:
			break;
		default:
			return -1;
	}
	// Check if it's already set
	if ( ( (markings >> mark) & 1) != 0 ){
		return 0;
	}
	// Otherwise, just add the marking
	markings += mark;
	return 0;
}
int BoxPokemon::removeMarking(unsigned char mark) {
	switch (mark) {
		case MARK_CIRCLE:
		case MARK_TRIANGLE:
		case MARK_SQUARE:
		case MARK_HEART:
		case MARK_STAR:
		case MARK_DIAMOND:
			break;
		default:
			return -1;
	}
	// Check if it's already set
	if ( ( (markings >> mark) & 1) == 0 ){
		return 0;
	}
	// Otherwise, just remove the marking
	markings -= mark;
	return 0;
}

/***********************************************************************************************************************
*	Party Pokemon																									   *
************************************************************************************************************************/
PartyPokemon::PartyPokemon()
{
	
}
PartyPokemon::PartyPokemon(BoxPokemon pokemon)
	: box(pokemon)
{
	unsigned char stat = STNV_NAN;
	PartyPokemon(pokemon, stat);
}
PartyPokemon::PartyPokemon(BoxPokemon pokemon, unsigned char statCondition) {
	PartyPokemon(pokemon, statCondition);
}
PartyPokemon::PartyPokemon(BoxPokemon pokemon, int cHP) {
	PartyPokemon(pokemon, cHP, STNV_NAN);
}
PartyPokemon::PartyPokemon(BoxPokemon pokemon, int cHP, unsigned char statCondition)
	: box(pokemon),
	  currentHP(cHP),
	  statusCondition(statCondition)
{
	// Load stats
	for (int i=0; i<6; i++) {
		stats.at(i) = get_stat(i);
	}
	// Load the level. Note it is BoxPokemon, not PartyPokemon
	level = get_level();
}
// Accessors
/*BoxPokemon * PartyPokemon::getBox() {
	return box;
}*/
BoxPokemon PartyPokemon::getBox() {
    return box;
}
inline unsigned char PartyPokemon::getLevel() {
	return level;
}
inline int PartyPokemon::getHP() {
	return currentHP;
}
inline unsigned char PartyPokemon::getStatusCondition() {
	return statusCondition;
}
// Modifiers/reloads
inline void PartyPokemon::reloadLevel() {
	level = get_level();
}
inline void PartyPokemon::reloadStats() {
	for (int i=0; i<6; i++) {
		stats.at(i) = get_stat(i);
	}
}
inline int PartyPokemon::deltaHealth(int delta) {
	currentHP += delta;
	return currentHP;
}
int PartyPokemon::updateStatusCondition() {
	switch (statusCondition) {
		case STNV_SLEEP_1:
		case STNV_SLEEP_2:
		case STNV_SLEEP_3:
			statusCondition--;
			break;
		default:
			break;
	}
	return statusCondition;
}
inline void PartyPokemon::clearStatusCondition() {
	statusCondition = STNV_NAN;
}

/***********************************************************************************************************************
*	Battle Pokemon																									   *
************************************************************************************************************************/

BattlePokemon::BattlePokemon() {
	
}
BattlePokemon::BattlePokemon(PartyPokemon pokemon)
	: party(pokemon)
{
	
}
// Accessors
inline PartyPokemon BattlePokemon::getPart() {
    return party;
}
