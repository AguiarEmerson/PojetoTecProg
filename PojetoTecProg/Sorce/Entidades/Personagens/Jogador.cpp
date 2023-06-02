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
			dano = 1;
			podeMover = true;
			box.setFillColor(sf::Color::Green);
		}

		Jogador::Jogador() :
			Personagem(),
			pontos(0)
		{
			box.setFillColor(sf::Color::Green);
			dano = 1;
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
			move();
			gravidade();
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
						pos.x += ds.x;
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-2*secundaria->getvel().x, 0.0f));
						}
						if (secundaria->getId() == "espinho")
						{
							setAc(sf::Vector2f(5 * vel.x, 0.0f));
							danoEspinho(secundaria);
						}
					}
					else
					{
						pos.x -= ds.x;	
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-2*secundaria->getvel().x, 0));
						}
						if (secundaria->getId() == "espinho")
						{
								setAc(sf::Vector2f(-5 * vel.x, 0.0f));
								danoEspinho(secundaria);
						}
					}
				}
				else
				{
					if (pos.y < pos2.y)
					{
						if(secundaria->getId()=="plataforma")
							ta_no_chao = true;
						pos.y += ds.y;
						if (secundaria->getId() == "trampolim")
						{
							pulaTramp(secundaria);

						}
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-2*secundaria->getvel().x, 0));
						}
						if (secundaria->getId() == "espinho")
						{
							setvel(sf::Vector2f(vel.x, -16.0f));
							ta_no_chao = false;
							danoEspinho(secundaria);
						}
					}
					else 
					{
						pos.y -= ds.y;
						if (secundaria->getId() == "plataforma"||secundaria->getId()=="trampolim")
							vel.y = 0;
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-2*secundaria->getvel().x, 0));
						}
						if (secundaria->getId() == "espinho")
						{
							vel.y = 0;
							danoEspinho(secundaria);
						}
					}
				}

			}
		

		}
		void Jogador::esmagaInimigo(Entidade* inimigo)
		{
			setvel(sf::Vector2f(vel.x, - 10.0f));
			ta_no_chao = false;
		}
		void Jogador::deletaProjetil(Entidade* projetil)
		{
			Projetil* projet = NULL;
			projet = static_cast<Projetil*>(projetil);
			tomaDano(projet->getDano());
			projet->setExiste(false);
		}
		void Jogador::pulaTramp(Entidade* ent)
		{
			Trampolim* trampolim = NULL;
			trampolim = static_cast<Trampolim*>(ent);
			Entidade* jogador = NULL;
			jogador = static_cast<Entidade*>(this);
			trampolim->jogadorPula(jogador);
			if (trampolim->getPodePular() == false)
				setTa_No_Chao(true);
			else
			{
				setvel(sf::Vector2f(vel.x, -15.0f));
				ta_no_chao = false;
				trampolim->setPodePular(false);
			}
			

		}


		void Jogador::danoEspinho(Entidade* entidade)
		{
			Espinho* espinho=NULL;
			espinho = static_cast<Espinho*>(entidade);
			Personagem* personagem = NULL;
			personagem = static_cast<Personagem*>(this);
			espinho->danoPersonagem(personagem);
		}
		int Jogador::getDano() {
			return dano;
		}

		
	}
}