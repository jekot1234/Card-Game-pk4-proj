#include<string>
#include<list>
#include<SFML/Graphics.hpp>
#include<fstream>

#ifndef CARDS_H
#define  CARDS_H

class PlayerBoard;
class GraphicHandler;

struct ResourceException : public std::exception {

	const char* what() const throw() {
		return "File load fail!";
	}

};

class Card {
private:

	sf::Texture texture;
	sf::Texture focusTexture;
	std::string filename;
	std::string name;

protected:

	int id;
	int lane;
	int currattack;
	int multiplyer;
	int bonus;
	bool weather;
	int attack;

public:

	sf::Sprite sprite;
	sf::Text nameText;
	sf::Text attackText;
	sf::Sprite focusSprite;

	Card(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font);
	Card(Card& copy);

	virtual Card* clone() { return new Card(*this); };

	int getId() { return id; };
	int getLane() { return lane; };
	int getAttack() { return attack; };
	int getCurrAttack() { return currattack; };
	std::string getName() { return name; };
	std::string getFileName() { return filename; };
	sf::Sprite getFocus() { return focusSprite; };

	void setCurrAttack(int _currattack) { currattack = _currattack; };
	virtual void setMultiplyer(int mul);
	void setWeather(bool w) { weather = w; };

	void setPosition(float x, float y);
	void setBonus(int bon);
	void reset();
	void updatetextpos();
	virtual bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	virtual int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Horn : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Horn(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Horn(Card& copy) : Card(copy) {};

	Card* clone() { return new Horn(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Desertion : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Desertion(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Desertion(Card& copy) : Card(copy) {};

	Card* clone() { return new Desertion(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class AirSupport : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	AirSupport(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	AirSupport(Card& copy) : Card(copy) {};

	Card* clone() { return new AirSupport(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class AntiTank : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	AntiTank(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	AntiTank(Card& copy) : Card(copy) {};

	Card* clone() { return new AntiTank(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class HQ : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	HQ(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	HQ(Card& copy) : Card(copy) {};

	Card* clone() { return new HQ(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Dummy : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Dummy(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Dummy(Card& copy) : Card(copy) {};

	Card* clone() { return new Dummy(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Strike : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Strike(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Strike(Card& copy) : Card(copy) {};

	Card* clone() { return new Strike(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);
};
class Spy : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Spy(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Spy(Card& copy) : Card(copy) {};

	Card* clone() { return new Spy(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Elite : public Card {

public:
	void setMultiplyer(int mul) {};
	Elite(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Elite(Card& copy) : Card(copy) {};

	Card* clone() { return new Elite(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Medic : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Medic(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Medic(Card& copy) : Card(copy) {};

	Card* clone() { return new Medic(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Brotherhood : public Card {

public:
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Brotherhood(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Brotherhood(Card& copy) : Card(copy) {};

	Card* clone() { return new Brotherhood(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Bond : public Card {

public:
	void revoke(PlayerBoard& board);
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Bond(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {};

	Bond(Card& copy) : Card(copy) {};

	Card* clone() { return new Bond(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);

};
class Morale : public Card {

public:
	void revoke(PlayerBoard& board);
	bool playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic);
	Morale(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font)
		: Card(_id, _lane, _attack, _name, texturefile, font) {
		bonus = -1;
	};

	Morale(Card& copy) : Card(copy) {
		bonus = -1;
	};

	Card* clone() { return new Morale(*this); };
	int calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard);
};


class PlayerBoard {
private:

	int lane1Points;
	int lane2Points;
	int lane3Points;
	int playerPoints;

	bool pass;

	bool boolStar1;
	bool boolStar2;
	bool boolStar3;

	bool L1weather;
	bool L2weather;
	bool L3weather;

	sf::Font font;



public:

	int L1bonus;
	int L2bonus;
	int L3bonus;

	sf::Texture cross;
	sf::Texture emptycross;
	sf::Texture star;
	sf::Texture landTex;
	sf::Texture airTex;
	sf::Texture atankTex;
	sf::Texture landInaTex;
	sf::Texture airInaTex;
	sf::Texture atankInaTex;

	std::list<Card*> hand;
	std::list<Card*> deck;
	std::list<Card*> lane1;
	std::list<Card*> lane2;
	std::list<Card*> lane3;
	std::list<Card*> used;

	sf::Sprite cross1;
	sf::Sprite cross2;
	sf::Sprite star1;
	sf::Sprite star2;
	sf::Sprite star3;
	sf::Sprite land;
	sf::Sprite air;
	sf::Sprite atank;

	sf::Text L1points;
	sf::Text L2points;
	sf::Text L3points;
	sf::Text PlayerPoints;
	sf::Text Pass;

	int getPlayerPoints() { return playerPoints; };

	bool getPass() { return pass; };

	bool getStar1() { return boolStar1; };
	bool getStar2() { return boolStar2; };
	bool getStar3() { return boolStar3; };
	
	int getL1bonus() { return L1bonus; };
	int getL2bonus() { return L2bonus; };
	int getL3bonus() { return L3bonus; };

	bool getL1Weather() { return L1weather; };
	bool getL2Weather() { return L2weather; };
	bool getL3Weather() { return L3weather; };


	void setPass(bool _pass) { pass = _pass; };

	void setStar1(bool _star1) { boolStar1 = _star1; };
	void setStar2(bool _star2) { boolStar2 = _star2; };
	void setStar3(bool _star3) { boolStar3 = _star3; };

	void setL1bonus(int bonus) { L1bonus = bonus; };
	void setL2bonus(int bonus) { L2bonus = bonus; };
	void setL3bonus(int bonus) { L3bonus = bonus; };


	void setL1Weather(bool w) { L1weather = w; };
	void setL2Weather(bool w) { L2weather = w; };
	void setL3Weather(bool w) { L3weather = w; };



	PlayerBoard() {
		lane1Points = 0;
		lane2Points = 0;
		lane3Points = 0;
		playerPoints = 0;

		pass = false;
		boolStar1 = false;
		boolStar2 = false;
		boolStar3 = false;

		L1bonus = false;
		L2bonus = false;
		L3bonus = false;

		L1weather = false;
		L2weather = false;
		L3weather = false;
	};
	void updatePos();
	void putCard(Card* card);
	void updateEnempos();
	void initText();
	void initSprites();
	void calculateScore();
	void endRound();


};

#endif

