#include "..\Entidades\Obstaculos\Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v)
		{
			textura = Pgrafico->mandaTextura("Imagens/plataformal.png");
			box.setTexture(&textura);
			id = "plataforma";
			estatico = true;
		}
		Plataforma::Plataforma() :
			Obstaculo()
		{
			textura = Pgrafico->mandaTextura("Imagens/plataformal.png");
			box.setTexture(&textura);
			estatico = true;
		}
		Plataforma::~Plataforma() {

		}
		void Plataforma::colide(Entidade* secundaria, sf::Vector2f ds)
		{
			//o tipo de colisão é 0 para pra baixo, 1 para o lado direito, 2 para cima e 3 para o lado esquerdo
			sf::Vector2f pos2 = secundaria->getpos();

			if (ds.y <= 0.0f && ds.x <= 0.0f)
			{
				if (ds.y <= ds.x)
				{
					//bloco 1 acima do 2
					if (pos.x < pos2.x)
					{
						pos.x += ds.x;
					}
					else
					{
						pos.x -= ds.x;
					}
				}
				else
				{
					if (pos.y < pos2.y)
					{
						pos.y += ds.y;
					}
					else
					{
						pos.y -= ds.y;
					}
				}

			}
		}
		void Plataforma::Executar()
		{
		}

		

	}
}