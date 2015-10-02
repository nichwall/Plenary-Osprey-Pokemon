/* Loads and defines badges from gyms or other locations if desired */

#pragma once

#include "../Defines.h"

class Badge {
	private:
		// Name for player
		std::string name;
		// Used for the path
		int num;
		// Max level for obeying
		int obeyLevel;
		// Moves allowed outside of battle
		std::vector<int> worldMoves;
	public:
		// Constructors
		Badge();
		Badge(std::string badgeName, int badgeNumber, int maxObeyLevel, std::vector<int> movesInOverworld);
		// Accessors
		std::string getName();
		int getBadgeNumber();
		std::string getPath();
		int getObeyLevel();
		std::vector<int> getAllowedMoves();
		bool isAllowedMove(int moveID);
};
