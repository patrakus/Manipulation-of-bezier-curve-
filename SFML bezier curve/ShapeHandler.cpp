#include "ShapeHandler.hpp"

bzc::ShapeHandler::ShapeHandler() : _handlerPointer(5.f)
{
	_handlerPointer.setOrigin(5.f, 5.f);
	_handlerPointer.setOutlineColor(sf::Color::Blue);
	_handlerPointer.setOutlineThickness(1);
	//_handlerPointer.move( -(5.f / 2), -(5.f / 2));
	//_handlerPointer.move(200, 200);

	line[0].color = sf::Color::Green;
	line[1].color = sf::Color::Green;
}

bzc::ShapeHandler::~ShapeHandler()
{
}

void bzc::ShapeHandler::draw(sf::RenderWindow& const window)
{
	window.draw(_handlerPointer);
	window.draw(line, 2, sf::LineStrip);
}

void bzc::ShapeHandler::moveHandler(const sf::Vector2f& offset)
{
	_handlerPointer.move(offset);
}

void bzc::ShapeHandler::setLine(const sf::Vector2f& point, const sf::Vector2f& controlPoint)
{
	line[0].position = point; // point which curve cross
	line[1].position = controlPoint; // control point which steer curve
}