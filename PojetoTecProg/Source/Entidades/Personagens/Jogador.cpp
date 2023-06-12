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
			podeMover = true;
			ganhouFase = false;
		}

		Jogador::Jogador() :
			Personagem(),
			pontos(0)
		{
			ganhouFase = false;
		}

		Jogador::~Jogador()
		{

		}

		void Jogador::pula()
		{
			if (ta_no_chao) {
				vel.y = -sqrt(2.0 * GRAVIDADE * ALTURAPULO);
				ta_no_chao = false;
			}
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
							setAc(sf::Vector2f(-FORCAPROJETIL*secundaria->getvel().x, 0.0f));
						}
						if (secundaria->getId() == "espinho")
						{
							setAc(sf::Vector2f(IMPULSOESPINHOL * vel.x, 0.0f));
							danoEspinho(secundaria);
						}
						if (secundaria->getId() == "plataforma" || secundaria->getId() == "mola" || secundaria->getId() == "esteira")
							setAc(sf::Vector2f(0.0f, 0.0f));
					}
					else
					{
						pos.x -= ds.x;	
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-FORCAPROJETIL*secundaria->getvel().x, 0));
						}
						if (secundaria->getId() == "espinho")
						{
								setAc(sf::Vector2f(-IMPULSOESPINHOL * vel.x, 0.0f));
								danoEspinho(secundaria);
						}
						if (secundaria->getId() == "plataforma" || secundaria->getId() == "mola" || secundaria->getId() == "esteira")
							setAc(sf::Vector2f(0.0f, 0.0f));
					}
				}
				else
				{
					if (pos.y < pos2.y)
					{
						if(secundaria->getId()=="plataforma")
							ta_no_chao = true;
						pos.y += ds.y;
						if (secundaria->getId() == "Esteira")
						{
							acimaEsteira(secundaria);
						}
						if (secundaria->getId() == "trampolim")
						{
							pulaTramp(secundaria);

						}
						if (secundaria->getId() == "projetil")
						{
							deletaProjetil(secundaria);
							setAc(sf::Vector2f(-FORCAPROJETIL*secundaria->getvel().x, 0));
						}
						if (secundaria->getId() == "espinho")
						{
							setvel(sf::Vector2f(vel.x, -PULOALTO));
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
							setAc(sf::Vector2f(-FORCAPROJETIL*secundaria->getvel().x, 0));
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
			setvel(sf::Vector2f(vel.x, -sqrt(2.0*GRAVIDADE*ALTURAPULO)));
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
				setvel(sf::Vector2f(vel.x, -PULOALTO));
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
		const int Jogador::getDano() {
			return dano;
		}
		void Jogador::acimaEsteira(Entidade* ent)
		{
			Esteira* Esteira = NULL;
			Esteira = static_cast<Obstaculos::Esteira*>(ent);
			Personagem* personagem=NULL;
			personagem = static_cast<Personagem*>(this);
			Esteira->colideJogador(personagem);
		}
		void Jogador::setPontos(int pont)
		{
			pontos = pont;
		}

		void Jogador::GanhaPonto(int pont)
		{
			pontos += pont;
		}
		void Jogador::setGanhou(const bool fas){
			ganhouFase = fas;
		}
		const bool Jogador::getGanhou(){
			return ganhouFase;
		}
		void Jogador::verificaGanhou(){
			if (pos.x > TAMANHOFASE)
				ganhouFase = 1;
		}
		const int Jogador::getPonto()
		{
			return pontos;
		}

		
	}
}