#include "..\Entidades\Personagens\Inimigo.h"

namespace Entidades
{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Personagem(tam, p, v, h),
			jogador(NULL)
		{
			id = "inimigo";
			direcao = rand() % 2;
			box.setFillColor(sf::Color::Red);
		}

		Inimigo::Inimigo() :
			Personagem(),
			jogador(NULL)
		{
			direcao = rand() % 2;
			box.setFillColor(sf::Color::Red);
		}

		Inimigo::~Inimigo()
		{
			jogador = NULL;
		}

		void Inimigo::setjogador(Jogador* j)
		{
			jogador = j;
		}

		void Inimigo::moveraleatorio()
		{
			if (direcao == 0)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (direcao == 1)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

			float dt = relogio.getElapsedTime().asSeconds();
			if (dt >= 1.0) {
				direcao = rand() % 2;
				relogio.restart();
			}
		}

		void Inimigo::move()
		{
			sf::Vector2f posjogador = jogador->getpos();
			if (fabs(posjogador.x - pos.x) < RAIO_VISAO && fabs(posjogador.y - pos.y) < RAIO_VISAO)
			{
				Perseguir();
			}
			else
				moveraleatorio();
		}

		void Inimigo::Perseguir()
		{
			if (jogador->getpos().x > pos.x)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (jogador->getpos().x < pos.x)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

		}

		void Inimigo::Executar()
		{
			move();
			//chaotemp();
			gravidade();
		}

		void Inimigo::colide(Entidade* secundaria, sf::Vector2f ds)
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
						ta_no_chao = true;
					}
					else
					{
						pos.y -= ds.y;
						vel.y = 0;
						if (ta_no_chao)
						{
							secundaria->setTa_No_Chao(true);
							secundaria->setpos(sf::Vector2f(secundaria->getpos().x, secundaria->getpos().y - ds.y));
						}
					}
				}

			}
		}
	}
}