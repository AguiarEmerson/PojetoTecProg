#pragma once
#include "Personagem.h"
#include"..\..\..\Projetil.h"
#include"..\..\..\Trampolim.h"
#include"..\..\..\Espinho.h"


namespace Entidades
{
	using namespace Obstaculos;
	namespace Personagens {
		class Jogador :public Personagem
		{
		protected:
			int pontos;
			
		public:
			Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			Jogador();
			~Jogador();
			void pula();
			void move();
			void Executar();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void esmagaInimigo(Entidade* inimigo);
			void pulaTramp(Entidade* ent);
			void deletaProjetil(Entidade* projetil);
			void danoEspinho(Entidade* entidade);
			int getDano();
			
		};
	}
}