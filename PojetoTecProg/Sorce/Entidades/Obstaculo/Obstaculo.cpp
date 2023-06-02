#include "..\Entidades\Obstaculos\Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Entidade(tam, p, v)
		{
			danoso = 0;
		}
		Obstaculo::Obstaculo() :
			Entidade()
		{
			danoso = 0;
		}
		Obstaculo::~Obstaculo()
		{}

	}
}