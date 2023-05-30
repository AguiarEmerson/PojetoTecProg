#include "..\Entidades\Personagens\Personagem.h"

namespace Entidades
{
	namespace Personagens {
		Personagem::Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Entidade(tam, p, v),
			num_vidas(h)
		{
		}

		Personagem::Personagem() :
			Entidade(),
			num_vidas(3)
		{
		}

		Personagem::~Personagem()
		{
		}

		void Personagem::setAc(sf::Vector2f aceleracao)
		{
			ac = aceleracao;
		}
		sf::Vector2f Personagem::getAc()
		{
			return ac;
		}

		
	}
}