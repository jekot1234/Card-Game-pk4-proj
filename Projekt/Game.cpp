#include "Game.h"

void Game::GameCycle(GraphicHandler& graphics) {

	p1rounds = 0;
	p2rounds = 0;

	playerB1.updatePos();
	playerB2.updateEnempos();

	std::string changetext = "Runda Gracza\n";
	std::string temp;

	bool round;

	while (p1rounds != 2 && p2rounds != 2) {

		playerB1.setPass(false);
		playerB2.setPass(false);
		playerB1.calculateScore();
		playerB2.calculateScore();

		temp.append(changetext);
		temp.append(player1->getName());
		graphics.pChangeText.setString(temp);
		temp.clear();
		graphics.pChangeText.setPosition(sf::Vector2f(960 - graphics.pChangeText.getLocalBounds().width / 2, 540 - graphics.pChangeText.getLocalBounds().height / 2));


		while (!(playerB1.getPass()) || !(playerB2.getPass())) {
			

			if (!playerB1.getPass()) {

				PlayerChangeIn(graphics, playerB1, playerB2);

				Card* choice;

				round = false;

				if (playerB1.hand.empty())
					playerB1.setPass(true);

				while (!round && graphics.mainWindow->isOpen()) {
					choice = player1->makeChoice(playerB1, playerB2, graphics);

					if (choice == nullptr) {
						playerB1.setPass(true);
						round = true;
					}
					else {
						round = choice->playCard(playerB1, playerB2, graphics);
						if (round) {
							playerB1.hand.remove(choice);
							if (playerB1.hand.empty())
								playerB1.setPass(true);
						}
					}
					playerB1.calculateScore();
					playerB2.calculateScore();
				}
				if (!playerB2.getPass()) {
					temp.append(changetext);
					temp.append(player2->getName());
					graphics.pChangeText.setString(temp);
					temp.clear();
					graphics.pChangeText.setPosition(sf::Vector2f(960 - graphics.pChangeText.getLocalBounds().width / 2, 540 - graphics.pChangeText.getLocalBounds().height / 2));
				}

				PlayerChangeOut(graphics, playerB1, playerB2);
			}

			

			if (!playerB2.getPass()) {

				PlayerChangeIn(graphics, playerB2, playerB1);

				playerB2.updatePos();
				playerB1.updateEnempos();

				Card* choice;

				round = false;

				if (playerB2.hand.empty())
					playerB2.setPass(true);

				while (!round && graphics.mainWindow->isOpen()) {
					choice = player2->makeChoice(playerB2, playerB1, graphics);

					if (choice == nullptr) {
						playerB2.setPass(true);
						round = true;
					}
					else {
						round = choice->playCard(playerB2, playerB1, graphics);
						if (round) {
							playerB2.hand.remove(choice);
							if (playerB2.hand.empty())
								playerB2.setPass(true);
						}

					}
					playerB1.calculateScore();
					playerB2.calculateScore();
				}
				if (!playerB1.getPass()) {

					temp.append(changetext);
					temp.append(player1->getName());
					graphics.pChangeText.setString(temp);
					temp.clear();
					graphics.pChangeText.setPosition(sf::Vector2f(960 - graphics.pChangeText.getLocalBounds().width / 2, 540 - graphics.pChangeText.getLocalBounds().height / 2));
				}


				PlayerChangeOut(graphics, playerB2, playerB1);
			}
		}
		playerB1.endRound();
		playerB2.endRound();

		if (playerB1.getPlayerPoints() > playerB2.getPlayerPoints())
			p1rounds++;
		else if (playerB2.getPlayerPoints() > playerB1.getPlayerPoints())
			p2rounds++;
		else if (playerB1.getPlayerPoints() == playerB2.getPlayerPoints()) {
			p1rounds++;
			p2rounds++;
		}

		if (p1rounds == 1) {
			playerB1.cross1.setTexture(playerB1.cross);
		}
		if (p2rounds == 1) {
			playerB2.cross1.setTexture(playerB2.cross);
		}
		if (p1rounds == 2) {
			playerB1.cross2.setTexture(playerB1.cross);
		}
		if (p2rounds == 2) {
			playerB2.cross2.setTexture(playerB2.cross);
		}

	}
}

void Game::Initialize() {

	try {
		playerB1.initSprites();
		playerB2.initSprites();

		playerB1.initText();
		playerB2.initText();
	}
	catch(...){
		throw ResourceException();
	}


	shuffleCards(player1->activeDeck);
	shuffleCards(player2->activeDeck);

	int i = 0;

	for (auto p = player1->activeDeck.begin(); p != player1->activeDeck.end(); p++) {

		if (i < 10) {
			playerB1.hand.push_back(*p);
		}
		else {
			playerB1.deck.push_back(*p);
		}
		i++;

	}

	i = 0;

	for (auto p = player2->activeDeck.begin(); p != player2->activeDeck.end(); p++) {

		if (i < 10) {
			playerB2.hand.push_back(*p);
		}
		else {
			playerB2.deck.push_back(*p);
		}
		i++;

	}

}

void Game::PlayerChangeIn(GraphicHandler& graphics, PlayerBoard& pb, PlayerBoard& enemypb) {
	
	sf::Time time;
	sf::Clock clock;

	clock.restart();

	while (graphics.mainWindow->isOpen()) {

		sf::Event event;
		while (graphics.mainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				graphics.mainWindow->close();
		}

		pb.updatePos();
		enemypb.updateEnempos();
		
		time = clock.getElapsedTime();

		if (time.asSeconds() < 1.5) {

			graphics.setState(pchangein);
			graphics.setTime(time);

			graphics.draw(pb, enemypb);

		}
		else
			return;

	}
}

void Game::PlayerChangeOut(GraphicHandler& graphics, PlayerBoard& pb, PlayerBoard& enemypb) {

	sf::Time time;
	sf::Clock clock;

	clock.restart();

	while (graphics.mainWindow->isOpen()) {

		sf::Event event;
		while (graphics.mainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				graphics.mainWindow->close();
		}

		pb.updatePos();
		enemypb.updateEnempos();

		time = clock.getElapsedTime();

		if (time.asSeconds() < 1.5) {

			graphics.setState(pchangeout);
			graphics.setTime(time);

			graphics.draw(pb, enemypb);

		}
		else
			return;

	}
}

void Game::shuffleCards(std::list<Card*>& deck) {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	//std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));

}

void Game::endGame() {

	PlayedGame g1(p1rounds, p2rounds, player2->getName(), player2->getRating());
	PlayedGame g2(p2rounds, p1rounds, player1->getName(), player1->getRating());

	player1->gameHist.push_back(g1);
	player2->gameHist.push_back(g2);

	player1->setRating(player1->getRating() + p1rounds - p2rounds);
	player2->setRating(player2->getRating() + p2rounds - p1rounds);
}

