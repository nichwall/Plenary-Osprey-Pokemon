/* Define generations of Pokemon. This can be used with the default configuration
 * files to easily determine which generations can be encountered where, and 
 * also allow ease of mechanics change (generation I,II,III,IV,V,or VI game mechanics)
 * It can also be handy to help exclude specific generations if recreating games
 */

#include <string>

class Generation {
	private:
		int id;
		int main_region_id;
		std::string identifier;
	public:
		// Constructor
		Generation(int genID, int mainRegionID, std::string generationIdentifier) {
			id = genID;
			main_region_id = mainRegionID;
			identifier = generationIdentifier;
		}
		// Destructor
		~Generation() {
		}
		// Accessors
		int getGenerationID() {
			return id;
		}
		int getMainRegionID() {
			return main_region_id;
		}
		std::string getGenerationIdentifier() {
			return identifier;
		}
		// No modifiers right now
};
