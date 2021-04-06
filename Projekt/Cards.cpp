#include "Cards.h"
#include"GraphicHandler.h"

Card::Card(int _id, int _lane, int _attack, std::string _name, std::string texturefile, sf::Font& font) {

	id = _id;
	lane = _lane;
	attack = _attack;
	currattack = _attack;
	name = _name;
	filename = texturefile;
	weather = false;
	multiplyer = 1;

	std::string texfile = "cards/";
	std::string hqtexture = "cards/";

	texfile.append(texturefile);

	hqtexture.append(texturefile);
	hqtexture.append("hq");
	hqtexture.append(".png");

	texfile.append(".png");

	if (!texture.loadFromFile(texfile)) {
		throw ResourceException();
	}
	if (!focusTexture.loadFromFile(hqtexture)) {
		throw ResourceException();
	}

	attackText.setFillColor(sf::Color::White);
	attackText.setCharacterSize(14);
	attackText.setFont(font);
	if (attack != 0) {
		attackText.setString(std::to_string(attack));
	}
	attackText.setStyle(sf::Text::Bold);


	sprite.setTexture(texture);
	focusSprite.setTexture(focusTexture);

	focusSprite.setPosition(sf::Vector2f(1590.0, 480.0));
}

Card::Card(Card& copy) {

	id = copy.id;
	lane = copy.lane;
	attack = copy.attack;
	currattack = copy.attack;
	name = copy.name;
	sf::Texture copytex(copy.texture);
	texture = std::move(copytex);
	sf::Texture copyfocustex(copy.focusTexture);
	focusTexture = std::move(copyfocustex);

	attackText.setFillColor(sf::Color::White);
	attackText.setCharacterSize(14);
	attackText.setFont(*copy.attackText.getFont());
	if (attack != 0) {
		attackText.setString(std::to_string(attack));
	}
	attackText.setStyle(sf::Text::Bold);


	sprite.setTexture(texture);
	focusSprite.setTexture(focusTexture);

	focusSprite.setPosition(sf::Vector2f(1590.0, 480.0));

}

void Card::setPosition(float x, float y) {

	sf::Vector2f pos(x, y);

	sprite.setPosition(pos);

}

bool Card::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	playerBoard.putCard(this);

	return true;
}

int Card::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	return attack;
}

void Card::updatetextpos() {

	sf::Vector2f cardpos = this->sprite.getPosition();
	sf::Vector2f pos;
	if ((std::to_string(attack).size()) != 1) {
		sf::Vector2f attacktextpos(cardpos.x + 5.0, cardpos.y + 5.0);
		pos = attacktextpos;
	}
	else {
		sf::Vector2f attacktextpos(cardpos.x + 10.0, cardpos.y + 5.0);
		pos = attacktextpos;
	}


	this->attackText.setPosition(pos);

}

void Card::setMultiplyer(int mul) {

	multiplyer += mul;

	int bon = bonus;

	if (bonus < 0) {
		bon = 0;
	}

	if (!weather) {
		currattack = attack * multiplyer + bon;
	}
	else 
		currattack = 1 * multiplyer + bon;




	attackText.setString(std::to_string(currattack));
	if (attack > currattack)
		attackText.setFillColor(sf::Color::Red);
	else if (attack < currattack)
		attackText.setFillColor(sf::Color(255, 192, 5));
	else
		attackText.setFillColor(sf::Color::White);

}

void Card::setBonus(int bon) {
	bonus += bon;
}

void Card::reset() {
	bonus = 0;
	multiplyer = 1;
	weather = false;
	currattack = attack;
	attackText.setString(std::to_string(attack));
	attackText.setFillColor(sf::Color::White);
}

void PlayerBoard::updatePos() {

	float yLane1 = 480;
	float yLane2 = 620;
	float yLane3 = 760;
	float yHand = 920;

	float xLane1 = 580.0;
	float xLane2 = 580.0;
	float xLane3 = 580.0;
	float xHand = 580.0;

	if (lane1.size() <= 8) {
		xLane1 = 1050.0 - (lane1.size() * 0.5 * 100.0 + (lane1.size() - 1) * 0.5 * 20.0);
	}
	if (lane2.size() <= 8) {
		xLane2 = 1050.0 - (lane2.size() * 0.5 * 100.0 + (lane2.size() - 1) * 0.5 * 20.0);
	}
	if (lane3.size() <= 8) {
		xLane3 = 1050.0 - (lane3.size() * 0.5 * 100.0 + (lane3.size() - 1) * 0.5 * 20.0);
	}
	if (hand.size() <= 8) {
		xHand = 1050.0 - (hand.size() * 0.5 * 100.0 + (hand.size() - 1) * 0.5 * 20.0);
	}

	for (auto p : lane1) {
		if (lane1.size() <= 8) {
			p->setPosition(xLane1, yLane1);
			p->updatetextpos();
			xLane1 += 120;
		}
		else {
			p->setPosition(xLane1, yLane1);
			p->updatetextpos();
			xLane1 += 840.0 / (lane1.size() - 1);
		}
	}
	for (auto p : lane2) {
		if (lane2.size() <= 8) {
			p->setPosition(xLane2, yLane2);
			p->updatetextpos();
			xLane2 += 120;
		}
		else {
			p->setPosition(xLane2, yLane2);
			p->updatetextpos();
			xLane2 += 840.0 / (lane2.size() - 1);
		}
	}
	for (auto p : lane3) {
		if (lane3.size() <= 8) {
			p->setPosition(xLane3, yLane3);
			p->updatetextpos();
			xLane3 += 120;
		}
		else {
			p->setPosition(xLane3, yLane3);
			p->updatetextpos();
			xLane3 += 840.0 / (lane3.size() - 1);
		}
	}
	for (auto p : hand) {
		if (hand.size() <= 8) {
			p->setPosition(xHand, yHand);
			p->updatetextpos();
			xHand += 120;
		}
		else {
			p->setPosition(xHand, yHand);
			p->updatetextpos();
			xHand += 840.0 / (hand.size() - 1);
		}
	}

	sf::Vector2f pos(410.0, 505.0);

	sf::FloatRect bounds = L1points.getLocalBounds();
	pos.x -= bounds.width;
	L1points.setPosition(pos);
	pos.x += bounds.width;
	pos.y += 140.0;

	bounds = L2points.getLocalBounds();
	pos.x -= bounds.width;
	L2points.setPosition(pos);
	pos.x += bounds.width;
	pos.y += 140.0;

	bounds = L3points.getLocalBounds();
	pos.x -= bounds.width;
	L3points.setPosition(pos);
	pos.x += bounds.width;

	pos.x = 210;
	pos.y = 470;

	bounds = PlayerPoints.getLocalBounds();
	pos.x -= bounds.width / 2;
	PlayerPoints.setPosition(pos);

	pos.x = 120;
	pos.y = 605;

	cross1.setPosition(pos);
	pos.x = 210;
	cross2.setPosition(pos);

	pos.x = 432.0;
	pos.y = 480.0;
	star1.setPosition(pos);
	pos.y = 620.0;
	star2.setPosition(pos);
	pos.y = 760.0;
	star3.setPosition(pos);

}

void PlayerBoard::putCard(Card* card) {

	switch (card->getLane()) {
	case(1):
		if (boolStar1)
			card->setMultiplyer(1);
		if (L1weather) {
			card->setWeather(true);
			card->setMultiplyer(0);
		}
		if (L1bonus != 0) {
			card->setBonus(L1bonus);
			card->setMultiplyer(0);
		}

		lane1.push_back(card);
		break;
	case(2):
		if (boolStar2)
			card->setMultiplyer(1);
		if (L2weather) {
			card->setWeather(true);
			card->setMultiplyer(0);
		}
		if (L2bonus != 0) {
			card->setBonus(L2bonus);
			card->setMultiplyer(0);
		}

		lane2.push_back(card);
		break;
	case(3):
		if (boolStar3)
			card->setMultiplyer(1);
		if (L3weather) {
			card->setWeather(true);
			card->setMultiplyer(0);
		}
		if (L3bonus != 0) {
			card->setBonus(L1bonus);
			card->setMultiplyer(0);
		}

		lane3.push_back(card);
		break;
	}
}

void PlayerBoard::updateEnempos() {

	float yLane1 = 310;
	float yLane2 = 170;
	float yLane3 = 30;

	float xLane1 = 580.0;
	float xLane2 = 580.0;
	float xLane3 = 580.0;

	if (lane1.size() <= 8) {
		xLane1 = 1050.0 - (lane1.size() * 0.5 * 100.0 + (lane1.size() - 1) * 0.5 * 20.0);
	}
	if (lane2.size() <= 8) {
		xLane2 = 1050.0 - (lane2.size() * 0.5 * 100.0 + (lane2.size() - 1) * 0.5 * 20.0);
	}
	if (lane3.size() <= 8) {
		xLane3 = 1050.0 - (lane3.size() * 0.5 * 100.0 + (lane3.size() - 1) * 0.5 * 20.0);
	}

	for (auto p : lane1) {
		if (lane1.size() <= 8) {
			p->setPosition(xLane1, yLane1);
			p->updatetextpos();
			xLane1 += 120;
		}
		else {
			p->setPosition(xLane1, yLane1);
			p->updatetextpos();
			xLane1 += 840.0 / (lane1.size() - 1);
		}
	}
	for (auto p : lane2) {
		if (lane2.size() <= 8) {
			p->setPosition(xLane2, yLane2);
			p->updatetextpos();
			xLane2 += 120;
		}
		else {
			p->setPosition(xLane2, yLane2);
			p->updatetextpos();
			xLane2 += 840.0 / (lane2.size() - 1);
		}
	}
	for (auto p : lane3) {
		if (lane3.size() <= 8) {
			p->setPosition(xLane3, yLane3);
			p->updatetextpos();
			xLane3 += 120;
		}
		else {
			p->setPosition(xLane3, yLane3);
			p->updatetextpos();
			xLane3 += 840.0 / (lane3.size() - 1);
		}
	}


	sf::Vector2f pos(410.0, 55.0);

	sf::FloatRect bounds = L3points.getLocalBounds();
	pos.x -= bounds.width;
	L3points.setPosition(pos);
	pos.x += bounds.width;
	pos.y += 140.0;

	bounds = L2points.getLocalBounds();
	pos.x -= bounds.width;
	L2points.setPosition(pos);
	pos.x += bounds.width;
	pos.y += 140.0;

	bounds = L1points.getLocalBounds();
	pos.x -= bounds.width;
	L1points.setPosition(pos);
	pos.x += bounds.width;

	pos.x = 210;
	pos.y = 420;

	bounds = PlayerPoints.getLocalBounds();
	pos.x -= bounds.width / 2;
	pos.y -= bounds.height;
	PlayerPoints.setPosition(pos);

	pos.y = 125.0;

	bounds = Pass.getLocalBounds();
	pos.x -= bounds.width / 2;
	pos.y -= bounds.height;
	Pass.setPosition(pos);

	pos.x = 120;
	pos.y = 150;

	cross1.setPosition(pos);
	pos.x = 210;
	cross2.setPosition(pos);

	pos.x = 432.0;
	pos.y = 310.0;
	star1.setPosition(pos);
	pos.y = 170.0;
	star2.setPosition(pos);
	pos.y = 30.0;
	star3.setPosition(pos);

}

void PlayerBoard::initText() {
	if (!font.loadFromFile("points.ttf"))
	{
		throw ResourceException();
	}

	L1points.setFillColor(sf::Color::White);
	L1points.setCharacterSize(57);
	L1points.setFont(font);
	L1points.setString("0");

	L2points.setFillColor(sf::Color::White);
	L2points.setCharacterSize(57);
	L2points.setFont(font);
	L2points.setString("0");

	L3points.setFillColor(sf::Color::White);
	L3points.setCharacterSize(57);
	L3points.setFont(font);
	L3points.setString("0");

	PlayerPoints.setFillColor(sf::Color::White);
	PlayerPoints.setCharacterSize(90);
	PlayerPoints.setFont(font);
	PlayerPoints.setString("0");

	Pass.setFillColor(sf::Color(255, 201, 15));
	Pass.setCharacterSize(90);
	Pass.setFont(font);
	Pass.setString("PASS");
}

void PlayerBoard::initSprites() {

	if (!cross.loadFromFile("cross.png")) {
		throw ResourceException();
	}
	if (!emptycross.loadFromFile("emptycross.png")) {
		throw ResourceException();
	}
	if (!star.loadFromFile("star.png")) {
		throw ResourceException();
	}
	if (!landTex.loadFromFile("land.png")) {
		throw ResourceException();
	}
	if (!airTex.loadFromFile("air.png")) {
		throw ResourceException();
	}
	if (!atankTex.loadFromFile("atank.png")) {
		throw ResourceException();
	}
	if (!landInaTex.loadFromFile("landina.png")) {
		throw ResourceException();
	}
	if (!airInaTex.loadFromFile("airina.png")) {
		throw ResourceException();
	}
	if (!atankInaTex.loadFromFile("atankina.png")) {
		throw ResourceException();
	}

	cross1.setTexture(emptycross);
	cross2.setTexture(emptycross);
	star1.setTexture(star);
	star2.setTexture(star);
	star3.setTexture(star);
	land.setTexture(landInaTex);
	air.setTexture(airInaTex);
	atank.setTexture(atankInaTex);

	land.setPosition(sf::Vector2f(80, 930));
	atank.setPosition(sf::Vector2f(180, 930));
	air.setPosition(sf::Vector2f(280, 930));

}

void PlayerBoard::calculateScore() {
	int L1 = 0;

	for (auto p : lane1) {
		L1 += p->getCurrAttack();
	}

	int L2 = 0;

	for (auto p : lane2) {
		L2 += p->getCurrAttack();
	}

	int L3 = 0;

	for (auto p : lane3) {
		L3 += p->getCurrAttack();
	}

	lane1Points = L1;
	lane2Points = L2;
	lane3Points = L3;

	playerPoints = L1 + L2 + L3;

	L1points.setString(std::to_string(L1));
	L2points.setString(std::to_string(L2));
	L3points.setString(std::to_string(L3));
	PlayerPoints.setString(std::to_string(playerPoints));

}

void PlayerBoard::endRound() {

	pass = false;
	boolStar1 = false;
	boolStar2 = false;
	boolStar3 = false;
	L1weather = false;
	L2weather = false;
	L3weather = false;
	L1bonus = 0;
	L2bonus = 0;
	L3bonus = 0;

	land.setTexture(landInaTex);
	atank.setTexture(atankInaTex);
	air.setTexture(airInaTex);

	for (auto p : lane1) {
		p->reset();
		used.push_back(p);
	}
	lane1.clear();
	for (auto p : lane2) {
		p->reset();
		used.push_back(p);
	}
	lane2.clear();
	for (auto p : lane3) {
		p->reset();
		used.push_back(p);
	}
	lane3.clear();
}

bool Horn::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	sf::Vector2i mouseClickPos;
	int lane;

	while (graphic.mainWindow->isOpen()) {

		sf::Event event;
		while (graphic.mainWindow->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				graphic.mainWindow->close();
		}

		graphic.draw(playerBoard, enemyBoard);



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			mouseClickPos = sf::Mouse::getPosition(*graphic.mainWindow);

			lane = graphic.ClickedLane(mouseClickPos);

			switch (lane) {
			case(1):
				playerBoard.setStar1(true);
				for (auto p : playerBoard.lane1) {
					p->setMultiplyer(1);
				}
				return true;
			case(2):
				playerBoard.setStar2(true);
				for (auto p : playerBoard.lane2) {
					p->setMultiplyer(1);
				}
				return true;
			case(3):
				playerBoard.setStar3(true);
				for (auto p : playerBoard.lane3) {
					p->setMultiplyer(1);
				}
				return true;
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {}
			return false;
		}
	}
}

int Horn::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	return 0;

	int l1value = 0;
	int l2value = 0;
	int l3value = 0;

	for (auto p : playerBoard.lane1) {
		l1value += p->getCurrAttack();
	}
	for (auto p : playerBoard.lane2) {
		l2value += p->getCurrAttack();
	}
	for (auto p : playerBoard.lane3) {
		l3value += p->getCurrAttack();
	}

	if (l1value >= l2value && l1value >= l3value && !playerBoard.getStar1()) {
		return l1value;
	}
	else if (l2value >= l1value && l2value >= l3value && !playerBoard.getStar2()) {
		return l2value;
	}
	else if (l3value >= l1value && l3value >= l2value && !playerBoard.getStar3()) {
		return l3value;
	}
	else
		return 0;
}

bool Desertion::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	enemyBoard.setL1Weather(true);
	for (auto p : enemyBoard.lane1) {
		p->setWeather(true);
		p->setMultiplyer(0);
	}
	enemyBoard.land.setTexture(enemyBoard.landTex);
	return true;
}

int Desertion::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {
	int value = 0;

	for (auto p : enemyBoard.lane1) {
		value += p->getCurrAttack() - 1;
	}

	return value;
}

bool AirSupport::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	enemyBoard.setL3Weather(true);
	for (auto p : enemyBoard.lane3) {
		p->setWeather(true);
		p->setMultiplyer(0);
	}
	enemyBoard.air.setTexture(enemyBoard.airTex);
	return true;
}

int AirSupport::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {
	int value = 0;

	for (auto p : enemyBoard.lane3) {
		value += p->getCurrAttack() - 1;
	}

	return value;
}

bool AntiTank::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	enemyBoard.setL2Weather(true);
	for (auto p : enemyBoard.lane2) {
		p->setWeather(true);
		p->setMultiplyer(0);
	}
	enemyBoard.atank.setTexture(enemyBoard.atankTex);
	return true;
}

int AntiTank::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {
	int value = 0;

	for (auto p : enemyBoard.lane2) {
		value += p->getCurrAttack() - 1;
	}

	return value;
}

bool HQ::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	playerBoard.setL1Weather(false);
	for (auto p : playerBoard.lane1) {
		p->setWeather(false);
		p->setMultiplyer(0);
	}
	playerBoard.land.setTexture(playerBoard.landInaTex);

	playerBoard.setL2Weather(false);
	for (auto p : playerBoard.lane2) {
		p->setWeather(false);
		p->setMultiplyer(0);
	}
	playerBoard.atank.setTexture(playerBoard.atankInaTex);

	playerBoard.setL3Weather(false);
	for (auto p : playerBoard.lane3) {
		p->setWeather(false);
		p->setMultiplyer(0);
	}
	playerBoard.air.setTexture(playerBoard.airInaTex);
	return true;
}

int HQ::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	if (!(playerBoard.getL1Weather() || playerBoard.getL2Weather() || playerBoard.getL3Weather())) {
		return 0;
	}
	else {
		int value = 0;

		if (playerBoard.getL1Weather()) {
			for (auto p : playerBoard.lane1) {
				value += p->getAttack() - 1;
			}
		}
		if (playerBoard.getL2Weather()) {
			for (auto p : playerBoard.lane2) {
				value += p->getAttack() - 1;
			}
		}
		if (playerBoard.getL3Weather()) {
			for (auto p : playerBoard.lane3) {
				value += p->getAttack() - 1;
			}
		}
		return value;
	}
}

bool Dummy::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{

	sf::Vector2i mouseClickPos;
	Card* choice = nullptr;
	int lane;

	while (graphic.mainWindow->isOpen()) {

		sf::Event event;
		while (graphic.mainWindow->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				graphic.mainWindow->close();
		}

		graphic.draw(playerBoard, enemyBoard);



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			mouseClickPos = sf::Mouse::getPosition(*graphic.mainWindow);

			choice = graphic.ClickedCard(lane, playerBoard, enemyBoard, mouseClickPos);

			if (dynamic_cast<Elite*>(choice)) {
				return false;
			}

			if (choice) {
				switch (lane) {
				case(4):
					playerBoard.lane1.remove(choice);
					playerBoard.hand.push_back(choice);
					choice->reset();
					if (auto p = dynamic_cast<Bond*>(choice)) {
						p->revoke(playerBoard);
					}
					else if (auto p = dynamic_cast<Morale*>(choice)) {
						p->revoke(playerBoard);
					}
					playerBoard.lane1.push_back(this);
					return true;
				case(3):
					playerBoard.lane2.remove(choice);
					playerBoard.hand.push_back(choice);
					choice->reset();
					if (auto p = dynamic_cast<Bond*>(choice)) {
						p->revoke(playerBoard);
					}
					else if (auto p = dynamic_cast<Morale*>(choice)) {
						p->revoke(playerBoard);
					}
					playerBoard.lane2.push_back(this);
					return true;
				case(2):
					playerBoard.lane3.remove(choice);
					playerBoard.hand.push_back(choice);
					choice->reset();
					if (auto p = dynamic_cast<Bond*>(choice)) {
						p->revoke(playerBoard);
					}
					else if (auto p = dynamic_cast<Morale*>(choice)) {
						p->revoke(playerBoard);
					}
					playerBoard.lane3.push_back(this);
					return true;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {}
			return false;
		}
	}
}

int Dummy::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	if (playerBoard.getPlayerPoints() + 20 < enemyBoard.getPlayerPoints()) {
		return enemyBoard.getPlayerPoints() - playerBoard.getPlayerPoints();
	}
	else {
		return 0;
	}
}

bool Strike::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{
	int max = 0;

	for (auto p : enemyBoard.lane1) {
		if (p->getCurrAttack() > max) {
			max = p->getCurrAttack();
		}
	}
	for (auto p : enemyBoard.lane2) {
		if (p->getCurrAttack() > max) {
			max = p->getCurrAttack();
		}
	}
	for (auto p : enemyBoard.lane3) {
		if (p->getCurrAttack() > max) {
			max = p->getCurrAttack();
		}
	}
	for (auto i = begin(enemyBoard.lane1); i != end(enemyBoard.lane1);) {

		if (dynamic_cast<Elite*>(*i)) {
			i++;
		}
		else if ((*i)->getCurrAttack() == max) {
			(*i)->reset();
			enemyBoard.used.push_back(*i);

			if (Morale* p = dynamic_cast<Morale*>(*i)) {
				p->revoke(enemyBoard);
			}
			enemyBoard.lane1.erase(i++);
		}
		else
			i++;
	}
	for (auto i = begin(enemyBoard.lane2); i != end(enemyBoard.lane2);) {
		if (dynamic_cast<Elite*>(*i)) {
			i++;
		}
		else if ((*i)->getCurrAttack() == max) {
			(*i)->reset();
			enemyBoard.used.push_back(*i);

			if (Morale* p = dynamic_cast<Morale*>(*i)) {
				p->revoke(enemyBoard);
			}
			enemyBoard.lane2.erase(i++);
		}
		else
			i++;
	}
	for (auto i = begin(enemyBoard.lane3); i != end(enemyBoard.lane3);) {

		if (dynamic_cast<Elite*>(*i)) {
			i++;
		}
		else if ((*i)->getCurrAttack() == max) {
			(*i)->reset();
			enemyBoard.used.push_back(*i);

			if (Morale* p = dynamic_cast<Morale*>(*i)) {
				p->revoke(enemyBoard);
			}
			enemyBoard.lane3.erase(i++);
		}
		else
			i++;
	}


	return true;
}

int Strike::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	int value = 0;

	for (auto p : enemyBoard.lane1) {
		if (p->getCurrAttack() > value) {
			value = p->getCurrAttack();
		}
	}
	for (auto p : enemyBoard.lane2) {
		if (p->getCurrAttack() > value) {
			value = p->getCurrAttack();
		}
	}
	for (auto p : enemyBoard.lane3) {
		if (p->getCurrAttack() > value) {
			value = p->getCurrAttack();
		}
	}

	return value;
}

bool Spy::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{
	enemyBoard.putCard(this);
	playerBoard.hand.push_back(playerBoard.deck.front());
	playerBoard.deck.pop_front();

	return true;
}

int Spy::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {
	return 100;
}

bool Medic::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{
	playerBoard.putCard(this);

	if (!playerBoard.used.empty()) {
		Card* healed = playerBoard.used.back();
		playerBoard.used.pop_back();

		playerBoard.putCard(healed);
	}

	return true;
}

int Medic::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {
	int value = playerBoard.used.back()->getAttack() + this->getAttack();
	return value;
}

bool Brotherhood::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{
	playerBoard.hand.remove(this);

	playerBoard.putCard(this);

	for (auto i = begin(playerBoard.hand); i != end(playerBoard.hand);) {
		if ((*i)->getId() == this->id) {
			playerBoard.putCard(*i);
			playerBoard.hand.erase(i++);
		}
		else
			i++;
	}

	for (auto i = begin(playerBoard.deck); i != end(playerBoard.deck);) {

		if ((*i)->getId() == this->id) {
			playerBoard.putCard(*i);
			playerBoard.deck.erase(i++);
		}
		else
			i++;
	}
	return true;
}

int Brotherhood::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	int value = attack;

	for (auto p : playerBoard.hand) {
		if (p->getId() == id) {
			value += p->getAttack();
		}
	}
	for (auto p : playerBoard.deck) {
		if (p->getId() == id) {
			value += p->getAttack();
		}
	}

	return value;
}

void Bond::revoke(PlayerBoard& board) {

	switch (lane) {
	case(1):
		for (auto p : board.lane1) {
			if (id == p->getId()) {
				p->setMultiplyer(-1);
			}
		}
		break;
	case(2):
		for (auto p : board.lane2) {
			if (id == p->getId()) {
				p->setMultiplyer(-1);
			}
		}
		break;
	case(3):
		for (auto p : board.lane3) {
			if (id == p->getId()) {
				p->setMultiplyer(-1);
			}
		}
		break;
	}
}

bool Bond::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic)
{
	switch (lane) {
	case(1):
		if (playerBoard.getStar1())
			this->setMultiplyer(1);
		if (playerBoard.getL1Weather()) {
			this->setWeather(true);
			this->setMultiplyer(0);
		}
		if (playerBoard.L1bonus) {
			this->setBonus(playerBoard.L1bonus);
			this->setMultiplyer(0);
		}

		for (auto p : playerBoard.lane1) {
			if (this->id == p->getId()) {
				this->setMultiplyer(1);
				p->setMultiplyer(1);
			}
		}

		playerBoard.lane1.push_back(this);
		break;
	case(2):
		if (playerBoard.getStar2())
			this->setMultiplyer(1);
		if (playerBoard.getL2Weather()) {
			this->setWeather(true);
			this->setMultiplyer(0);
		}
		if (playerBoard.L2bonus) {
			this->setBonus(playerBoard.L2bonus);
			this->setMultiplyer(0);
		}

		for (auto p : playerBoard.lane2) {
			if (this->id == p->getId()) {
				this->setMultiplyer(1);
				p->setMultiplyer(1);
			}
		}

		playerBoard.lane2.push_back(this);
		break;
	case(3):
		if (playerBoard.getStar3())
			this->setMultiplyer(1);
		if (playerBoard.getL3Weather()) {
			this->setWeather(true);
			this->setMultiplyer(0);
		}
		if (playerBoard.L3bonus) {
			this->setBonus(playerBoard.L3bonus);
			this->setMultiplyer(0);
		}

		for (auto p : playerBoard.lane3) {
			if (this->id == p->getId()) {
				this->setMultiplyer(1);
				p->setMultiplyer(1);
			}
		}

		playerBoard.lane3.push_back(this);
		break;
	}

	return true;
}

int Bond::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard)
{
	int value = attack;

	if (lane == 1) {
		for (auto p : playerBoard.lane1) {
			if (p->getId() == id) {
				value += attack;
			}
		}
	}
	else if (lane == 2) {
		for (auto p : playerBoard.lane2) {
			if (p->getId() == id) {
				value += attack;
			}
		}
	}
	else if (lane == 3) {
		for (auto p : playerBoard.lane3) {
			if (p->getId() == id) {
				value += attack;
			}
		}
	}

	return value;
}

void Morale::revoke(PlayerBoard& board) {
	
	switch (lane) {
	case(1):
		board.L1bonus -= 1;
		for (auto p : board.lane1) {
			p->setBonus(-1);
			p->setMultiplyer(0);
		}
		break;
	case(2):
		board.L2bonus -= 1;
		for (auto p : board.lane2) {
			p->setBonus(-1);
			p->setMultiplyer(0);
		}
		break;
	case(3):
		board.L3bonus -= 1;
		for (auto p : board.lane3) {
			p->setBonus(-1);
			p->setMultiplyer(0);
		}
		break;
	}

}

bool Morale::playCard(PlayerBoard& playerBoard, PlayerBoard& enemyBoard, GraphicHandler& graphic) {

	playerBoard.putCard(this);

	switch(lane) {
	case(1):
		playerBoard.L1bonus += 1;
		for (auto p : playerBoard.lane1) {
			p->setBonus(1);
			p->setMultiplyer(0);
		}
		break;
	case(2):
		playerBoard.L2bonus += 1;
		for (auto p : playerBoard.lane2) {
			p->setBonus(1);
			p->setMultiplyer(0);
		}
		break;
	case(3):
		playerBoard.L3bonus += 1;
		for (auto p : playerBoard.lane3) {
			p->setBonus(1);
			p->setMultiplyer(0);
		}
		break;
	}

	return true;
}

int Morale::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard) {

	int value = attack;

	if (lane == 1) {
		value += playerBoard.lane1.size();
	}
	else if (lane == 2) {
		value += playerBoard.lane2.size();
	}
	else if (lane == 3) {
		value += playerBoard.lane3.size();
	}


	return value;
}

int Elite::calculateValue(PlayerBoard& playerBoard, PlayerBoard& enemyBoard)
{
	return attack + 2;
}
