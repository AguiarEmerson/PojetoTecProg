#include "..\..\..\Include\Entidades\Obstaculos\Espinho.h"
#include "..\Gerenciadores\Grafico.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v),num(num_Espinhos)
		{
			textura = Pgrafico->mandaTextura("Imagens/espinho.png");
			box.setTexture(&textura);
			dt = 0.0f;
			danoso = true;
			dano = 1;
			id = "espinho";
			num_Espinhos++;
		}
		Espinho::Espinho() :
			Obstaculo(),num(num_Espinhos)
		{
			textura = Pgrafico->mandaTextura("Imagens/espinho.png");
			box.setTexture(&textura);
			dt = 0.0f;
			danoso = true;
			dano = 1;
			id = "espinho";
			num_Espinhos++;
		}
		Espinho::~Espinho()
		{
		}
		void Espinho::Executar()
		{	
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
		}
		void Espinho::colide(Entidade* secundaria, sf::Vector2f ds) {

		}
		void Espinho::danoPersonagem(Personagem* personagem) {
			if (dt >= TEMPOESPINHO) {
				personagem->tomaDano(dano);
				tempo_total+=TEMPOESPINHO;
			}


		}

		void Espinho::primTempoTotal() {
			if (primeiro_ciclo)
			{
				primeiro_ciclo = 0;
				tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
			}
		}
		char* Espinho::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo=&aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi poss�vel salvar" << std::endl;
				exit(1);
			}


			return nomeArquivo;
		}
		Entidade* Espinho::carregarEnt(char* arquivo)
		{
			Espinho* espinho = new Espinho;

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}



			return static_cast<Entidade*>(espinho);


		}

	}
}
int Entidades::Obstaculos::Espinho::num_Espinhos = 0;