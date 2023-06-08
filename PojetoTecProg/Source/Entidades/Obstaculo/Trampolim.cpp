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
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/trampolim.png");
			box.setTexture(&textura);
			num_Trampolim++;
		}
		Trampolim::Trampolim():
			Obstaculo(), num(num_Trampolim)
		{
			velocidade = 20.0;
			id = "trampolim";
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/trampolim.png");
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
		string Trampolim::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << danoso << ' ' << velocidade << std::endl;

			GravadorEnt.close();

			return aux;
		}
		Entidade* Trampolim::carregarEnt(string arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}

			float posx = 0, posy = 0, velx = 0, vely = 0,veloci=0;
			bool chao = false, move = false, danos = false, viv = false;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> danos >>veloci;
			Trampolim* trampolim = new Trampolim(veloci,sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));
			trampolim->setTa_No_Chao(chao);
			trampolim->setVivo(viv);
			trampolim->setPodeMover(move);
			


			RecuperadorEnt.close();
			return static_cast<Entidade*>(trampolim);
		}
		

		

	}
}
int Entidades::Obstaculos::Trampolim::num_Trampolim = 0;