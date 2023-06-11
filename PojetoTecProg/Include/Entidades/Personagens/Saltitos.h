#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class saltitos :public Inimigo
		{
		protected:
			float altura;
			static int num_saltitos;
			const int num;
		public:

			saltitos(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			saltitos();

			~saltitos();

			void pula();
			void move();
			void Executar();

			string salvaEnt();
			static Entidade* carregarEnt(string arquivo);

			void setAltura(float alt);


		};
	}
}

