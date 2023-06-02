#pragma once
#include "..\Personagens\Inimigo.h"
#include "..\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class Cachorro :public Inimigo {
		protected:
			Jogador* jogador;
			int direcao;
		public:
			Cachorro(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h);
			Cachorro();

			~Cachorro();

			void setjogador(Jogador* j);
			void moveraleatorio();
			void Perseguir();
			void move();
			void Executar();
		};
	}
}