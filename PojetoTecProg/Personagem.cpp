#include "Personagem.h"

Personagem::Personagem(float tam, sf::Vector2f p, sf::Vector2f v,int h):
	Entidade(tam,p,v),
	hp(h)
{
}
Personagem::~Personagem()
{
}

void Personagem::operator++()
{
	hp++;
}
void Personagem::operator--()
{
	hp--;
}