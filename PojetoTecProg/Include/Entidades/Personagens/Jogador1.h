#pragma once
#include "Jogador.h"
namespace Entidades
{
	namespace Personagens
	{
		class Jogador1 :public Jogador
		{ 
		protected:
			bool sozinho;
			
		public:
			Jogador1(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			Jogador1();
			~Jogador1();
			void move();
			void Executar();

			string salvaEnt();
			static Entidade* carregarEnt(string arquivo);
		};
	}
}

