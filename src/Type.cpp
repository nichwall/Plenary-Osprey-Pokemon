#include "Type.h"

// Constructor
Type::Type(int typeID, std::string typeName, int genID, int damageClassID) {
	type_id = typeID;
	type_identifier = typeName;
	generation_id = genID;
	damage_class_id = damageClassID;
}
// Destructor
Type::~Type() {
	
}
// Accessors
int Type::getTypeID() {
	return type_id;
}
std::string Type::getTypeIdentifier() {
	return type_identifier;
}
int Type::getGenerationID() {
	return generation_id;
}
int Type::getDamageClassID() {
	return damage_class_id;
}


// Create all of the Type objects
