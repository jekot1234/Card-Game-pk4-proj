#include<list>
#include<random>
#include<chrono>

#include"Player.h"
#include"GraphicHandler.h"

#ifndef GAME_H
#define  GAME_H

//int randomized(int i) { return std::rand() % i; }

class Game {

public:
	Player* player1;
	Player* player2;
	PlayerBoard playerB1;
	PlayerBoard playerB2;

	int p1rounds;
	int p2rounds;



	Game() = default;
	Game(Player* p1, Player* p2) {
		player1 = p1;
		player2 = p2;
		p1rounds = 0;
		p2rounds = 0;

		PlayerBoard pB1;
		PlayerBoard pB2;

		playerB1 = pB1;
		playerB2 = pB2;
	}
	void GameCycle(GraphicHandler& graphics);
	void Initialize();
	void PlayerChangeIn(GraphicHandler& graphics, PlayerBoard& pb, PlayerBoard& enemypb);
	void PlayerChangeOut(GraphicHandler& graphics, PlayerBoard& pb, PlayerBoard& enemypb);
	void shuffleCards(std::list<Card*>& deck);
	void endGame();


};

#endif
