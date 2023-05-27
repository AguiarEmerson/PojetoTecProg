#include "..\Entidades\Obstaculos\Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Entidade(tam, p, v)
		{
			id = "obstaculo";
		}
		Obstaculo::Obstaculo() :
			Entidade()
		{
		}
		Obstaculo::~Obstaculo()
		{}

	}
}