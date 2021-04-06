#include<vector>
#include<list>
#include<map>
#include"Cards.h"
#include"GraphicHandler.h"

#ifndef PLAYER_H
#define  PLAYER_H

class PlayedGame {
public:
	int scorep;
	int scoree;
	std::string enemyName;
	int enemyrating;
	sf::Text text;

	PlayedGame(int _scorep, int _scoree, std::string _enemyName, int _enemyrating) : scorep(_scorep), scoree(_scoree), enemyName(_enemyName), enemyrating(_enemyrating) {
	
		std::string T;

		T.append(std::to_string(scorep));
		T.append(" - ");
		T.append(std::to_string(scoree));
		T.append(" ");
		T.append(enemyName);
		T.append(" ");
		T.append(std::to_string(enemyrating));
		text.setString(T);

		if (scoree < scorep) {
			text.setFillColor(sf::Color::Green);
		}
		else if (scoree == scorep) {
			text.setFillColor(sf::Color::Yellow);
		}
		else {
			text.setFillColor(sf::Color::Red);
		}

		text.setCharacterSize(50);
	
	};

};

class Player {
protected:

	std::string name;
	int rating;
	int id;

public:
	sf::Text nametext;
	sf::Text ratingttext;
	std::list<Card*> activeDeck;
	std::vector<PlayedGame> gameHist;

	Player(std::string _name, std::vector<PlayedGame> history, std::list<Card*> _deck, int _rating, int _id) : name(_name), id(_id), rating(_rating), activeDeck(_deck), gameHist(history) {
	
		nametext.setString(name);
		nametext.setFillColor(sf::Color::White);
		nametext.setCharacterSize(82);

		ratingttext.setString(std::to_string(rating));
		nametext.setCharacterSize(82);
	
	};

	Player(std::string _name, int _rating, int _id) : name(_name), id(_id), rating(_rating) {

		nametext.setString(name);
		nametext.setFillColor(sf::Color::White);
		nametext.setCharacterSize(82);

		ratingttext.setString(std::to_string(rating));
		nametext.setCharacterSize(82);

	};


	std::string getName() { return name; };
	int getRating() { return rating; };
	void setRating(int _rating) { rating = _rating; };
	int getId() { return id; };
	virtual Card* makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics);
};

class ActivePlayer : public Player {

public:
	ActivePlayer(std::string _name, std::vector<PlayedGame> history, std::list<Card*> _deck, int _rating, int _id) : Player( _name, history, _deck, _rating, _id) {};

	ActivePlayer(std::string _name, int _rating, int _id) : Player(_name, _id, _rating) {

		nametext.setString(_name);
		nametext.setFillColor(sf::Color::White);
		nametext.setCharacterSize(82);

		ratingttext.setString(std::to_string(_rating));
		nametext.setCharacterSize(82);

	};

	Card* makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics);
};

class botPlayer : public Player {

public:
	std::map<int, Card*> values;

	botPlayer(std::string _name, int _rating, int _id) : Player(_name, _id, _rating) {
		
		nametext.setString(name);
		nametext.setFillColor(sf::Color::White);
		nametext.setCharacterSize(82);

		ratingttext.setString(std::to_string(rating));
		nametext.setCharacterSize(82);
	};

	int passValue(PlayerBoard& pb, PlayerBoard& enemypb);

	Card* makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics);
};

#endif