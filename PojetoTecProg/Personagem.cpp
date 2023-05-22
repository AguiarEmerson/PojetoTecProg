#include "Personagem.h"

namespace Entidades
{
	Personagem::Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
		Entidade(tam, p, v),
		hp(h)
	{
	}

	Personagem::Personagem() :
		Entidade(),
		hp(3)
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
}