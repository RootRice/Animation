#include <iostream>
#include <SFML/Graphics.hpp>
#include "Editor.h"

int main()
{
    sf::RenderWindow editor_window(sf::VideoMode(600, 600), "Editor");
    //sf::RenderWindow play_window(sf::VideoMode(600, 600), "Player");

    Editor editor(editor_window);
    while(editor_window.isOpen())
    {
        sf::Event e;
        while (editor_window.pollEvent(e))
        {
            if (e.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
                editor_window.setView(sf::View(visibleArea));
            }
        }
        editor_window.clear();
        editor.Update();
        editor_window.display();
    }
}
