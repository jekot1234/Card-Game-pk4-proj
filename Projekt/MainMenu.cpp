#include "MainMenu.h"
#include<iostream>
#include<typeinfo>

MainMenu::MainMenu(sf::RenderWindow* _mainWindow, Initializer* _data) {

	data = _data;

	mainWindow = _mainWindow;

	if (!font1.loadFromFile("points.ttf")) {

	}

	if (!font2.loadFromFile("maszyna.ttf")) {

	}
	
	if (!backgroundTex.loadFromFile("mmbg.png")) {

	}
	background.setTexture(backgroundTex);



	if (!buttGraTex.loadFromFile("buttgra.png")) {

	}
	buttGra.setTexture(buttGraTex);
	if (!buttTalTex.loadFromFile("butttal.png")) {

	}
	buttTal.setTexture(buttTalTex);
	if (!buttGraczeTex.loadFromFile("buttgrz.png")) {

	}
	buttGracze.setTexture(buttGraczeTex);
	if (!buttPomTex.loadFromFile("buttpom.png")) {

	}
	buttPom.setTexture(buttPomTex);

	if (upButTex.loadFromFile("up.png")) {

	}
	if (upButIna.loadFromFile("upina.png")) {

	}

	if (dnButTex.loadFromFile("dn.png")) {

	}
	if (dnButIna.loadFromFile("dnina.png")) {

	}

	if (!butPCTex.loadFromFile("pcbut.png")) {

	}
	if (!butPATex.loadFromFile("add.png")) {

	}
	if (!butPPTex.loadFromFile("play.png")) {

	}
	butPlayer.setTexture(butPCTex);

	if (!butBackTex.loadFromFile("back.png")) {

	}
	butBack.setTexture(butBackTex);

	if (!butCPUtex.loadFromFile("cpu.png")) {

	}
	butCPU.setTexture(butCPUtex);

	setstate(mmenu);

}

void MainMenu::setstate(menustate _state) {

	iter = 0;
	int i = 0;

	sf::Vector2f buttpos(0, 0);

	switch (_state) {
	case(mmenu):
		state = _state;

		buttpos.x = 960.0 - buttGra.getLocalBounds().width / 2;
		buttpos.y = 60;
		buttGra.setPosition(buttpos);

		buttpos.y += 230;
		buttTal.setPosition(buttpos);

		buttpos.y += 230;
		buttGracze.setPosition(buttpos);

		buttpos.y += 230;
		buttPom.setPosition(buttpos);


		break;
	case(player):

		state = _state;

		butBack.setPosition(165.0, 65.0);

		butPlayer.setTexture(butPCTex);
		butPlayer.setPosition(sf::Vector2f(550.0 - butPlayer.getLocalBounds().width / 2, 760.0));

		upBut.setTexture(upButIna);
		upBut.setPosition(sf::Vector2f(1325.0, 170.0));

		dnBut.setTexture(dnButIna);
		dnBut.setPosition(sf::Vector2f(1325.0, 890.0));

		break;

	case(changep):
		state = _state;

		butPlayer.setTexture(butPATex);
		butPlayer.setPosition(sf::Vector2f(550.0 - butPlayer.getLocalBounds().width / 2, 760.0));

		upBut.setTexture(upButIna);
		upBut.setPosition(sf::Vector2f(1325.0, 170.0));

		dnBut.setTexture(dnButIna);
		dnBut.setPosition(sf::Vector2f(1325.0, 890.0));

		for (auto p = data->playerList.begin(); p != data->playerList.end(); p++) {
			if (i == 0) {
				p->nametext.setFont(font1);
				sf::FloatRect bounds = p->nametext.getLocalBounds();
				p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 340.0));

				i++;
			}
			else if (i == 1) {
				p->nametext.setFont(font1);
				sf::FloatRect bounds = p->nametext.getLocalBounds();
				p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 490.0));

				i++;
			}
			else if (i == 2) {
				p->nametext.setFont(font1);
				sf::FloatRect bounds = p->nametext.getLocalBounds();
				p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 640.0));
				i++;
			}
			else if (i == 3) {
				p->nametext.setFont(font1);
				sf::FloatRect bounds = p->nametext.getLocalBounds();
				p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 790.0));
				i = 0;
			}
		}
		break;
	case(createp):

		state = _state;

		activeText.setCharacterSize(150);
		activeText.setFont(font1);
		activeText.setFillColor(sf::Color::White);
		activeText.setPosition(500 - activeText.getGlobalBounds().width / 2, 360);
		activeText.setString("");

		break;

	case(deck):

		state = _state;

		setCardsPos();

		break;

	case(game):

		state = _state;

		enem = nullptr;

		upBut.setTexture(upButIna);
		upBut.setPosition(sf::Vector2f(1325.0, 170.0));

		dnBut.setTexture(dnButIna);
		dnBut.setPosition(sf::Vector2f(1325.0, 890.0));

		for (auto p = data->playerList.begin(); p != data->playerList.end(); p++) {

			if (&(*p) != active) {
				if (i == 0) {
					p->nametext.setFont(font1);
					sf::FloatRect bounds = p->nametext.getLocalBounds();
					p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 340.0));

					i++;
				}
				else if (i == 1) {
					p->nametext.setFont(font1);
					sf::FloatRect bounds = p->nametext.getLocalBounds();
					p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 490.0));

					i++;
				}
				else if (i == 2) {
					p->nametext.setFont(font1);
					sf::FloatRect bounds = p->nametext.getLocalBounds();
					p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 640.0));
					i++;
				}
				else if (i == 3) {
					p->nametext.setFont(font1);
					sf::FloatRect bounds = p->nametext.getLocalBounds();
					p->nametext.setPosition(sf::Vector2f(1430 - bounds.width / 2, 790.0));
					i = 0;
				}
			}
		}

		butPlayer.setTexture(butPPTex);
		butPlayer.setPosition(sf::Vector2f(550.0 - butPlayer.getLocalBounds().width / 2, 760.0));
		butCPU.setPosition(sf::Vector2f(950.0, 800.0));

		break;
	}

}

void MainMenu::menuLoop() {

	setActive(&data->playerList.front());

	while (1) {
		while (mainWindow->isOpen()) {


			drawMenu();

			if (gameReady)
				break;

		}
		if (gameReady) {
			try {
				startGame();
			}
			catch (...) {
				throw ResourceException();
			}

			gameReady = false;
		}
		if (!mainWindow->isOpen())
			break;
	}
	
}

void MainMenu::setActive(Player* _active) {

	if(active)
		active->nametext.setFillColor(sf::Color::White);

	active = _active;

	active->nametext.setFillColor(sf::Color::Yellow);

	activeText.setString(active->getName());
	activeText.setCharacterSize(120);
	activeText.setFont(font1);
	activeText.setFillColor(sf::Color::White);
	activeText.setPosition(500 - activeText.getGlobalBounds().width / 2, 360);

	int i = 0;

	for (auto p = active->gameHist.begin(); p != active->gameHist.end(); p++) {
		if (i == 0) {
			p->text.setFont(font1);
			sf::FloatRect bounds = p->text.getLocalBounds();
			p->text.setPosition(sf::Vector2f(1430 - bounds.width/2, 340.0));

			i++;
		}
		else if (i == 1) {
			p->text.setFont(font1);
			sf::FloatRect bounds = p->text.getLocalBounds();
			p->text.setPosition(sf::Vector2f(1430 - bounds.width/2, 490.0));

			i++;
		}
		else if (i == 2) {
			p->text.setFont(font1);
			sf::FloatRect bounds = p->text.getLocalBounds();
			p->text.setPosition(sf::Vector2f(1430 - bounds.width/2, 640.0));
			i++;
		}
		else if (i == 3) {
			p->text.setFont(font1);
			sf::FloatRect bounds = p->text.getLocalBounds();
			p->text.setPosition(sf::Vector2f(1430 - bounds.width/2, 790.0));
			i = 0;
		}
	}

}

void MainMenu::drawMenu() {

	switch (state) {
	case(mmenu):
		this->drawMenuMain();
		break;
	case(player):
		this->drawPlayerMenu();
		break;
	case(changep):
		this->drawChangeMenu();
		break;
	case(createp):
		this->drawCreateMenu();
		break;
	case(deck):
		this->drawDeckMenu();
		break;
	case(game):
		this->drawGameMenu();
		break;
	}

}

void MainMenu::drawMenuMain() {
	sf::Event event;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}

	sf::Vector2i mouseClickPos;
	int clicked;

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(background);

	mainWindow->draw(buttGra);
	mainWindow->draw(buttTal);
	mainWindow->draw(buttGracze);
	mainWindow->draw(buttPom);



	mainWindow->display();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		mouseClickPos = sf::Mouse::getPosition(*mainWindow);
		clicked = mainMenuClick(mouseClickPos);

		switch (clicked) {
		case(1):
			setstate(game);
			break;
		case(2):
			setstate(deck);
			break;
		case(3):
			setstate(player);
			break;
		case(4):
			mainWindow->close();
			exit();
			break;
		}

	}

}

void MainMenu::drawPlayerMenu() {

	sf::Event event;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}

	if (iter == 0) {
		upBut.setTexture(upButIna);
	}
	else {
		upBut.setTexture(upButTex);
	}

	if ((iter + 1) * 4 >= int(active->gameHist.size())) {
		dnBut.setTexture(dnButIna);
	}
	else {
		dnBut.setTexture(dnButTex);
	}

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(background);

	auto i = active->gameHist.begin();
	std::advance(i, 4 * iter);
	for (int j = 0; j < 4; j++) {
		
		if (i != active->gameHist.end()) {
			mainWindow->draw((*i).text);
			i++;
		}

	}

	mainWindow->draw(activeText);
	mainWindow->draw(butBack);
	mainWindow->draw(butPlayer);
	mainWindow->draw(upBut);
	mainWindow->draw(dnBut);
	mainWindow->display();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*mainWindow);

		auto fmouseClick = sf::Vector2f(mouseClickPos);

		if (upBut.getGlobalBounds().contains(fmouseClick)) {
			if (iter > 0) {
				iter--;
			}

		}
		else if (dnBut.getGlobalBounds().contains(fmouseClick)) {
			if (((iter + 1) * 4) < active->gameHist.size()) {
				iter++;
			}
		}
		else if (butPlayer.getGlobalBounds().contains(fmouseClick)) {
			setstate(changep);
		}
		else if (butBack.getGlobalBounds().contains(fmouseClick)) {
			setstate(mmenu);
		}

		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {};
	}

}

void MainMenu::drawChangeMenu() {

	sf::Event event;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}

	if (iter == 0) {
		upBut.setTexture(upButIna);
	}
	else {
		upBut.setTexture(upButTex);
	}

	if ((iter + 1) * 4 >= int(data->playerList.size())) {
		dnBut.setTexture(dnButIna);
	}
	else {
		dnBut.setTexture(dnButTex);
	}

	active->nametext.setCharacterSize(82);
	active->nametext.setFont(font1);

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(background);

	auto p = data->playerList.begin();
	std::advance(p, 4 * iter);
	for (int j = 0; j < 4; j++) {

		if (p != data->playerList.end()) {
			mainWindow->draw((*p).nametext);
			p++;
		}

	}

	mainWindow->draw(butPlayer);
	mainWindow->draw(butBack);
	mainWindow->draw(activeText);
	mainWindow->draw(upBut);
	mainWindow->draw(dnBut);

	mainWindow->display();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*mainWindow);

		auto fmouseClick = sf::Vector2f(mouseClickPos);

		if (upBut.getGlobalBounds().contains(fmouseClick)) {
			if (iter > 0) {
				iter--;
			}

		}
		else if (dnBut.getGlobalBounds().contains(fmouseClick)) {
			if (((iter + 1) * 4) < data->playerList.size()) {
				iter++;
			}
		}
		else if (butPlayer.getGlobalBounds().contains(fmouseClick)) {
			setstate(createp);
		}
		else if (butBack.getGlobalBounds().contains(fmouseClick)) {
			setstate(player);
		}
		
		auto i = data->playerList.begin();
		std::advance(i, 4 * iter);
		for (int j = 0; j < 4; j++) {

			if (i != data->playerList.end()) {
				if ((*i).nametext.getGlobalBounds().contains(fmouseClick)) {
					setActive(&(*i));
				}
				i++;
			}

		}

		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {};
	}



}

void MainMenu::drawCreateMenu() {

	sf::Event event;
	sf::String fstr(activeText.getString());
	std::string str(activeText.getString());

	while (mainWindow->pollEvent(event)) {

		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == '\b') {
				if(str.size())
					str.pop_back();
				activeText.setString(str);
			}
			else if (event.text.unicode < 128 && event.text.unicode != ' ') {
				fstr += event.text.unicode;
				activeText.setString(fstr);
			}
		}
		else if (event.type == sf::Event::Closed)
			mainWindow->close();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

		str = activeText.getString();

		str.pop_back();

		data->playerList.emplace_back(str, data->playerList.back().getId() + 1, 1500);

		setstate(changep);
		setActive(&(data->playerList.back()));

	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*mainWindow);

		auto fmouseClick = sf::Vector2f(mouseClickPos);
		if (butBack.getGlobalBounds().contains(fmouseClick)) {
			setActive(active);
			setstate(changep);
		}
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
	}

	mainWindow->clear(sf::Color::Black);

	mainWindow->draw(background);
	mainWindow->draw(activeText);
	mainWindow->draw(butBack);

	mainWindow->display();
}

void MainMenu::drawDeckMenu() {

	sf::Event event;

	setCardsPos();

	int chose = 0;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*mainWindow);
		auto fmouseClick = sf::Vector2f(mouseClickPos);

		if (butBack.getGlobalBounds().contains(fmouseClick)) {
			setstate(mmenu);
		}

		Card* cop = choseCard(mouseClickPos, chose);

		if (chose == 1) {

			std::string type = typeid(*cop).name();

			type.erase(type.begin(), type.begin() + 6);

			Card* newCard = cop->clone();

			std::cout << typeid(*cop).name() << std::endl;
			std::cout << typeid(*newCard).name() << std::endl;

			active->activeDeck.push_back(newCard);
		}
		else if (chose == 2) {
			active->activeDeck.remove(cop);
			delete cop;
		}
		
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left));

	}

	mainWindow->clear(sf::Color::Black);
	mainWindow->draw(background);
	mainWindow->draw(butBack);
	for (auto p : active->activeDeck) {

		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);
	}

	for (auto p : data->cardBase) {

		mainWindow->draw(p->sprite);
		mainWindow->draw(p->attackText);

	}

	mainWindow->display();
}

void MainMenu::drawGameMenu() {

	sf::Event event;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}

	if (iter == 0) {
		upBut.setTexture(upButIna);
	}
	else {
		upBut.setTexture(upButTex);
	}

	if ((iter + 1) * 4 >= int(data->playerList.size())) {
		dnBut.setTexture(dnButIna);
	}
	else {
		dnBut.setTexture(dnButTex);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2i mouseClickPos = sf::Mouse::getPosition(*mainWindow);

		auto fmouseClick = sf::Vector2f(mouseClickPos);

		if (upBut.getGlobalBounds().contains(fmouseClick)) {
			if (iter > 0) {
				iter--;
			}

		}
		else if (dnBut.getGlobalBounds().contains(fmouseClick)) {
			if (((iter + 1) * 4) < data->playerList.size()) {
				iter++;
			}
		}
		else if (butBack.getGlobalBounds().contains(fmouseClick)) {
			if(enem)
				enem->nametext.setFillColor(sf::Color::White);
			setstate(mmenu);
		}
		else if (butPlayer.getGlobalBounds().contains(fmouseClick)) {

			if (active) {
				if (enem) {
					gameReady = true;
				}
			}
		}
		else if (butCPU.getGlobalBounds().contains(fmouseClick)) {

			if (active) {
				enem = &(data->botList.front());
				gameReady = true;
			}
		}

		auto i = data->playerList.begin();
		std::advance(i, 4 * iter);
		for (int j = 0; j < 4; j++) {

			if (i != data->playerList.end()) {
				if ((*i).nametext.getGlobalBounds().contains(fmouseClick)) {

					if (&(*i) != active) {
						if (enem)
							enem->nametext.setFillColor(sf::Color::White);
						enem = &(*i);
						enem->nametext.setFillColor(sf::Color::Red);

					}
				}
				i++;
			}

		}

		while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {};
	}

	active->nametext.setCharacterSize(82);
	active->nametext.setFont(font1);



	mainWindow->clear(sf::Color::Black);
	mainWindow->draw(background);
	mainWindow->draw(activeText);
	mainWindow->draw(upBut);
	mainWindow->draw(dnBut);
	mainWindow->draw(butPlayer);
	mainWindow->draw(butBack);
	mainWindow->draw(butCPU);

	auto p = data->playerList.begin();
	std::advance(p, 4 * iter);
	for (int j = 0; j < 4; j++) {

		if (p != data->playerList.end()) {
			if (&(*p) != active) {
				mainWindow->draw((*p).nametext);
			}
			p++;
		}

	}

	mainWindow->display();
}

void MainMenu::setCardsPos() {

	float yActive = 800;
	float yBase = 250;

	float xActive = 240;
	float xBase = 240;

	if (active->activeDeck.size() <= 8) {
		xActive = 960.0 - (active->activeDeck.size() * 0.5 * 100.0 + (active->activeDeck.size() - 1) * 0.5 * 20.0);
	}
	if (data->cardBase.size() <= 8) {
		xBase = 960.0 - (data->cardBase.size() * 0.5 * 100.0 + (data->cardBase.size() - 1) * 0.5 * 20.0);
	}


	for (auto p : active->activeDeck) {
		if (active->activeDeck.size() <= 10) {
			p->setPosition(xActive, yActive);
			p->updatetextpos();
			xActive += 120;
		}
		else {
			p->setPosition(xActive, yActive);
			p->updatetextpos();
			xActive += 1440.0 / (active->activeDeck.size() - 1);
		}
	}

	for (auto p : data->cardBase) {
		if (data->cardBase.size() <= 10) {
			p->setPosition(xBase, yBase);
			p->updatetextpos();
			xBase += 120;
		}
		else {
			p->setPosition(xBase, yBase);
			p->updatetextpos();
			xBase += 1440.0 / (data->cardBase.size() - 1);
		}
	}

}

void MainMenu::startGame() {

	try {
		GraphicHandler graph(mainWindow);
		Game game(active, enem);
		game.Initialize();
		game.GameCycle(graph);
	}
	catch(...){
		throw ResourceException();
	}


}

Card* MainMenu::choseCard(sf::Vector2i pos, int& chose)
{
	if (pos.y >= 250 && pos.y <= 370) {
		for (std::list<Card*>::reverse_iterator rit = data->cardBase.rbegin(); rit != data->cardBase.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				chose = 1;
				return *rit;
			}
		}
	}
	else if (pos.y >= 800 && pos.y <= 920) {
		for (std::list<Card*>::reverse_iterator rit = active->activeDeck.rbegin(); rit != active->activeDeck.rend(); ++rit) {
			Card* temp = *rit;
			if (pos.x >= temp->sprite.getPosition().x && pos.x < (temp->sprite.getPosition().x + 100)) {
				chose = 2;
				return *rit;
			}
		}
	}

	chose = 0;
	return nullptr;
}

int MainMenu::mainMenuClick(sf::Vector2i mouseClick)
{

	auto fmouseClick = sf::Vector2f(mouseClick);

	if (buttGra.getGlobalBounds().contains(fmouseClick)) {
		return 1;
	}
	else if (buttTal.getGlobalBounds().contains(fmouseClick)) {
		return 2;
	}
	else if (buttGracze.getGlobalBounds().contains(fmouseClick)) {
		return 3;
	}
	else if (buttPom.getGlobalBounds().contains(fmouseClick)) {
		return 4;
	}
	else {
		return 0;
	}
}

void MainMenu::exit() {

	std::ofstream playersFile("players/players.txt", std::ofstream::trunc);
	std::string filename;

	playersFile << data->playerList.size() << "\n";
	
	for (auto p : data->playerList) {
		playersFile << p.getId() << " ";
		playersFile << p.getName() << " ";
		playersFile << p.getRating() << "\n";

		filename.append("players/");
		filename.append(p.getName());
		filename.append(std::to_string(p.getId()));
		filename.append(".txt");

		std::ofstream playerFile(filename, std::ofstream::trunc);
		playerFile << p.activeDeck.size() << "\n";

		for (auto r : p.activeDeck) {

			std::string type = typeid(*r).name();

			type.erase(type.begin(), type.begin() + 6);

			playerFile << type << " ";
			playerFile << r->getId() << " ";
			playerFile << r->getAttack() << " ";
			playerFile << r->getLane() << " ";
			playerFile << r->getName() << ") ";
			playerFile << r->getFileName() << "\n";
		}

		playerFile << p.gameHist.size() << "\n";

		for (auto r : p.gameHist) {

			playerFile << r.scorep << " ";
			playerFile << r.scoree << " ";
			playerFile << r.enemyName << " ";
			playerFile << r.enemyrating << "\n";
		}

		filename.clear();

	}


}

void MainMenu::initializeBot() {



}
