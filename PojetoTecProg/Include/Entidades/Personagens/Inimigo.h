#pragma once
#include "Jogador.h"

using namespace Gerenciadores;
namespace Entidades
{
	namespace Personagens {
		class Inimigo :public Personagem
		{
		protected:
			float dt;
			float tempo_total;
			bool primeiro_ciclo;
			int direcao;
		public:
			Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Inimigo();

			~Inimigo();

			virtual void move() = 0;
			
			void coice(Entidade* entidade,float angulo);

			virtual void Executar()=0;

			void colide(Entidade* secundaria, sf::Vector2f ds);
			void esmagado(Entidade* secundaria);
			void esmagaJogador(Entidade* entidade);

			void primTempoTotal();

			char* salvaEnt() ;
			
		};
	}
}