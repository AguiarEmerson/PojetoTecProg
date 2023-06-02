#pragma once
#include "..\Personagens\Inimigo.h"
#include "..\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class Sapo :public Inimigo
		{
		protected:
			int direcao;
			float altura;

		public:

			Sapo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h);
			Sapo();

			~Sapo();

			void pula();
			void move();
			void Executar();


		};
	}
}

