#pragma once
#include "Obstaculo.H"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma :public Obstaculo
		{
		protected:
			bool estatico;

		public:
			Plataforma(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Plataforma();
			~Plataforma();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void Executar();
		};
	}
}