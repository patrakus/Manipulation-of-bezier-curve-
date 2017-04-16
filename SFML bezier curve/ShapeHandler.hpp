#pragma once
#include <SFML\Graphics.hpp>

namespace bzc
{
	class ShapeHandler
	{
	public:
		ShapeHandler();
		~ShapeHandler();

		void draw(sf::RenderWindow& const window);
		void moveHandler(const sf::Vector2f& offset);
		void setRadius(const float radius)
		{
			_handlerPointer.setRadius(radius);
		}
		float getRadius() const
		{
			return _handlerPointer.getRadius();
		}
		sf::Vector2f getPosition() const
		{
			return _handlerPointer.getPosition();
		}
		void setLine(const sf::Vector2f& point, const sf::Vector2f& controlPoint);

		void handlerIsActive()
		{
			_handlerPointer.setFillColor(sf::Color::Black);
		}

		void handlerIsNotActive()
		{
			_handlerPointer.setFillColor(sf::Color::White);
		}

		void setCircleHandler(const sf::Vector2f controlPointPos)
		{
			_handlerPointer.setPosition(controlPointPos);
		}

		void update()
		{
			line[1].position = _handlerPointer.getPosition();
		}

	private:
		sf::CircleShape _handlerPointer;
		sf::Vertex line[2];
	};
}

// przypomnieæ sobie o inlinie w klasach