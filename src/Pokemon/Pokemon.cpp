// Pokemon classes

#include "Pokemon.h"

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
std::string BasePokemon::getPokemonName() {
	return pokemonName;
}
int BasePokemon::getRegionalPokedexNumber() {
	return pokedexNumber;
}
int BasePokemon::getNationalPokedexNumber() {
	return nationalPokedexNumber;
}
std::string BasePokemon::getPokemonSpecies() {
	return species;
}
char BasePokemon::getFirstType() {
	return type1;
}
char BasePokemon::getSecondType() {
	return type2;
}
std::vector<evolutionDataStructure> BasePokemon::getEvolutions() {
	return evolutions;
}
std::array<char, 6> BasePokemon::getEvYeild() {
	return evYeild;
}
char BasePokemon::getEvYeild(int stat) {
	return evYeild.at(stat);
}
unsigned int BasePokemon::getXpYeild() {
	return experienceYield;
}
std::array<unsigned char, 6> BasePokemon::getBaseStats() {
	return baseStats;
}
unsigned char BasePokemon::getBaseStats(int stat) {
	return baseStats.at(stat);
}
char BasePokemon::getGrowthRate() {
	return levelUpEquation;
}
std::array<char, 2> BasePokemon::getEggGroups() {
	std::array<char, 2> array = { eggGroup1 , eggGroup2 };
	return array;
}
char BasePokemon::getFirstEggGroup() {
	return eggGroup1;
}
char BasePokemon::getSecondEggGroup() {
	return eggGroup2;
}
std::vector<learnMoveDataStruct> BasePokemon::getLearnableMoves() {
	return learnableMoves;
}
//int canLearn(BaseMove& move);
unsigned char BasePokemon::getGenderRatio() {
	return genderRatio;
}
unsigned char BasePokemon::getBaseEggCycleCount() {
	return eggCycles;
}
unsigned char BasePokemon::getHeight() {
	return heightAndWeight / 65536;
}
unsigned char BasePokemon::getWeight() {
	return heightAndWeight % 65536;
}
unsigned char BasePokemon::getBodyStyle() {
	return bodyStyle;
}
unsigned char BasePokemon::getPokedexColor() {
	return pokedexColor;
}
unsigned char BasePokemon::getBaseFriendship() {
	return baseFriendship;
}

BoxPokemon::BoxPokemon(BasePokemon pokemon)
	: base(&pokemon)
{
	
}

BoxPokemon::BoxPokemon(BasePokemon pokemon, std::string nick, unsigned int p_ivs, std::array<unsigned char, 6> p_evs,
					   unsigned int p_xp, unsigned int p_personalityValue, std::array<LearnedMove, 4> p_moves,
					   uint16_t p_heldItem, unsigned char p_friendship, std::array<unsigned char, 6> p_contestStats,
					   unsigned char p_pokerus, unsigned int origin, unsigned int p_ribbons, unsigned char p_markings)
	: base(&pokemon),
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


