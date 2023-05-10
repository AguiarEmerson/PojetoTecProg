#include "Ente.h"

Ente::Ente(float tam):
	box(sf::Vector2f(tam,tam))
{
	id = 0;
}
Ente::~Ente()
{
}

sf::RectangleShape Ente::print()
{
	return box;
}