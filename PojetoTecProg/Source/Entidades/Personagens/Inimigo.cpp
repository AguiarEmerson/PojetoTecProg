#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Personagem(tam, p, v, h)
		{
			direcao = 0;
			primeiro_ciclo = 1;
			tempo_total = 0;
			dt = 0;
			
		}

		Inimigo::Inimigo() :
			Personagem()
		{
			direcao = 0;
			primeiro_ciclo = 1;
			tempo_total = 0;
			dt = 0;
		}

		Inimigo::~Inimigo()
		{
		}

		
		void Inimigo::coice(Entidade* entidade,float angulo)
		{
			ac.x = ac.x + cos(angulo) * VELOCIDADECOICE;
			vel.y = vel.y + sin(angulo) * VELOCIDADECOICE;
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(entidade);
			jogador->tomaDano(dano);
			jogador->setAc(sf::Vector2f(-(jogador->getAc().x + cos(angulo) * VELOCIDADECOICE), jogador->getAc().y));
			jogador->setvel(sf::Vector2f(jogador->getvel().x, jogador->getvel().y - sin(angulo) * VELOCIDADECOICE));
			

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
						if (secundaria->getId() == "robo"|| secundaria->getId() == "zoiudo") {
							angulo = atan2f((pos2.y + tam2.y - pos.y - tam1.y), (pos2.x + tam2.x - pos.x - tam1.x));
							coice(secundaria, angulo);
						}
					}
					else
					{
						pos.x -= ds.x;
						if (secundaria->getId() == "robo" || secundaria->getId() == "zoiudo") {
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
						if (secundaria->getId() == "robo" || secundaria->getId() == "zoiudo")
						{
							esmagaJogador(secundaria);
						}
					}
					else
					{
						pos.y -= ds.y;
						vel.y = 0;
						if (secundaria->getId() == "robo" || secundaria->getId() == "zoiudo")
							esmagado(secundaria);
	
					}
				}

			}
		}


		void Inimigo::esmagado(Entidade* secundaria)
		{
			
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(secundaria);
			tomaDano(jogador->getDano());
			jogador->esmagaInimigo(this);
			if (num_vidas == 0)
				jogador->GanhaPonto(ponto);
			
		}

		void Inimigo::esmagaJogador(Entidade* entidade)
		{
			Jogador* jogador = nullptr;
			jogador = static_cast<Jogador*>(entidade);
			jogador->tomaDano(dano);
			vel.y=-10.0f;
			ta_no_chao = false;
			jogador->setvel(sf::Vector2f(jogador->getvel().x, -jogador->getvel().y));
		}
		void Inimigo::primTempoTotal(){
			if (primeiro_ciclo)
			{
				primeiro_ciclo = 0;
				tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
			}
		}
		void Inimigo::setDirecao(int dir)
		{
			direcao = dir;
		}

		

		
	}
}