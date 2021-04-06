#include <SFML/Graphics.hpp>
#include <list>
#include "Cards.h"
#include "Interface.h"

#ifndef GRAPHICHANDLER_H
#define GRAPHICHANDLER_H

enum State {
	normal,
	focus,
	focushand,
	pchangein,
	pchangeout,
};


class GraphicHandler {

	State currState;
	sf::Time time;

	sf::Font font;

	sf::Text Confirm;

	sf::Texture blackTex;
	sf::Sprite blackSprite;
	sf::Texture bgTex;
	sf::Sprite bgSprite;
	

	void drawNormal(PlayerBoard& pb, PlayerBoard& enemypb);
	void drawFocus(PlayerBoard& pb, PlayerBoard& enemypb);
	void drawFocusHand(PlayerBoard& pb, PlayerBoard& enemypb);
	void drawPlayerOut(PlayerBoard& pb, PlayerBoard& enemypb);
	void drawPlayerIn(PlayerBoard& pb, PlayerBoard& enemypb);

public:
	sf::RenderWindow* mainWindow;
	Card* focused;
	sf::Text pChangeText;


	GraphicHandler(sf::RenderWindow* _mainWindow) {

		if (!font.loadFromFile("points.ttf")) {
			throw ResourceException();
		}

		pChangeText.setFont(font);
		pChangeText.setCharacterSize(100);
		pChangeText.setFillColor(sf::Color::Red);
		
		if (!bgTex.loadFromFile("bg.png")) {
			throw ResourceException();
		}
		bgSprite.setTexture(bgTex);

		if (!blackTex.loadFromFile("black.png")) {
			throw ResourceException();
		}
		blackSprite.setTexture(blackTex);

		focused = nullptr;
		currState = normal;
		mainWindow = _mainWindow;
	};

	void setState(State state) { currState = state; };
	void setTime(sf::Time _time) { time = _time; };

	void draw(PlayerBoard& pb, PlayerBoard& enemypb);
	void drawBoards(PlayerBoard& pb, PlayerBoard& enemypb);


	Card* ClickedCard(int& lane, PlayerBoard& pb, PlayerBoard& enemypb, sf::Vector2i pos);
	int ClickedLane(sf::Vector2i pos);
};





#endif