/* Class for Egg Groups.
 * 
 * Inherited by Pokemon
 */

#include <string>

class EggGroup {
	private:
		// In game
		int id;
		std::string identifier;
		// Shown to player, if desired
		std::string name;
	public:
		// Constructor
		EggGroup(int eggGroupID, std::string eggGroupIdentifier, std::string eggGroupName) {
			id = eggGroupID;
			identifier = eggGroupIdentifier;
			name = eggGroupName;
		}
		// Destructor
		~EggGroup() {
		}
		// Accessors
		int getID() {
			return id;
		}
		std::string getIdentifier() {
			return identifier;
		}
		std::string getName() {
			return name;
		}
};
