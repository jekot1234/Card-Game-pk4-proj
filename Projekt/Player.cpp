#include"Player.h"

Card* ActivePlayer::makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics)
{
	sf::Vector2i mouseClickPos;
	int lane = 0;
	Card* focused = nullptr;
	graphics.setState(normal);

	while (graphics.mainWindow->isOpen()) {

		sf::Event event;
		while (graphics.mainWindow->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				graphics.mainWindow->close();
		}

		graphics.draw(pb, enemypb);



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			mouseClickPos = sf::Mouse::getPosition(*graphics.mainWindow);

			focused = graphics.ClickedCard(lane, pb, enemypb, mouseClickPos);
		}

		if (focused) {

			graphics.focused = focused;
			if (lane == 1) {
				graphics.setState(focushand);

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					return focused;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					return nullptr;
				}

			}
			else {
				graphics.setState(focus);
			}
		}
		else {
			graphics.setState(normal);
		}
	}

	return nullptr;
}

Card* Player::makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics)
{
	return nullptr;
}

int botPlayer::passValue(PlayerBoard& pb, PlayerBoard& enemypb)
{
	int val = 0;

	for (auto p : pb.hand) {
		val += p->getAttack();
	}

	if (val < enemypb.getPlayerPoints())
		return 100;
	else
		return 0;

}

Card* botPlayer::makeChoice(PlayerBoard& pb, PlayerBoard& enemypb, GraphicHandler& graphics)
{

	values.clear();

	for (auto p : pb.hand) {
		values.insert(std::pair <int, Card*> (p->calculateValue(pb, enemypb), p));
	}

	values.insert(std::pair <int, Card*>(passValue(pb, enemypb), nullptr));

	return (*values.rbegin()).second;
}
