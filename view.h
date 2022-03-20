#include <SFML/Graphics.hpp>

sf::View view;

sf::View getCoordinatesForView(float x, float y)
{
	view.setCenter(x + 100, y);
	return view;
}
