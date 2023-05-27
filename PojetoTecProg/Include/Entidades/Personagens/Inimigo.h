#pragma once
#include "Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class Inimigo :public Personagem
		{
		protected:
			Jogador* jogador;
			int direcao;
		public:
			Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Inimigo();

			~Inimigo();

			void setjogador(Jogador* j);
			void moveraleatorio();
			void move();
			void Perseguir();

			void Executar();
		};
	}
}