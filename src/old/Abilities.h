#include "definitions.h"

class Ability {
	private:
		/* Name/Flavor of the ability */
		std::string abilityName;
		std::string abilityText;
		unsigned char abilityNumber;
		
		/* Identifying number of ability, used for
		 * overrides and lookup. */
		
		/* In Battle Effects */
		std::vector<unsigned long> inBattle;
		
		/* Out of Battle Effects */
		std::vector<unsigned int> outOfBattle;
		
		/* Abilities that this ability overrides */
		std::vector<unsigned int> overrides;
	public:
		Ability();		
		Ability(std::string constructorString);
		
		unsigned int getAbilityNumber();
		unsigned int isAbilityNumber(int number);
};
