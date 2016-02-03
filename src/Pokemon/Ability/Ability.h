/* Define the in game abilities of Pokemon
 * 
 * Inherited by Pokemon
 */

// Define guard!
#ifndef ABILITY_ABILITY_H_
#define ABILITY_ABILITY_H_

#include "../../Language/Language.h"

// Ability class
class Ability {
    private:
        // Name of the ability
        std::string m_name;
        std::string m_flavor;

        // Mechanics of the ability
        unsigned char m_percentChance;
        unsigned char m_triggerMechanic;
        unsigned char m_triggerTime;
        unsigned char m_targetMechanic;
        
        // Additional data
        std::vector<unsigned int> m_data; // Additional data that mechanics might need to know
    public:
        Ability();
        ~Ability();

        // Accesors
        inline std::string getName()               { return m_name;            }
        inline std::string getFlavorText()         { return m_flavor;          }
        inline unsigned char getPercentChance()    { return m_percentChance;   }
        inline unsigned char getTriggerMechanic()  { return m_triggerMechanic; }
        inline unsigned char getTriggerTime()      { return m_triggerTime;     }
        inline unsigned char getTargetMechanic()   { return m_targetMechanic;  }

        // Modifiers
        // None included
};

#endif
