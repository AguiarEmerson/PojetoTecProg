#include "..\Entidades\Personagens\Inimigo.h"

namespace Entidades
{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Personagem(tam, p, v, h)
		{
			box.setFillColor(sf::Color::Red);
			dano = 0;
			
		}

		Inimigo::Inimigo() :
			Personagem()
		{
			
			box.setFillColor(sf::Color::Red);
			dano = 0;
		}

		Inimigo::~Inimigo()
		{
		}

		
		void Inimigo::coice(Entidade* entidade,float angulo)
		{
			ac.x = ac.x + cos(angulo) * 7;
			vel.y = vel.y + sin(angulo) * 7;
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(entidade);
			jogador->tomaDano();
			jogador->setAc(sf::Vector2f(-(jogador->getAc().x + cos(angulo) * 7), jogador->getAc().y));
			jogador->setvel(sf::Vector2f(jogador->getvel().x, jogador->getvel().y - sin(angulo) * 7));
			

		}

		void Inimigo::colide(Entidade* secundaria, sf::Vector2f ds)
		{
			//o tipo de colisão é 0 para pra baixo, 1 para o lado direito, 2 para cima e 3 para o lado esquerdo
			sf::Vector2f pos2 = secundaria->getpos();
			sf::Vector2f tam2 = secundaria->getTam();
			sf::Vector2f tam1 = this->getTam();

			float angulo;
			if (ds.y <= 0.0f && ds.x <= 0.0f)
			{
				if (ds.y <= ds.x)
				{
					//bloco 1 acima do 2
					if (pos.x < pos2.x)
					{
						pos.x += ds.x;
						if (secundaria->getId() == "jogador") {
							angulo = atan2f((pos2.y + tam2.y - pos.y - tam1.y), (pos2.x + tam2.x - pos.x - tam1.x));
							coice(secundaria, angulo);
						}
					}
					else
					{
						pos.x -= ds.x;
						if (secundaria->getId() == "jogador") {
							angulo = atan2f((pos2.y + tam2.y - pos.y - tam1.y), (pos2.x + tam2.x - pos.x - tam1.x));
							coice(secundaria, angulo);
						}
				
					}
				}
				else
				{
					if (pos.y < pos2.y)
					{
						pos.y += ds.y;
						ta_no_chao = true;
						if (secundaria->getId() == "jogador")
						{
							esmagaJogador(secundaria);
						}
					}
					else
					{
						pos.y -= ds.y;
						vel.y = 0;
						if (secundaria->getId() == "jogador")
							esmagado(secundaria);
	
					}
				}

			}
		}


		void Inimigo::esmagado(Entidade* secundaria)
		{
			tomaDano();
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(secundaria);
			jogador->esmagaInimigo(this);
			
		}

		void Inimigo::esmagaJogador(Entidade* entidade)
		{
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(entidade);
			jogador->tomaDano();
			vel.y=-10.0f;
			ta_no_chao = false;
			jogador->setvel(sf::Vector2f(jogador->getvel().x, -jogador->getvel().y));

		}
		

		
	}
}