#pragma once
#include <SFML/Graphics.hpp>
#include "MenuPanel.h"
class Editor
{
public:
	Editor(sf::RenderWindow& window);

	void Update();
private:
	sf::RenderWindow& window;
	MenuPanel main_panel;
};

