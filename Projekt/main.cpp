#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include"GraphicHandler.h"
#include"Game.h"
#include"Initializer.h"
#include"Interface.h"
#include"MainMenu.h"


int main() {

    try {
        Initializer data;
        sf::RenderWindow mainWindow(sf::VideoMode(1920, 1080), "Gra Karciana");
        MainMenu menu(&mainWindow, &data);
        menu.menuLoop();
        data.cleanUp();
        return 0;
    }
    catch (...) {
        std::cout << "Initialization failed! Exiting...\n";
        return 0;
    }
}