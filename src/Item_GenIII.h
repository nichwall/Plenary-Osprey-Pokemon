#include <SFML/Graphics.hpp>

#include "Pokemon.h"

class Item {
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		/* Item index number */
		int16_t indexNumber;
		/* Buy price of the item */
		int16_t buyPrice;
		/* */
		int8_t holdEffect;
		
		/* How many steps things last, how much restored... */
		std::vector<unsigned int> parameters;
		//uint8_t parameter;
		
		/* Mystery value:
		 * Key item sorta things */
		int16_t mysteryValue;
		
		/* Pocket number */
		int8_t pocket;
		
		/* Type of item (according to Bulbapedia):
		 * 0x0: Mail
		 * 0x1: Items can be used outside of battle
		 * 0x2: Items used only in certain areas
		 * 0x3: Pokeblock
		 * 0x4: Items cannot be used outside of battle
		 * 
		 * Types of Items (that I'm using for now):
		 * 0x0: Pokeball
		 * 0x1: Recovery Items
		 * 0x2: Evolutionary Items
		 * 0x3: Key Items
		 * 0x4: Fossils
		 * 0x5: Stat Items
		 * 0x6: Mail
		 * 0x7: Berries
		 * 1x0: Decorations
		 */
		int16_t type;
		
		/* Usage of items in the field
		 * 0x0: Outside
		 * 0x1: Inside
		 * 0x2: Outside of caves
		 * 0x3: Inside of caves
		 * 0x4: In water
		 * 0x5: During Dive
		 * 0x6: In Mulch
		 */
		int8_t fieldUsage;
		
		/* Battle Usage
		 * 0x0: Can't be used in battle
		 * 0x1: Seen in battle, but subscreen (potion)
		 * 0x2: Seen in battle (pokeball)
		 */
		int16_t battleUsage;
		
		/* Text to display when reading the summary
		 * (bag/battle/etc) */
		std::string flavorText;
		
	public:
		/* Constructors */
		Item (std::string itemData);
		
		/* Accessores */
		sf::Sprite getSprite();
		/*int getItemNumber();
		int getPocket();
		int getBuyPrice();
		int getSellPrice();
		std::string getFlavorText();
		int canHold();
		int canRegister();
		int canUse(int location);*/
		int capturesPokemon(int locationData, BattlePokemon& targetPokemon, BattlePokemon& ownPokemon);
		int getItemType();
};
