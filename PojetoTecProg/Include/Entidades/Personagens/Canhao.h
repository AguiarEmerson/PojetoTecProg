#pragma once
#include "../Entidades/Personagens/Inimigo.h"
#include "../Projetil.h"

namespace Entidades
{
	namespace Personagens {
		class Canhao:public Inimigo
		{
		protected:
			Projetil projetil;
			static int num_Canhao;
			const int num;
			
		public:
			Canhao(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Canhao();
			~Canhao();

			void move();
			void Executar();

			void controlaProjetil();
			Projetil* getProjetil();

			string salvaEnt();

			static Entidade* carregarEnt(string arquivo);

			void setProjetil(Projetil* projeti);


			

		};
	}
}