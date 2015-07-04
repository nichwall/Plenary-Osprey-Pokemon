/* Stores information on Move Flags
 * 
 * Inherited by Move
 */

class MoveFlag {
	private:
		int id;
		std::string identifier;
		std::string flavorText;
	public:
		// Constructor
		MoveFlag(int moveFlagID, std::string moveFlagIdentifier, std::string moveFlagText) {
			id = moveFlagID;
			identifier = moveFlagIdentifier;
			flavorText = moveFlagText;
		}
		// Deconstructor
		~MoveFlag() { }
		// Accessors
		int getMoveID() {
			return id;
		}
		int getMoveIdentifier() {
			return identifier;
		}
		int getMoveFlavorText() {
			return flavorText();
		}
		// No modifiers at this time
};
