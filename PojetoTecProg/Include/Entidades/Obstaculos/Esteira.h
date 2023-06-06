#pragma once
#include "Obstaculo.H"
#include "..\..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Esteira:public Obstaculo
		{
		protected:
			float desaceleracao;
			int direcao;
		public:
			Esteira(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Esteira();
			~Esteira();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void Executar();
			void colideJogador(Personagem* personagem);
		};
	}
}
