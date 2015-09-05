/* Player trainer data */

#ifndef TRAINER_PLAYER_H_
#define TRAINER_PLAYER_H_

#include "../Defines.h"
#include "Badges.h"

class Player {
	private:
		std::string playerName;
		bool isMale;
		// Trainer ID data
		int trainerID;
		int secretTrainerID;
		
		// Pokemon data
		std::vector<PartyPokemon> party;
		
		// Bag data
		// To be included
		
		// Badges earned
		std::vector<Badge> badges;
		
		unsigned int money;
		
		// Region in world
		unsigned int region_location;
		// Local position in region
		int xPos, yPos;
		
	public:
		Player();
};

#endif
