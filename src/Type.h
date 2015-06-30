/* Define the in game types of moves and Pokemon
 * 
 * Inherited by Pokemon, Moves
 */

#include <string>

class Type {
	private:
		int type_id;
		std::string type_identifier;
		int generation_id;
		int damage_class_id;
	public:
		// Constructor
		Type(int typeID, std::string typeName, int genID, int damageClassID) {
			type_id = typeID;
			type_identifier = typeName;
			generation_id = genID;
			damage_class_id = damageClassID;
		}
		// Deconstructor
		~Type() {
			
		}
		// Accessors
		int getID() {
			return type_id;
		}
		std::string getIdentifier() {
			return type_identifier;
		}
		int getGenerationID() {
			return generation_id;
		}
		int getDamageClassID() {
			return damage_class_id;
		}
		// No modifiers at this time
};
