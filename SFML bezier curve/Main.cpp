#include <SFML/Graphics.hpp>
#include "StandardCursor.hpp"
#include <iostream>

int main()
{
	int choice = 0;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		std::cout << "1. Change cursor to Wait." << std::endl;
		std::cout << "2. Change cursor to Text." << std::endl;
		std::cout << "3. Change cursor to Normal." << std::endl;
		std::cout << "4. Change cursor to Hand." << std::endl;
		std::cin >> choice;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	if (choice == 1)
	{
		sf::StandardCursor Cursor(sf::StandardCursor::WAIT);
		Cursor.set(window.getSystemHandle());
	}
	else if (choice == 2)
	{
		sf::StandardCursor Cursor(sf::StandardCursor::TEXT);
		Cursor.set(window.getSystemHandle());
	}
	else if (choice == 3)
	{
		sf::StandardCursor Cursor(sf::StandardCursor::NORMAL);
		Cursor.set(window.getSystemHandle());
	}
	else
	{
		sf::StandardCursor Cursor(sf::StandardCursor::HAND);
		Cursor.set(window.getSystemHandle());
	}

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::View fixed = window.getView();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}