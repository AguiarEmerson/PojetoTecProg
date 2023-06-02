#include "..\Entidades\Obstaculos\Trampolim.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Trampolim::Trampolim(float velocidades,sf::Vector2f tam, sf::Vector2f p , sf::Vector2f v ):
			Obstaculo(tam,p,v)
		{
			id = "trampolim";
			podePular = true;
			velocidade = velocidades;
		}
		Trampolim::Trampolim():
			Obstaculo()
		{

			id = "trampolim";
		}

		Trampolim::~Trampolim()
		{
		}
		void Trampolim::colide(Entidade* secundaria, sf::Vector2f ds) 
		{
		}
		void Trampolim::Executar() 
		{
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		void Trampolim::jogadorPula(Entidade* joga) 
		{
			if (dt >= 5.0f && podePular == false)
			{
				podePular = true;
				Pgrafico->getrelogio().restart();
			}
				
		}

		const bool Trampolim::getPodePular()
		{
			return podePular;
		}
		void Trampolim:: setPodePular(const bool pula)
		{
			podePular = pula;
		}
		

	}
}