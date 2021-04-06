#include "Initializer.h"
#include <iostream>

Initializer::Initializer() {

	if (!font.loadFromFile("maszyna.ttf"))
	{
		throw ResourceException();
	}

	std::ifstream cardsFile("cards/cards.txt");

	if (!cardsFile.is_open()) {
		throw ResourceException();
	}

	loadCards(cardsFile, cardBase);

	botList.emplace_back("CPU", 1500, 0);


	std::ifstream botcards("cards/botdeck.txt");
	if (!botcards.is_open()) {
		throw ResourceException();
	}

	loadCards(botcards, botList.front().activeDeck);
	
	

	int size;

	std::ifstream playersFile("players/players.txt");

	if (!playersFile.is_open()) {
		throw ResourceException();
	}

	playersFile >> size;

	for (int i = 0; i < size; i++) {
		int rating;
		int id;
		std::string name;
		playersFile >> id >> name >> rating;
		
		std::string playerfname;

		playerfname.append("players/");
		playerfname.append(name);
		playerfname.append(std::to_string(id));
		playerfname.append(".txt");

		std::ifstream pcardsstram(playerfname);
		std::list<Card*>deck;
		try {
			loadCards(pcardsstram, deck);
		}
		catch (...) {
			throw ResourceException();
		}
		std::vector<PlayedGame> history;


		loadGames(pcardsstram, history);


		playerList.emplace_back(name, history, deck, rating, id);
	}




}

void Initializer::loadCards(std::ifstream& stream, std::list<Card*>& deck) {
	int size;

	stream >> size;

	for (int i = 0; i < size; i++) {
		int id, lane, attack;
		std::string name, texturefile, type;
		stream >> type >> id >> attack >> lane;
		stream.ignore();

		char c;
		while (stream.peek() != ')') {
			stream.get(c);
			name.push_back(c);
		}

		stream.ignore();

		stream >> texturefile;


		Card* newCard = nullptr;
			

		try {
			newCard = InitCard(type, id, lane, attack, name, texturefile, font);
		}
		catch (...) {
			throw ResourceException();
		}


		deck.push_back(newCard);
	}
}

void Initializer::loadGames(std::ifstream& stream, std::vector<PlayedGame>& history) {

	int size;

	stream >> size;

	for (int i = 0; i < size; i++) {
		int scorep, scoree, enemyrating;
		std::string name;
		stream >> scorep >> scoree >> name >>enemyrating;

		history.emplace_back(scorep, scoree, name, enemyrating);
	}

}

Card* Initializer::InitCard(std::string type, int id, char lane, int attack, std::string& name, std::string texturefile, sf::Font& font)
{

	Card* newCard;
	try {
		if (type == "Card")
			newCard = new Card(id, lane, attack, name, texturefile, font);
		else if (type == "Horn")
			newCard = new Horn(id, lane, attack, name, texturefile, font);
		else if (type == "Desertion")
			newCard = new Desertion(id, lane, attack, name, texturefile, font);
		else if (type == "AirSupport")
			newCard = new AirSupport(id, lane, attack, name, texturefile, font);
		else if (type == "AntiTank")
			newCard = new AntiTank(id, lane, attack, name, texturefile, font);
		else if (type == "HQ")
			newCard = new HQ(id, lane, attack, name, texturefile, font);
		else if (type == "Dummy")
			newCard = new Dummy(id, lane, attack, name, texturefile, font);
		else if (type == "Strike")
			newCard = new Strike(id, lane, attack, name, texturefile, font);
		else if (type == "Spy")
			newCard = new Spy(id, lane, attack, name, texturefile, font);
		else if (type == "Elite")
			newCard = new Elite(id, lane, attack, name, texturefile, font);
		else if (type == "Medic")
			newCard = new Medic(id, lane, attack, name, texturefile, font);
		else if (type == "Brotherhood")
			newCard = new Brotherhood(id, lane, attack, name, texturefile, font);
		else if (type == "Bond")
			newCard = new Bond(id, lane, attack, name, texturefile, font);
		else if (type == "Morale")
			newCard = new Morale(id, lane, attack, name, texturefile, font);
		else
			throw ResourceException();
	}
	catch (...) {
		throw ResourceException();
	}
	
	return newCard;
}

void Initializer::cleanUp() {

	for (auto p : cardBase) {
		delete p;
	}

	for (auto p : playerList) {
		for (auto r : p.activeDeck) {
			delete r;
		}
	}

}
