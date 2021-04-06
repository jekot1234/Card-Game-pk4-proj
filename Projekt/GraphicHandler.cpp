#include "GraphicHandler.h"

void GraphicHandler::draw(PlayerBoard& pb, PlayerBoard& enemypb) {

	switch (currState) {
	case(normal):
		this->drawNormal(pb, enemypb);
		break;
	case(focus):
		this->drawFocus(pb, enemypb);
		break;
	case(focushand):
		this->drawFocusHand(pb, enemypb);
		break;
	case(pchangein):
		this->drawPlayerIn(pb, enemypb);
		break;
	case(pchangeout):
		this->drawPlayerOut(pb, enemypb);
	}
}

void GraphicHandler::drawNormal(PlayerBoard& pb, PlayerBoard& enemypb) {
	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(bgSprite);

	this->drawBoards(pb, enemypb);

	mainWindow->display();
}

void GraphicHandler::drawFocus(PlayerBoard& pb, PlayerBoard& enemypb) {

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(bgSprite);

	this->drawBoards(pb, enemypb);

	mainWindow->draw(focused->focusSprite);

	mainWindow->display();

}

void GraphicHandler::drawFocusHand(PlayerBoard& pb, PlayerBoard& enemypb) {
	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(bgSprite);

	this->drawBoards(pb, enemypb);

	mainWindow->draw(focused->focusSprite);

	mainWindow->display();


}

void GraphicHandler::drawPlayerOut(PlayerBoard& pb, PlayerBoard& enemypb) {

	blackSprite.setColor(sf::Color(255, 255, 255, time.asMilliseconds() * 255 / 1500));

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(bgSprite);

	this->drawBoards(pb, enemypb);

	mainWindow->draw(blackSprite);

	mainWindow->draw(pChangeText);

	mainWindow->display();
}

void GraphicHandler::drawPlayerIn(PlayerBoard& pb, PlayerBoard& enemypb) {

	blackSprite.setColor(sf::Color(255, 255, 255, (1500 - time.asMilliseconds()) * 255 / 1500 ));

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(bgSprite);

	this->drawBoards(pb, enemypb);

	mainWindow->draw(blackSprite);

	mainWindow->draw(pChangeText);

	mainWindow->display();
}

void GraphicHandler::drawBoards(PlayerBoard& pb, PlayerBoard& enemypb)
{

	for (auto p : pb.hand) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : pb.lane1) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : pb.lane2) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : pb.lane3) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : enemypb.lane1) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : enemypb.lane2) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}
	for (auto p : enemypb.lane3) {
		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}

	mainWindow->draw(pb.L1points);
	mainWindow->draw(pb.L2points);
	mainWindow->draw(pb.L3points);
	mainWindow->draw(enemypb.L1points);
	mainWindow->draw(enemypb.L2points);
	mainWindow->draw(enemypb.L3points);
	mainWindow->draw(pb.PlayerPoints);
	mainWindow->draw(enemypb.PlayerPoints);
	if (enemypb.getPass())
		mainWindow->draw(enemypb.Pass);

	mainWindow->draw(pb.cross1);
	mainWindow->draw(pb.cross2);
	mainWindow->draw(enemypb.cross1);
	mainWindow->draw(enemypb.cross2);

	if (pb.getStar1())
		mainWindow->draw(pb.star1);
	if (pb.getStar2())
		mainWindow->draw(pb.star2);
	if (pb.getStar3())
		mainWindow->draw(pb.star3);
	if (enemypb.getStar1())
		mainWindow->draw(enemypb.star1);
	if (enemypb.getStar2())
		mainWindow->draw(enemypb.star2);
	if (enemypb.getStar3())
		mainWindow->draw(enemypb.star3);


	mainWindow->draw(pb.air);
	mainWindow->draw(pb.atank);
	mainWindow->draw(pb.land);

}

Card* GraphicHandler::ClickedCard(int& lane, PlayerBoard& pb, PlayerBoard& enemypb, sf::Vector2i pos) {

	if (pos.y >= 30 && pos.y <= 150) {
		lane = 7;
		for (std::list<Card*>::reverse_iterator rit = enemypb.lane3.rbegin(); rit != enemypb.lane3.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 170 && pos.y <= 290) {
		lane = 6;
		for (std::list<Card*>::reverse_iterator rit = enemypb.lane2.rbegin(); rit != enemypb.lane2.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 310 && pos.y <= 430) {
		lane = 5;
		for (std::list<Card*>::reverse_iterator rit = enemypb.lane1.rbegin(); rit != enemypb.lane1.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 480 && pos.y <= 600) {
		lane = 4;
		for (std::list<Card*>::reverse_iterator rit = pb.lane1.rbegin(); rit != pb.lane1.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 620 && pos.y <= 740) {
		lane = 3;
		for (std::list<Card*>::reverse_iterator rit = pb.lane2.rbegin(); rit != pb.lane2.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 760 && pos.y <= 880) {
		lane = 2;
		for (std::list<Card*>::reverse_iterator rit = pb.lane3.rbegin(); rit != pb.lane3.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else if (pos.y >= 920 && pos.y <= 1040) {
		lane = 1;
		for (std::list<Card*>::reverse_iterator rit = pb.hand.rbegin(); rit != pb.hand.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				return *rit;
			}
		}
	}
	else {
		return nullptr;
	}
}

int GraphicHandler::ClickedLane(sf::Vector2i pos)
{
	if (pos.x >= 550 && pos.x <= 1550) {
		if (pos.y >= 480 && pos.y <= 600)
			return 1;
		else if (pos.y >= 620 && pos.y <= 740)
			return 2;
		else if (pos.y >= 760 && pos.y <= 880)
			return 3;
		else
			return 0;
	}
	else
		return 0;
}