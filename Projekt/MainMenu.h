#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Initializer.h"
#include "Game.h"

enum menustate {
	player,
	changep,
	mmenu,
	createp,
	deck,
	game
};

class MainMenu {
	menustate state;
	Player* active;
	Player* enem;
	int iter;
	bool gameReady;
	bool cpu;
public:
	sf::Font font1;
	sf::Font font2;
	sf::Texture backgroundTex;
	sf::Sprite background;
	sf::RenderWindow* mainWindow;
	sf::Texture buttGraTex;
	sf::Sprite buttGra;
	sf::Texture buttTalTex;
	sf::Sprite buttTal;
	sf::Texture buttGraczeTex;
	sf::Sprite buttGracze;
	sf::Texture buttPomTex;
	sf::Sprite buttPom;
	sf::Texture upButTex;
	sf::Texture upButIna;
	sf::Texture dnButTex;
	sf::Texture dnButIna;
	sf::Sprite upBut;
	sf::Sprite dnBut;
	sf::Texture butPCTex;
	sf::Texture butPATex;
	sf::Texture butPPTex;
	sf::Sprite butPlayer;
	sf::Text activeText;
	sf::Texture butBackTex;
	sf::Sprite butBack;
	sf::Text text1;
	sf::Texture butCPUtex;
	sf::Sprite butCPU;


	Initializer* data;

	MainMenu(sf::RenderWindow* mainWindow, Initializer* _data);

	void setstate(menustate _state);
	void menuLoop();
	void setActive(Player* _active);
	void setEnem(Player* _enem) { enem = _enem; };
	Player* getEnem() { return enem; };
	void drawMenu();
	void drawMenuMain();
	void drawPlayerMenu();
	void drawChangeMenu();
	void drawCreateMenu();
	void drawDeckMenu();
	void drawGameMenu();
	void setCardsPos();
	void startGame();
	Card* choseCard(sf::Vector2i pos, int &chose);
	int mainMenuClick(sf::Vector2i mouseClick);
	void exit();
	void initializeBot();


};