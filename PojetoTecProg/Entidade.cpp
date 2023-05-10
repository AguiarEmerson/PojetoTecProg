#include "Entidade.h"

Entidade::Entidade(float tam, float x, float y):
	Ente(tam)
{
	setpos(x, y);
}
Entidade::~Entidade()
{

}

void Entidade::setpos(float x, float y)
{
	pos = sf::Vector2f(x, y);
	box.setPosition(x, y);
}

sf::Vector2f Entidade::getpos()
{
	return pos;
}

void Entidade::setvel(float x, float y)
{
	vel = sf::Vector2f(x, y);
}
sf::Vector2f Entidade::getvel()
{
	return vel;
}
