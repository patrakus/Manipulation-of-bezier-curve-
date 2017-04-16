#include <SFML/Graphics.hpp>
#include "StandardCursor.hpp"
#include <iostream>
#include "Mouse.hpp"
#include "BezierCurve.hpp"
#include "FPS.hpp"
#include "ShapeHandler.hpp"
#include <math.h>

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
	//bezier.setControlPoints(pointsSample, 3);
	bezier.setCurveResolution(20);

	bezier.update();

	sf::Vertex* points = bezier.getVertices();
	unsigned int curveResolution = bezier.getResolution();

	sf::Vector2f* mousePos;

	bzc::ShapeHandler shapeHandler;
	shapeHandler.setLine(pointsSample[0], pointsSample[1]);
	shapeHandler.setCircleHandler(pointsSample[1]);

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
					sf::Mouse::getPosition(window).y << std::endl;*/ // ---> sprawdziæ w kodzie api ró¿nice

				
				//std::cout <<"Autorka konwersja wynosi " << "x: " <<mousePos->x << " y:" << mousePos->y<< std::endl;
				//std::cout << std::endl;
				/*std::cout << "Wersja dostarczona przez api wynosi x:" <<
					window.mapPixelToCoords(sf::Mouse::getPosition()).x << " y:" <<
					window.mapPixelToCoords(sf::Mouse::getPosition()).y << std::endl;*/
			}

			mousePos = &bzc::Mouse::viewToWorldSpace(sf::Mouse::getPosition(window),
				fixed.getTransform(), window);

			sf::Vector2f mousePosFromHandler = *mousePos - shapeHandler.getPosition();

			float radiusFromHandler = mousePosFromHandler.x * mousePosFromHandler.x +
				mousePosFromHandler.y * mousePosFromHandler.y;

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left && radiusFromHandler <= shapeHandler.getRadius())
				{
					shapeHandler.handlerIsActive();
					shapeHandler.moveHandler(mousePosFromHandler);
					shapeHandler.update();
				}
			}
			else
			{
				shapeHandler.handlerIsNotActive();
			}
		}

		window.clear();
		//window.draw(shape);
		shapeHandler.draw(window);
		window.draw(points,curveResolution, sf::LineStrip);
		window.display();
	}

	return 0;
}