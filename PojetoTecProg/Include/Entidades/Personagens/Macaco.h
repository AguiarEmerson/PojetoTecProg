#pragma once
#include "../Entidades/Personagens/Inimigo.h"
#include "../Projetil.h"

namespace Entidades
{
	namespace Personagens {
		class Macaco:public Inimigo
		{
		protected:
			Projetil projetil;
			
		public:
			Macaco(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3);
			Macaco();
			~Macaco();

			void move();
			void Executar();

			void controlaProjetil();
			Projetil* getProjetil();

			

		};
	}
}