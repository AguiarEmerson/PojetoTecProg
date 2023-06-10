#pragma once
#include "Personagem.h"
#include"..\Projetil.h"
#include"..\Obstaculos\Trampolim.h"
#include"..\Obstaculos\Espinho.h"
#include "..\Obstaculos\Esteira.h"


namespace Entidades
{
	using namespace Obstaculos;
	namespace Personagens {
		class Jogador :public Personagem
		{
		protected:
			int pontos;
			bool ganhouFase;
			
		public:
			Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			Jogador();
			~Jogador();
			void pula();
			virtual void move()=0;
			virtual void Executar()=0;
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void esmagaInimigo(Entidade* inimigo);
			void pulaTramp(Entidade* ent);
			void deletaProjetil(Entidade* projetil);
			void danoEspinho(Entidade* entidade);
			const int getDano();
			void acimaEsteira(Entidade* ent);
			virtual string salvaEnt() = 0;
			void setPontos(int pont);
			const int getPonto();
			void GanhaPonto(int pont);

			void setGanhou(const bool fas);
			const bool getGanhou();
			void verificaGanhou();
			
		};
	}
}