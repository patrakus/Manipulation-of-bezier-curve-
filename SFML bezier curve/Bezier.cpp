#include "BezierCurve.hpp"
#include <iostream>
#include "MathFunctions.hpp"

bzc::Bezier::Bezier() : _resolution(8)
{
	_vertices = nullptr;
	_controlPoints = new sf::Vector2f[4]{ { -100.f, 0.f },{ -100.f, -100.f },
	{ 100.f, -100.f },{ 100.f, 0.f } };
}

bzc::Bezier::Bezier(unsigned int curveResolution) : _resolution(curveResolution)
{
	Bezier();
}

bzc::Bezier::~Bezier()
{
		delete _vertices;
		delete _controlPoints;
}

void bzc::Bezier::update()
{
	createVertices();
	calculateCurve();
	setColor();
}

void bzc::Bezier::setControlPoints(const sf::Vector2f* points, const unsigned int size)
{
	if (_controlPoints != nullptr)
	{
		delete _controlPoints;
		_controlPoints = nullptr;
	}

	createControlPoints(size);
	copyPoints(points, size);
}

//****************************************private*******************************************
//******************************************************************************************

void bzc::Bezier::calculateCurve()
{
	for (unsigned int i = 0; i <= _resolution-1; i++)
	{
		sf::Vector2f verticePos;
		float temp = normalization(static_cast<float>(i));
		sf::Vector2f* P = _controlPoints;


		verticePos.x = bzc::pow<float>((1 - temp), 3.f) * P[0].x + 3 * bzc::pow<float>((1 - temp), 2.f)*temp*P[1].x
			+ 3 * (1 - temp)*temp*temp*P[2].x + temp*temp*temp*P[3].x;

		verticePos.y = bzc::pow<float>((1 - temp), 3.f) * P[0].y + 3 * bzc::pow<float>((1 - temp), 2.f)*temp*P[1].y
			+ 3 * (1 - temp)*temp*temp*P[2].y + temp*temp*temp*P[3].y;

		_vertices[i].position = verticePos;
	}
}

void bzc::Bezier::setColor()
{
	for (unsigned int i = 0; i < _resolution; i++)
	{
		_vertices[i].color = sf::Color::Red;
	}
}

void bzc::Bezier::createControlPoints(const unsigned int size)
{
	if (_controlPoints == nullptr)
	{
		_controlPoints = new sf::Vector2f[size];
	}
}

void bzc::Bezier::copyPoints(const sf::Vector2f* points, const unsigned int size)
{

	for (unsigned int i = 0; i < size; i++)
	{
		_controlPoints[i] = points[i];
	}
}

void bzc::Bezier::createVertices()
{
	if (_vertices != nullptr)
	{
		delete _vertices;
	}

	_vertices = new sf::Vertex[_resolution];
}