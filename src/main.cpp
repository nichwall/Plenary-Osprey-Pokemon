// g++ -o main main.cpp -lGL -lGLU -lglut -lsfml-system -lsfml-window -lsfml-graphics

#include <SFML/Graphics.hpp>

// Including personal header things
//#include "Player.h"
//#include "Bag.h"
//#include "Item_GenIII.h;

#include "Pokemon/Pokemon.h"
#include "Trainer/Player.h"

/* Get zoom level of the game.
 * Supported levels will be
 * 0.5=Tiny
 * 1.0=Normal
 * 1.5=Large
 * 2.0 = Huge
 */
double zoomLevel=1.0;
int tileHeight=32;
int tileWidth=32;
double frameSkip=1.0;
int backgroundDeltaX;
int backgroundDeltaY;
int arrowPressed=-1;

/* Determine which generation's
 * game engine to use for different
 * parts of the game. Will allow
 * for easier modification/extension
 * when new generations come out or
 * if people want to compine generations. */
int berryEngine=1;
int pokemonEngine=1;
int bagEngine=1;
int itemEngine=1;

//Bag playerBag = Bag(1,zoomLevel);

// Global player Sprite
//Player player (2,0,"Resources/Graphics/Characters/boy_walk.png",192,128,4,4,20,20);

// Bag background
int main() {
	sf::RenderWindow window(sf::VideoMode((int)800*zoomLevel,(int)600*zoomLevel),"Plenary-Osprey Pokemon: Bag v0.1");
	//int currentPocket = 0;
	
	setLanguage(9);
	
	loadTypes();
	loadTypeEffectivenessMap();
	loadMoveMeta();
	constructBaseMoves();
	
	//LearnedMove learned (baseMoves.at(47));
	
	while (1) {
		/* Clear Screen */
		//window.clear(sf::Color::Black);
		/* Draw the things */
//		currentPocket = currentPocket++%8+1;
//		window.draw(playerBag.getBagBackground(currentPocket));
//		window.draw(playerBag.getBagIcon(currentPocket));
		/* Display changes */
		//window.display();
		usleep(100000);
		//printf("Size of movesArray: %d\n",sizeof(movesInGame));
	}
}

