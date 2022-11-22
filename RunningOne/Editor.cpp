#include "Editor.h"

constexpr MenuPanel::Menu_Params main_panel_params
{
	false, true, 0.0f, 0.0f, 0.2f, 1.0f
};

Editor::Editor(sf::RenderWindow& window) : window(window), main_panel(MenuPanel(window, main_panel_params))
{
	
}

void Editor::Update()
{
	main_panel.Update(0.0f, 0.0f);
}
