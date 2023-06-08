#include "..\Entidades\Personagens\Personagem.h"

namespace Entidades
{
	namespace Personagens {
		Personagem::Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Entidade(tam, p, v),
			num_vidas(h),
			dano(1)
		{
			
		}
		Personagem::Personagem() :
			Entidade(),
			num_vidas(3),
			dano(1)
		{
		}

		Personagem::~Personagem()
		{
		}

		void Personagem::setAc(const sf::Vector2f aceleracao)
		{
			ac = aceleracao;
		}
		const sf::Vector2f Personagem::getAc()
		{
			return ac;
		}

		void Personagem::verificaVida()
		{
			if (num_vidas == 0)
				vivo = false;
		}

		void Personagem::tomaDano(const int dano)
		{
			num_vidas-= dano;
		}
	}
}