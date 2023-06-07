#pragma once
#include "..\Entidade.h"

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
			virtual void colide(Entidade* secundaria, sf::Vector2f ds) = 0;
			virtual void Executar() = 0;

			virtual char* salvaEnt() = 0;
			virtual Entidade* carregarEnt(char* arquivo) = 0;

		};
	}
}