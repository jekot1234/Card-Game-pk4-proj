#include <SFML/Graphics.hpp>
#include "Cards.h"
#ifndef INTERFACE_H
#define INTERFACE_H
class GameInterface {



public:
	sf::Sprite Background;
	Card* focus;
	sf::Text* ConfirmText;
	std::list<sf::Sprite*> stars;

	GameInterface() = default;
	GameInterface(sf::Sprite bg);
};
#endif