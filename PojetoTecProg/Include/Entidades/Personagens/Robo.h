#pragma once
#include "Jogador.h"
namespace Entidades
{
	namespace Personagens
	{
		class robo :public Jogador
		{ 
		protected:
			bool sozinho;
			
		public:
			robo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			robo();
			~robo();
			void move();
			void Executar();

			string salvaEnt();
			static Entidade* carregarEnt(string arquivo);
		};
	}
}

