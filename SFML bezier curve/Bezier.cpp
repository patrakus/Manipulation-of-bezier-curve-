#include "BezierCurve.hpp"
#include <iostream>

bzc::Bezier::Bezier() : _resolution(8)
{
	vertices = nullptr;
	controlPoints = new sf::Vector2f[3]{ { -100.f, 0.f },{ -100.f, -100.f },
	{ 100.f, -100.f } };
}

bzc::Bezier::Bezier(unsigned int curveResolution) : _resolution(curveResolution)
{
	Bezier();
}

bzc::Bezier::~Bezier()
{
		delete vertices;
		delete controlPoints;
}

void bzc::Bezier::update()
{
	createVertices();
	calculateCurve();
	setColor();
}

void bzc::Bezier::setControlPoints(const sf::Vector2f* points, const unsigned int size)
{
	if (controlPoints != nullptr)
	{
		delete controlPoints;
		controlPoints = nullptr;
	}

	createControlPoints(size);
	copyPoints(points, size);
}

void bzc::Bezier::calculateCurve()
{
	for (unsigned int i = 0; i <= _resolution-1; i++)
	{
		sf::Vector2f verticePos;
		float temp = normalization(static_cast<float>(i));

		verticePos.x = ((1 - temp)*(1 - temp))*controlPoints[0].x + 2 * (1 - temp)*temp*controlPoints[1].x +
			temp*temp*controlPoints[2].x;
		verticePos.y = ((1 - temp)*(1 - temp))*controlPoints[0].y + 2 * (1 - temp)*temp*controlPoints[1].y +
			temp*temp*controlPoints[2].y;

		vertices[i].position = verticePos;
	}
}

void bzc::Bezier::setColor()
{
	for (unsigned int i = 0; i < _resolution; i++)
	{
		vertices[i].color = sf::Color::Red;
	}
}

void bzc::Bezier::createControlPoints(const unsigned int size)
{
	if (controlPoints == nullptr)
	{
		controlPoints = new sf::Vector2f[size];
	}
}

void bzc::Bezier::copyPoints(const sf::Vector2f* points, const unsigned int size)
{

	for (unsigned int i = 0; i < size; i++)
	{
		controlPoints[i] = points[i];
	}
}

void bzc::Bezier::createVertices()
{
	if (vertices != nullptr)
	{
		delete vertices;
	}

	vertices = new sf::Vertex[_resolution];
}