#include "..\Entidades\Personagens\Jogador.h"
#include"..\Gerenciadores\Grafico.h"


namespace Entidades
{
	namespace Personagens
	{
		Jogador::Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h, int xp) :
			Personagem(tam, p, v, h),
			pontos(xp)
		{
			id = "jogador";
			podeMover = true;
			box.setFillColor(sf::Color::Green);
		}

		Jogador::Jogador() :
			Personagem(),
			pontos(0)
		{
			box.setFillColor(sf::Color::Green);
			id = "jogador";
		}

		Jogador::~Jogador()
		{

		}

		void Jogador::pula()
		{
			if (ta_no_chao) {
				setvel(sf::Vector2f(vel.x, vel.y - 10.0f)); 
				setpos(sf::Vector2f(pos.x, pos.y + vel.y));
			}
			ta_no_chao = false;
			
			setpos(sf::Vector2f(pos.x, pos.y + vel.y));
		}

		void Jogador::move()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				pula();
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			Pgrafico->atualizacam(sf::Vector2f(pos.x, TAMW_Y / 2.0));
			if (!(ac.x >= -0.5 && ac.x <= 0.5))
			{
				pos = pos - ac;

				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
			}
			
			
		}
		void Jogador::Executar()
		{
			gravidade();
			move();
			verificaVida();
		}

		void Jogador::colide(Entidade* secundaria, sf::Vector2f ds)
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
						if(secundaria->getId()=="obstaculo")
						pos.x += ds.x;
						
					}
					else
					{
						if (secundaria->getId() == "obstaculo")
						pos.x -= ds.x;
						
					}
				}
				else
				{
					if (pos.y < pos2.y)
					{
						if (secundaria->getId() == "obstaculo") {
							pos.y += ds.y;
							if (secundaria->getId() == "obstaculo")
							{
								ta_no_chao = true;
							}
						}
					}
					else 
					{
						if (secundaria->getId() == "obstaculo") {
							pos.y -= ds.y;
							vel.y = 0;
						}
						
					}
				}

			}
		

		}
		void Jogador::esmagaInimigo(Entidade* inimigo)
		{
			setvel(sf::Vector2f(vel.x, - 15.0f));
			
			ta_no_chao = false;
		}

		
	}
}