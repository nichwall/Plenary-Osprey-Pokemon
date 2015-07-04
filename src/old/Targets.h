/* Define move targets
 * 
 * Inherited by Moves
 */

#include <string>

class Targets {
	private:
		int id;
		std::string identifier;
		std::string name;
		std::string description;
	public:
		// Constructor
		Targets(int targetID, std::string targetIdentifier, std::string targetName, std::string targetDescription) {
			id = targetID;
			identifier = targetIdentifier;
			name = targetName;
			description = targetDescription;
		}
		// Destructor
		~Targets() { }
		// Accessors
		int getTargetID() {
			return id;
		}
		std::string getTargetIdentifier() {
			return identifier;
		}
		std::string getTargetName() {
			return name;
		}
		std::string getTargetDescription() {
			return description;
		}
		// No modifiers at this time
}
