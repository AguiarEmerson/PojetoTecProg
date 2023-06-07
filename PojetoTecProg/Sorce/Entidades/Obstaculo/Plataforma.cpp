#include "..\Entidades\Obstaculos\Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v),num(num_Plataforma)
		{
			textura = Pgrafico->mandaTextura("Imagens/plataforma.png");
			box.setTexture(&textura);
			id = "plataforma";
			estatico = true;
			num_Plataforma++;
		}
		Plataforma::Plataforma() :
			Obstaculo(), num(num_Plataforma)
		{
			textura = Pgrafico->mandaTextura("Imagens/plataforma.png");
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
		char* Plataforma::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}


			return nomeArquivo;
		}
		Entidade* Plataforma::carregarEnt(char* arquivo)
		{

		}

		

	}
}
int Entidades::Obstaculos::Plataforma::num_Plataforma = 0;