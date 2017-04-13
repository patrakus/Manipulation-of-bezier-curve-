#include <SFML/Graphics.hpp>
#include "StandardCursor.hpp"
#include <iostream>
#include "Mouse.hpp"
#include "BezierCurve.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::View fixed = window.getView();
	fixed.move(-400.f, -300.f);
	window.setView(fixed);

	sf::Vector2f pointsSample[3] = { { 0.f, 0.f }, { -100.f, -100.f }, { 100.f, -100.f } };

	bzc::Bezier bezier;
	bezier.setControlPoints(pointsSample, 3);
	bezier.setCurveResolution(20);

	bezier.update();

	sf::Vertex* points = bezier.getVertices();
	unsigned int curveResolution = bezier.getResolution();

	sf::Vector2f* mousePos;

	sf::Clock timer;
	float deltaTime;

	float speed = 10000.f;

	while (window.isOpen())
	{
		deltaTime = timer.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				/*std::cout << sf::Mouse::getPosition(window).x << " " <<
					sf::Mouse::getPosition(window).y << std::endl;*/ // ---> sprawdziæ w kodzie api ró¿nice
				mousePos = &bzc::Mouse::viewToWorldSpace(sf::Mouse::getPosition(window),
					fixed.getTransform(), window);
				
				//std::cout <<"Autorka konwersja wynosi " << "x: " <<mousePos->x << " y:" << mousePos->y<< std::endl;
				std::cout << std::endl;
				std::cout << "Wersja dostarczona przez api wynosi x:" <<
					window.mapPixelToCoords(sf::Mouse::getPosition()).x << " y:" <<
					window.mapPixelToCoords(sf::Mouse::getPosition()).y << std::endl;
			}

			window.setView(fixed);
		}

		window.clear();
		window.draw(shape);
		window.draw(points,curveResolution, sf::LineStrip);
		window.display();
	}

	return 0;
}


// zamieniæ to rownanie w bezierze na lerp
// zrobiæ poprawnie dzia³aj¹ce przemieszczenie za pomoc¹ deltaTime