#include "Mouse.hpp"

sf::Vector2f& bzc::Mouse::viewToWorldSpace(sf::Vector2f mousePos, 
	const sf::Transform viewTransform, const sf::Window& window)
{
	//sf::Vector2f temp(calculateValueBetweenMinusOneAndOne(mousePos.x, 0, window.getSize().x),
	//	calculateValueBetweenMinusOneAndOne(window.getSize().y - mousePos.y, 0, window.getSize().y));

	sf::Vector2f temp;
	temp.x = mousePos.x;
	temp.y = mousePos.y;

	return viewTransform.getInverse().transformPoint(temp);
}