#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class Cachorro :public Inimigo {
		protected:
			std::list<Jogador*> listaJogador;
		public:
			Cachorro(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Cachorro();

			~Cachorro();

			void setjogador(Jogador* j);
			void moveraleatorio();
			void Perseguir();
			void move();
			void Executar();
			Jogador* decideJogador();
		};
	}
}