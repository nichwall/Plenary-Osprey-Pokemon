/* Define the in game types of moves and Pokemon
 * 
 * Inherited by Pokemon, Moves
 */

#include <string>

class Type {
	private:
		int type_id;
		std::string type_identifier;
		std::string type_name;
		int generation_id;
		int damage_class_id;
	public:
		// Constructor
		Type(int typeID, std::string typeName, int genID, int damageClassID);
		// Deconstructor
		~Type();
		// Accessors
		int getTypeID();
		std::string getTypeIdentifier();
		int getGenerationID();
		int getDamageClassID();
		// No modifiers at this time
};
