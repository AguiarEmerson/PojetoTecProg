#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class RoboAnda :public Inimigo {
		protected:
			std::list<Jogador*> listaJogador;
			static int num_RoboAnda;
			const int num;
		public:
			RoboAnda(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			RoboAnda();

			~RoboAnda();

			void Executar();
			void Perseguir();
			void move();
			Jogador* decideJogador();
			void setjogador(Jogador* j);
			void moveraleatorio();
			
			string salvaEnt();
			static Entidade* carregarEnt(string arquivo);
		};
	}
}