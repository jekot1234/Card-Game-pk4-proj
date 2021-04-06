#ifndef INITIALIZER_H
#define INITIALIZER_H
#include <SFML/Graphics.hpp>
#include "Cards.h"
#include "Player.h"
#include <fstream>
#include <map>

class Initializer {

public:
	sf::Font font;

	std::list<Card*> cardBase;
	std::list<ActivePlayer> playerList;
	std::list<botPlayer> botList;


	Initializer();
	void loadCards(std::ifstream& stream, std::list<Card*>& deck);
	void loadGames(std::ifstream& stream, std::vector<PlayedGame>& history);
	Card* InitCard(std::string type, int id, char _lane, int attack, std::string& name, std::string texturefile, sf::Font& font);
	void cleanUp();
};


#endif