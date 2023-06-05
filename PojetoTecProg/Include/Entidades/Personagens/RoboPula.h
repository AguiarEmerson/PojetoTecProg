#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Entidades
{
	namespace Personagens {
		class RoboPula :public Inimigo
		{
		protected:
		
			float altura;

		public:

			RoboPula(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			RoboPula();

			~RoboPula();

			void pula();
			void move();
			void Executar();


		};
	}
}
