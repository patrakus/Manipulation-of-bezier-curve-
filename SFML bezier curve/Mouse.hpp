#pragma once

#include "SFML/Graphics.hpp"

namespace bzc
{
	class Mouse
	{
	public:

		static sf::Vector2f& viewToWorldSpace(sf::Vector2i mousePos, 
			const sf::Transform viewTransform, const sf::Window& window);

	private:
		static float calculateValueBetweenMinusOneAndOne(float value, float min, float max)
		{
			return -1 + ((value - min) / (max - min)) * 2;
		}
	};
}