/* Manages Pokemon classes */

#ifndef POKEMON_POKEMON_H_
#define POKEMON_POKEMON_H_

#include "../Language/Language.h"
#include "../Type/Type.h"
#include "../Move/Move.h"
#include "Evolution.h"

// Defines every Pokemon, but just what is required to define one
class BasePokemon {
	private:
		// Pokemon name
		std::string pokemonName;
		// Types of the Pokemon
		char type1;
		char type2;
		
		// Evolution struct
		std::vector<evolutionDataStructure> evolutions;
		
		
	public:
		
};

// Defines Pokemon that have been caught, extends base
class BoxPokemon: public BasePokemon {
	
};

// Defines Pokemon in the party, extends box
class PartyPokemon: public BoxPokemon {
	
};

// Defines Pokemon in battle, extends party
class BattlePokemon: public PartyPokemon {
	
};

#endif
