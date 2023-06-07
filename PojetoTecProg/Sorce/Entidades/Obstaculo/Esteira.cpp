#include "..\Entidades\Obstaculos\Esteira.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Esteira::Esteira(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam, p, v),num(num_Esteira)
		{
			direcao = rand() % 2;
			if(direcao)
				textura = Pgrafico->mandaTextura("Arquivos/Imagens/esteirad.png");
			else
				textura = Pgrafico->mandaTextura("Arquivos/Imagens/esteirae.png");
			box.setTexture(&textura);
			id = "Esteira";
			desaceleracao = 2.0f;
			num_Esteira++;
		}
		Esteira::Esteira() :
			Obstaculo(), num(num_Esteira)
		{
			direcao = rand()%2;
			if (direcao)
				textura = Pgrafico->mandaTextura("Imagens/esteirad.png");
			else
				textura = Pgrafico->mandaTextura("Imagens/esteirae.png");
			box.setTexture(&textura);
			id = "Esteira";
			desaceleracao = 2.0f;
			num_Esteira++;
		}
		Esteira::~Esteira() {
		}
		void Esteira::colide(Entidade* secundaria, sf::Vector2f ds)
		{
		}
		void Esteira::Executar()
		{
		}
		void Esteira::colideJogador(Personagem* personagem)
		{
			personagem->setTa_No_Chao(true);
			if(direcao)
				personagem->setAc(sf::Vector2f(personagem->getAc().x + desaceleracao, personagem->getAc().y));
			else
				personagem->setAc(sf::Vector2f(personagem->getAc().x - desaceleracao, personagem->getAc().y));

		}
		char* Esteira::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}



			GravadorEnt.close();
			return nomeArquivo;
		}
		Entidade* Esteira::carregarEnt(char* arquivo)
		{
			Esteira* esteira = new Esteira;

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}


			RecuperadorEnt.close();
			return static_cast<Entidade*>(esteira);
		}
	}
}
int Entidades::Obstaculos::Esteira::num_Esteira = 0;
