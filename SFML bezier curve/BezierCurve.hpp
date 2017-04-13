#pragma once

#include "SFML\Graphics.hpp"

namespace bzc
{
	class Bezier
	{
	public:
		Bezier();
		Bezier(unsigned int curveResolution);
		~Bezier();

		void update();
		sf::Vertex* getVertices() const
		{
			return vertices;
		}

		unsigned int getResolution() const
		{
			return _resolution;
		}

		void setControlPoints(const sf::Vector2f* points, const unsigned int size);
		void setCurveResolution(unsigned int resolution)
		{
			_resolution = resolution;
		}

	private:
		sf::Vertex* vertices;
		sf::Vector2f* controlPoints;
		unsigned int _resolution;

		void calculateCurve();
		void setColor();
		float normalization(float value)
		{
			return value / (_resolution-1);
		}

		void createControlPoints(const unsigned int size);
		void copyPoints(const sf::Vector2f* points, const unsigned int size);
		void createVertices();
	};
}