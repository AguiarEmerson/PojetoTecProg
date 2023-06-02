#pragma once
#include "Obstaculo.h"
#include "..\Personagens\Personagem.h"

namespace Entidades
{
	using namespace Personagens;
	namespace Obstaculos
	{
		class Espinho:public Obstaculo
		{
		protected:
			float dt;
			int dano;
		public:
			Espinho(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Espinho();
			~Espinho();
			void Executar();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void danoPersonagem(Personagem* personagem);
		};
	}
}

