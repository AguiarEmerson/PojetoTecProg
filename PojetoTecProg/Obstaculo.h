#pragma once
#include "Entidade.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo :public Entidade
		{
		protected:
			bool danoso;
		public:
			Obstaculo(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Obstaculo();
			~Obstaculo();

		};
	}
}