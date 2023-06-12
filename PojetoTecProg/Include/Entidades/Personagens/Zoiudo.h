#pragma once
#include "robo.h"
namespace Entidades
{
	namespace Personagens
	{
		class zoiudo:public Jogador
		{
		protected:
			robo* jogador;

		public:
			zoiudo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
			zoiudo();
			void move();
			void setJogador(robo* joga);
			void controlaCamera();
			void Executar();

			string salvaEnt();
			static Entidade* carregarEnt(string arquivo);
		};
	}
}