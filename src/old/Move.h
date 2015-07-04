#include "definitions.h"

class BaseMove {
	private:
		std::string moveTitle;
		std::string description;
		unsigned int moveNumber;
		
		/* Determines the type of the move. The first two bits will
		 * check what kind of attack it is
		 * 
		 * (dividing by 128)
		 * 0:	Does not make contact
		 * 1:	Makes contact with target
		 * 
		 * (modding by 128, dividing by 64)
		 * 0:	Physical
		 * 1:	Special
		 * 2:	Status
		 * 
		 * (after modding by 64)
		 * 0:	unknown
		 * Othersiwe, see defines above
		 */
		unsigned char type;
		
		/* For now, Contest things are being left out in order to
		 * help get the game up and going. Eventually it'll be added
		 * back in.
		 * 
		 * 0: Cute
		 * 1: Cool
		 * 2: Beautiful
		 * 3: Tough
		 * 4: Clever */
		
		unsigned char contestCatagory;
		std::vector<unsigned int> contestParameters;
		
		/* Power, accuracy, and base PP */
		unsigned char power;
		unsigned char accuracy;
		
		unsigned char basePP;		
		
		/* Some moves are special. This'll keep track of their info.
		 * 
		 * 0x0: Move makes contact
		 * 0x1: Leaves ground to use move (affected by Gravity)
		 * 0x2:	Gives player money at end of battle (if win) */
		std::vector<unsigned int> parameters;
		
		/* Determines persistent status problems.
		 * 
		 * 0x0-0x3:	probability
		 * 0x4:		Faints (1HKO)
		 * 0x5:		Burn
		 * 0x6:		Frozen
		 * 0x7:		Paralysis
		 * 0x8:		Poison
		 * 0x9:		Badly Poisoned
		 * 0x10:	Sleep
		 */
		unsigned int persistentStatus;
		
		/* Determines if the move will cause volatile status conditions
		 * Because there are only 16 conditions, the first 16 bits will
		 * determine what condition the move causes. The final 16 bits
		 * will determine the probability of the condition occuring.
		 * 
		 * 0x0-0x6:	probability
		 * 0x16:	Confusion
		 * 0x17:	Curse
		 * 0x18:	Embargo
		 * 0x19:	Encore
		 * 0x20:	Flinch
		 * 0x21:	Heal Block
		 * 0x22:	Identification
		 * 0x23:	Infatuation
		 * 0x24:	Nightmare
		 * 0x25:	Partially Trapped
		 * 0x26:	Perish Song
		 * 0x27:	Seeding
		 * 0x28:	Taunt
		 * 0x29:	Telekinectic Levitation
		 * 0x30:	Torment
		 * 0x31:	Trapped
		 * */
		unsigned int volatileStatus;
		
		/* Determines if the move will cause volatile battle status.
		 * Because there are only 18 conditions, we'll use the first 18
		 * bits for keeping track of which condition occurrs.
		 * 
		 * 0x0:		Aqua Ring
		 * 0x1:		Bracing
		 * 0x2:		Center of Attention
		 * 0x3:		Defense Curl
		 * 0x4:		Glowing
		 * 0x5:		Rooting
		 * 0x6:		Magic Coat
		 * 0x7:		Magnetic Levitation
		 * 0x8:		Minimize
		 * 0x9:		Protection
		 * 0x10:	Recharging
		 * 0x11:	Semi-invulnerable
		 * 0x12:	Substitute
		 * 0x13:	Taking aim
		 * 0x14:	Taking in Sunlight
		 * 0x15:	Withdrawing
		 * 0x16:	Whipping up a Whirlwind
		 * 0x17:	Cloaked with Harsh Light
		 */
		unsigned int volatileBattleStatus;
		
		/* 0x0: Targets self
		 * 0x1: Targets ally
		 * 0x2: Targets party
		 * 0x3: Targets left foe
		 * 0x4: Targets right foe
		 * 0x5: Targets both foes
		 * 0x6: Targets everyone else */
		unsigned char targets;
		
		/* Attack Priority.
		 * 0 for normal
		 * positive for earlier
		 * negative for later
		 * 
		 * Range of -127,127 inclusive.*/
		char attackPriority;
	public:
		BaseMove();
		/* For when we're initializing all of the moves during startup
		 * Tab seperated, with the following indices of the line being the following
		 * 
		 * 0:	Move Name
		 * 1:	Move Type
		 * 2:	Contest Type
		 * 3:	Move Power
		 * 4:	Move Accuracy
		 * 5:	
		 */
		BaseMove(std::string lineFromFile);
		BaseMove(std::string moveName, std::string moveDescription, int moveType, int contestType, int movePower, int moveAccuracy, int PP, int maximumPP, int moveTargets);
		~BaseMove();
		
		/* Accessors */
		std::string getMoveName();
		std::string getDescription();
		unsigned int getMoveNumber();
		int getType();
		int getPower();
		int getAccuracy();
		int getTargets();
		int getPP();
		/* Return what volatile status to give to the target */
		int getVolatileStatus();
		int getVolatileBattleStatus();
		/* This will return which status to give target Pokemon. The
		 * check for which to give will be done in here and the
		 * random number will also be created in here. */
		int getPersistentStatus() ;
		/* Checks the effectiveness of this move against a given type */
		double effectiveness(int targetType);
};

class LearnedMove : public BaseMove {
	private:
		/* Keeping track of the delta PP */
		unsigned char currentPP;
		unsigned char ppUpUsed;
	public:
		LearnedMove();
		LearnedMove(std::string constructionString);
		~LearnedMove();
	
		/* Modify PP Ups used */
		int addToPPUp(int additionalPP);
		/* Accessors */
		int getMaxPP();
		int getCurrentPP();
		/* Ether/move used to reset how much PP is left */
		void deltaPP(int PPchange);
		/* Heal to full PP */
		void healPP();
};

/* Keeps track of all moves in game. Probably need to find a
 * better place for this. */
extern std::vector<BaseMove> movesInGame;
