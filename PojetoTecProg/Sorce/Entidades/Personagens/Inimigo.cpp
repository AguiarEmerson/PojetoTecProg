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
			if (!(ac.x>=-0.5&&ac.x<=0.5&&ac.y>=-0.5&&ac.y<=0.5))
			{
				pos = pos - ac;
				
				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
				if (ac.y < 0)
					ac.y += 0.5;
				else
					ac.y -= 0.5;
			}
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
			if (podeMover) {
				if (jogador->getpos().x > pos.x)
				{
					setpos(sf::Vector2f(pos.x + vel.x, pos.y));
				}
				if (jogador->getpos().x < pos.x)
				{
					setpos(sf::Vector2f(pos.x - vel.x, pos.y));
				}
			}

		}
		
		void Inimigo::coice(Entidade* entidade,float angulo)
		{
			ac.x = ac.x + cos(angulo) * 7;
			vel.y = vel.y + sin(angulo) * 7;
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(entidade);
			jogador->setAc(sf::Vector2f(-(jogador->getAc().x + cos(angulo) * 7), jogador->getAc().y));
			jogador->setvel(sf::Vector2f(jogador->getvel().x, jogador->getvel().y - sin(angulo) * 7));


		}


		void Inimigo::Executar()
		{
			move();
			gravidade();
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
						angulo = atan2f((pos2.y + tam2.y - pos.y - tam1.y),(pos2.x + tam2.x - pos.x - tam1.x));
						if (secundaria->getId() == "jogador")
							coice(secundaria, angulo);
					}
					else
					{
						pos.x -= ds.x;
						angulo = atan2f((pos2.y + tam2.y - pos.y - tam1.y), (pos2.x + tam2.x - pos.x - tam1.x));
						if (secundaria->getId() == "jogador")
							coice(secundaria, angulo);
				
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
						if (secundaria->getId() == "jogador")
							tomaDano();
						pos.y -= ds.y;
						vel.y = 0;
					}
				}

			}
		}

		void Inimigo::tomaDano()
		{
			num_vidas--;
		}
	}
}