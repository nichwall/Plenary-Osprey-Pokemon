#include <SFML/Graphics.hpp>
#include <string>
#include "Move.h"

class Pokemon {
	private:
		unsigned int currentHealth;
		std::string nickname;
		
		Move move1;
		Move move2;
		Move move3;
		Move move4;
		
		/* Keep track of the current friendship */
		char friendship;
		
		/* Keep track of the IVs, EVs, and base stats
		 * If the Pokemon has not been captured, we will
		 * store it's EV yield here instead. Upon capture,
		 * the EV stats will be set to 0.
		 * 
		 * 0:	HP
		 * 1:	Atk
		 * 2:	Def
		 * 3:	Sp. Atk
		 * 4:	Sp. Def
		 * 5:	Spd
		 */
		char evs [6];
		char ivs [6];
		char baseStats [6];
		unsigned int experience;
		
		/* Keeps track of the Pokemon type, and because leftover bits,
		 * also store the body type for the Pokedex
		 * 
		 * 0x0-0x4:		Type 1
		 * 0x5-0x9:		Type 2
		 * 0x10-0x14:	Body type
		 */
		char type;
		
		/* Egg Type. Only uses 10 bits, because 5 per egg group, and
		 * there's two types. Use the next three bits to determine
		 * experience gain. Also, because leftover bits, determine
		 * gender with those.
		 * 
		 * Egg Groups:
		 * 0:	Monster
		 * 1:	Human-like
		 * 2:	Water 1
		 * 3:	Water 2
		 * 4:	Water 3
		 * 5:	Bug
		 * 6:	Mineral
		 * 7:	Flying
		 * 8:	Amphorous
		 * 9:	Field
		 * 10:	Fairy
		 * 11:	Ditto
		 * 12:	Grass
		 * 13:	Dragon
		 * 14:	Undiscovered
		 * 15:	Gender Unknown
		 * 
		 * 0x0-0x4:		Egg Group 1
		 * 0x5-0x9:		Egg Group 2
		 * 0x10-0x12:	Experience Gain group
		 * 0x13:		isMale
		 * 0x14:		isFemale
		 */
		unsigned char egg;
		
		/* Number in the Pokedex */
		unsigned int pokedexNum;
		
		/* Making a lookup for this later, because it's going to
		 * be massive.*/
		unsigned char ability;
		
		/* Catch Rate of Pokemon */
		unsigned char catchRate;
		
		/* Dimensions of Pokemon
		 * Contains Height(m)/Weight(kg)
		 * However, because of decimals, divide whatever number
		 * is stored for each by ten in the accessor methods
		 * 
		 * 0x0-0x7:		Height
		 * 0x8-0x23:	Weight
		 */
		unsigned int dimensions;
		
		char pokerusStatus;
	public:
		Pokemon (std::string pokemonData);
		int getPersistentStatusCondition();
		int getCurrentHP();
		int getCatchRate();
		/* Gets stat of Pokemon, based on evs, ivs, baseStats, and
		 * level */
		int getStat(int statIndex);
		int getMaxHP();
		int getCurrentLevel();
		int getTotalXP();
		int getXPtoNextLevel();
		int XPforLevel(int level);
		
		std::string getName();
		std::string getSummary();
		
		/* Get types of the Pokemon */
		int getType1();
		int getType2();
		int isType(int targetType);
		int getBodyType();
		double getHeight();
		double getWeight();
		int getEggGroup1();
		int getEggGroup2();
		
		int isMale();
		int isFemale();
		
		int canEvolve();
		int evolvesInto();
		int getPokedexNumber();
};
