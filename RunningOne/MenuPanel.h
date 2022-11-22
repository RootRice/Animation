#pragma once
#include <SFML/Graphics.hpp>
class MenuPanel
{
public:
	struct Menu_Params
	{
		bool resizeable_x;
		bool resizeable_y;
		float position_x;
		float position_y;
		float size_x;
		float size_y;
	};

	MenuPanel(sf::RenderWindow& window, Menu_Params params);

	void Update(float pointer_x, float pointer_y);
	
private:
	sf::RenderWindow& window;
	sf::RectangleShape panel_holder;

	Menu_Params params;
	Menu_Params params2;

	void Draw();

	void ResizePanel();

};

