#include "..\Entidades\Obstaculos\Trampolim.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Trampolim::Trampolim(float velocidades,sf::Vector2f tam, sf::Vector2f p , sf::Vector2f v ):
			Obstaculo(tam,p,v),num(num_Trampolim)
		{
			id = "trampolim";
			podePular = true;
			velocidade = velocidades;
			textura = Pgrafico->carregarTextura("Imagens/trampolim.png");
			box.setTexture(&textura);
			num_Trampolim++;
		}
		Trampolim::Trampolim():
			Obstaculo(), num(num_Trampolim)
		{
			velocidade = 20.0;
			id = "trampolim";
			textura = Pgrafico->carregarTextura("Imagens/trampolim.png");
			box.setTexture(&textura);
			num_Trampolim++;
		}

		Trampolim::~Trampolim()
		{
		}
		void Trampolim::colide(Entidade* secundaria, sf::Vector2f ds) 
		{
		}
		void Trampolim::Executar() 
		{
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
		}
		void Trampolim::jogadorPula(Entidade* joga) 
		{
			if (dt >= TEMPOTRAMPOLIM && podePular == false)
			{
				podePular = true;
				tempo_total+=TEMPOTRAMPOLIM;
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

		void Trampolim::primTempoTotal() {
			if (primeiro_ciclo)
			{
				primeiro_ciclo = 0;
				tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
			}
		}
		char* Trampolim::salvaEnt()
		{
			char* nomeArquivo = criaNomeArquivo(num);


			return nomeArquivo;
		}

		

	}
}
int Entidades::Obstaculos::Trampolim::num_Trampolim = 0;