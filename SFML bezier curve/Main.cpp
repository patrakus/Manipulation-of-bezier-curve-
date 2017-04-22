#include <SFML/Graphics.hpp>
#include "StandardCursor.hpp"
#include <iostream>
#include "Mouse.hpp"
#include "BezierCurve.hpp"
#include "FPS.hpp"
#include "ShapeHandler.hpp"
#include <cmath>

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

	bool moveHandler = false;

	sf::StandardCursor cursor(sf::StandardCursor::NORMAL);
	cursor.set(window.getSystemHandle());

	bool changedCursor = false;

	std::cout << shapeHandler.getRadius() << std::endl;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			sf::Vector2f mousePosInGlobal = window.mapPixelToCoords(sf::Mouse::getPosition(window));

			
			sf::Vector2f mousePosFromHandler = mousePosInGlobal - shapeHandler.getPosition();

			float radiusFromHandler = sqrt( mousePosFromHandler.x * mousePosFromHandler.x +
				mousePosFromHandler.y * mousePosFromHandler.y);


			//std::cout << mousePosInGlobal.x << " " << mousePosInGlobal.y << std::endl;
			std::cout << mousePosInGlobal.x << " " << mousePosInGlobal.y << std::endl;
			//std::cout << testPos2.x <<" " <<testPos2.y << std::endl;
			std::cout << shapeHandler.getPosition().x << " " << shapeHandler.getPosition().y << std::endl;
			std::cout << radiusFromHandler << std::endl;
			//std::cout << std::endl;

			if (radiusFromHandler <= shapeHandler.getRadius())
			{
				changedCursor = cursor.change(sf::StandardCursor::HAND);
				cursor.set(window.getSystemHandle());
				
			}
			else if (changedCursor)
			{
				cursor.change(sf::StandardCursor::NORMAL);
				cursor.set(window.getSystemHandle());
				changedCursor = false;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left && radiusFromHandler <= shapeHandler.getRadius())
				{
					moveHandler = true;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					moveHandler = false;
					shapeHandler.handlerIsNotActive();
				}
				
			}

			if (moveHandler)
			{
				shapeHandler.handlerIsActive();
				shapeHandler.moveHandler(mousePosFromHandler);
				shapeHandler.update();
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