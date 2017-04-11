#include <SFML/Graphics.hpp>
#include "StandardCursor.hpp"
#include <iostream>
#include "Mouse.hpp"

float test(float value, float min, float max);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");


	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::View fixed = window.getView();
	
	fixed.move(-400.f, -300.f);

	window.setView(fixed);

	std::cout << fixed.getCenter().x;
	
	sf::Transform viewTransform = fixed.getTransform();
	
	sf::Vertex dot(sf::Vector2f(0.f, 0.f), sf::Color::Red);
	
	sf::Mouse::setPosition(sf::Vector2i(400, 300), window);

	sf::Vector2f* mousePos;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				/*std::cout << sf::Mouse::getPosition(window).x << " " <<
					sf::Mouse::getPosition(window).y << std::endl;*/
				mousePos = &bzc::Mouse::viewToWorldSpace(sf::Mouse::getPosition(window),
					fixed.getTransform(), window);
				
				std::cout <<"x: " <<mousePos->x << " y:" << mousePos->y<< std::endl;
				std::cout << std::endl;
			}
				
		}

		window.clear();
		window.draw(shape);
		window.draw(&dot, 1, sf::Points);
		window.display();
	}

	return 0;
}