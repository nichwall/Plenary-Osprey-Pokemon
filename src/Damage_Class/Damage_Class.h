/* Keep track of which damage class */

#include <string>
#include <vector>

class Damage_Class {
	private:
		int id;
		std::string name;
		std::string description;
		std::string identifier;
	public:
		// Constructors
		Damage_Class();
		Damage_Class(int classID, std::string classIdentifier, std::string className, std::string classDescription);
		// Destructor
		~Damage_Class();
		// Accessors
		int getDamageClassID();
		std::string getDamageClassName();
		std::string getDamageClassDescription();
		std::string getDamageClassIdentifier();
		// Modifiers
};

std::vector<Damage_Class> damageClass;
int load_Damage_Class();
int load_Damage_Class(std::string pathToConfigFolder);
