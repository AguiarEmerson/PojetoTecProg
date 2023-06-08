#include "..\Entidades\Obstaculos\Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v),num(num_Plataforma)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/plataforma.png");
			box.setTexture(&textura);
			id = "plataforma";
			estatico = true;
			num_Plataforma++;
		}
		Plataforma::Plataforma() :
			Obstaculo(), num(num_Plataforma)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/plataforma.png");
			box.setTexture(&textura);
			id = "plataforma";
			estatico = true;
			num_Plataforma++;
		}
		Plataforma::~Plataforma() {

		}
		void Plataforma::colide(Entidade* secundaria, sf::Vector2f ds)
		{
			//ele não colide com o personagem, o personagem colide com ele
		}
		void Plataforma::Executar()
		{
		}
		string Plataforma::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << danoso << ' ' << estatico << ' ' << std::endl;


			return aux;
		}
		Entidade* Plataforma::carregarEnt(char* arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0;
			bool chao = false, move = false, danos = false, viv = false,estatic=false;
				
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> danos >> estatic;
			Plataforma* plataforma = new Plataforma(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));
			plataforma->setTa_No_Chao(chao);
			plataforma->setVivo(viv);
			plataforma->setPodeMover(move);
			plataforma->setDanoso(danos);
			plataforma->setEstatico(estatic);




			return static_cast<Entidade*>(plataforma);

		}
		void Plataforma::setEstatico(const bool estatic)
		{
			estatico = estatic;
		}

		

	}
}
int Entidades::Obstaculos::Plataforma::num_Plataforma = 0;