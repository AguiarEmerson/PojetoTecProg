#pragma once
#include "..\Entidade.h"

namespace Entidades
{
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:	//private pra usar a sobrecarga de operadores e farmar requisito
			int num_vidas;
		public:
			Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h);
			Personagem();
			~Personagem();

			virtual void Executar() = 0;
			virtual void colide(Entidade* secundaria, sf::Vector2f ds) = 0;
			
		};
	}
}