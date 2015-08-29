/* Used to handle battles! */

#ifndef BATTLES_BATTLEHANDLER_H_
#define BATTLES_BATTLEHANDLER_H_

#include "../Pokemon/Pokemon.h"

class Battle {
	private:
		char pokemonCount;
		std::vector<BattlePokemon *> playerPokemons;
		std::vector<PartyPokemon *> playerParty;
		std::vector<BattlePokemon *> opponentPokemons;
		std::vector<PartyPokemon *> opponentParty;
		
		// Weather
		unsigned char weather;
		unsigned char weatherRemaining;
		
		// Terrain type
		unsigned char floor;
		unsigned char background;
		
		// Turn data
		int turnCount;
		int lastPriorityRan;
	public:
		// Constructor
		Battle(char pokemonPerSide);
		Battle(char pokemonPerSide, unsigned char weatherState);
		Battle(char pokemonPerSide, unsigned char floorType, unsigned char backgroundType);
		Battle(char pokemonPerSide, unsigned char weatherState, unsigned char floorType, unsigned char backgroundType);
		// Accessors
		BattlePokemon * getNextTurn();
		unsigned char getFloor();
		unsigned char getBackground();
		unsigned char getWeather();
		char getPokemonTotalCount();
		char getPokemonPerSide();
		// Modifiers
		void startNewTurn();
		void endTurn();
		// Runner
		int run();
		int hasWon();
};

#endif
