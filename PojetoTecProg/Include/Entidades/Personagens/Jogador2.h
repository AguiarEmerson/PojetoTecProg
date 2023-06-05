#pragma once
#include "Jogador1.h"
namespace Entidades
{
	namespace Personagens
	{
		class Jogador2:public Jogador
		{
		protected:
			Jogador1* jogador;

		public:
			Jogador2(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			Jogador2();
			void move();
			void setJogador(Jogador1* joga);
			void controlaCamera();
			void Executar();
		};
	}
}