/* The berries!
 * 
 * Extends Items
 */
 
#include <string>

class Firmness {
	private:
		int id;
		std::string identifier;
		std::string name;
	public:
		Firmness(int firmnessID, std::string firmnessIdentifier, std::string firmnessName) {
			id = firmnessID;
			identifier = firmnessIdentifier;
			name = firmnessName;
		}
		// Destructor
		~Firmness() { }
		// Accessors
		int getFirmnessID() {
			return id;
		}
		std::string getFirmnessIdentifier() {
			return identifier;
		}
		std::string getFirmnessName() {
			return name;
		}
		// No Modifiers at this time
};

class Berry {
	private:
		int itemID;
		int firmnessID;
		int naturalGiftPower;
		int naturalGiftTypeID;
		int size;
		char maxHarvest;
		char growthTime;
		char soilDryness;
		char smoothness;
		char taste [6];
	public:
		// Constructor
		Berry(int item_ID, int firmness_ID, int natural_gift_power, int natural_gift_type_ID, int berry_size, char max_harvested, char growth_stage_length, char soil_dryness, char berry_smoothness, char tastes [6]) {
			itemID = 
		}
};
