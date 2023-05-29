#include "..\Ente.h"

Ente::Ente( sf::Vector2f tam) :
	box(tam)
{
}

Ente::~Ente()
{
}

sf::RectangleShape Ente::desenhar()
{
	return box;
}
string Ente::getId()
{
	return id;
}