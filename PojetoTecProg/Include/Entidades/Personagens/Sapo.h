#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class Sapo :public Inimigo
		{
		protected:
		
			float altura;

		public:

			Sapo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Sapo();

			~Sapo();

			void pula();
			void move();
			void Executar();


		};
	}
}
