#include "MenuPanel.h"

MenuPanel::MenuPanel(sf::RenderWindow& window, Menu_Params params) : window(window)
{
	this->params.resizeable_x = params.resizeable_x;
	this->params.resizeable_y = params.resizeable_y;


	if (params.size_x <= 1.0f && params.size_x >= 0.0f)
		this->params.size_x = params.size_x;
	else
		throw std::runtime_error("Panel size must be between 0.0 and 1.0");
	

	if (params.size_y <= 1.0f && params.size_y >= 0.0f)
		this->params.size_y = params.size_y;
	else
		throw std::runtime_error("Panel size must be between 0.0 and 1.0");

	const sf::Color colour_grey = sf::Color(125, 125, 125, 255);
	panel_holder.setFillColor(colour_grey);

	const sf::Vector2f panel_size
	(
		params.size_x * window.getSize().x, 
		params.size_y*window.getSize().y
	);
	panel_holder.setSize(panel_size);

	const sf::Vector2f panel_position
	(
		params.position_x,
		params.position_y
	);
	panel_holder.setPosition(panel_position);
}

void MenuPanel::Update(float pointer_x, float pointer_y)
{
	ResizePanel();
	Draw();
}

void MenuPanel::Draw()
{
	window.draw(panel_holder);
}

void MenuPanel::ResizePanel()
{
	sf::Vector2f panel_size = panel_holder.getSize();
	if (params.resizeable_x)
		panel_size.x = params.size_x * window.getSize().x;
	if (params.resizeable_y)
		panel_size.y = params.size_y * window.getSize().y;
	
	panel_holder.setSize(panel_size);
}
