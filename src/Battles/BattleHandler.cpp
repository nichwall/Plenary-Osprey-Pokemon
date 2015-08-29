// Battle class

#include "BattleHandler.h"

// Constructors
Battle::Battle(char pokemonPerSide) {
	Battle(pokemonPerSide, WEATHER_CLEAR, 0, 0);
}
Battle::Battle(char pokemonPerSide, unsigned char weatherState) {
	Battle(pokemonPerSide, weatherState, 0,0);
}
Battle::Battle(char pokemonPerSide, unsigned char floorType, unsigned char backgroundType) {
	Battle(pokemonPerSide, WEATHER_CLEAR, floorType, backgroundType);
}
Battle::Battle(char pokemonPerSide, unsigned char weatherState, unsigned char floorType, unsigned char backgroundType)
	: pokemonCount(pokemonPerSide),
	  weather(weatherState),
	  floor(floorType),
	  background(backgroundType)
{
	
}
// Accessors
BattlePokemon * Battle::getNextTurn() {
	return playerPokemons.at(0);
}
unsigned char Battle::getFloor() {
	return floor;
}
unsigned char Battle::getBackground() {
	return background;
}
unsigned char Battle::getWeather() {
	return weather;
}
char Battle::getPokemonTotalCount() {
	return pokemonCount*2;
}
char Battle::getPokemonPerSide() {
	return pokemonCount;
}
// Modifiers
void Battle::startNewTurn() {
	turnCount++;
	lastPriorityRan = -10000;
}
void Battle::endTurn() {
	// Decrease weather by one turn
	if (weatherRemaining != 0) {
		weatherRemaining--;
	} else {
		weather = 0;
	}
}
// Runner
int Battle::run() {
	while ( !hasWon() ) {
		startNewTurn();
		for (char i=0; i<pokemonCount*2; i++) {
			BattlePokemon * currentPokemon = getNextTurn();
			// Need to make the move actions
		}
		endTurn();
	}
	return hasWon();
}
int Battle::hasWon() {
	// Check player lost
	char faintedCount = 0;
	for (unsigned int i=0; i<playerParty.size(); i++) {
		if (playerParty.at(i)->getHP() <= 0) {
			faintedCount++;
		}
	}
	if (faintedCount == pokemonCount) {
		return BATTLE_PLAYER_LOSE;
	}
	// Check player won
	faintedCount = 0;
	for (unsigned int i=0; i<opponentParty.size(); i++) {
		if (opponentParty.at(i)->getHP() <= 0) {
			faintedCount++;
		}
	}
	if (faintedCount == pokemonCount) {
		return BATTLE_PLAYER_WIN;
	}
	return BATTLE_PLAYER_NOWIN;
}
