#include "Badges.h"

// Constructors
Badge::Badge() {
	
}
Badge::Badge(std::string badgeName, int badgeNumber, int maxObeyLevel, std::vector<int> movesInOverworld) {
	
}
// Accessors
std::string Badge::getName() {
	return name;
}
int Badge::getBadgeNumber() {
	return num;
}
std::string Badge::getPath() {
	return ""+num;
}
int Badge::getObeyLevel() {
	return obeyLevel;
}
std::vector<int> Badge::getAllowedMoves() {
	return worldMoves;
}
bool Badge::isAllowedMove(int moveID) {
	for (unsigned int i=0; i<worldMoves.size(); i++) {
		if (moveID == worldMoves.at(i)) {
			return true;
		}
	}
	return false;
}
