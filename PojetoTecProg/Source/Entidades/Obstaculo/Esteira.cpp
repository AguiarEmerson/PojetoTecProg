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
		string Esteira::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << danoso << ' '  <<direcao<<' '<<desaceleracao << ' ' << std::endl;
			



			GravadorEnt.close();
			return aux;
		}
		Entidade* Esteira::carregarEnt(string arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0, desac = 0;;
			bool chao = false, move = false, danos = false, viv = false;
			int dir = 0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> danos >> dir>> desac;
			Esteira* esteira = new Esteira(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));
			esteira->setTa_No_Chao(chao);
			esteira->setVivo(viv);
			esteira->setPodeMover(move);
			esteira->setDesaceleracao(desac);
			esteira->setDirecao(dir);

			RecuperadorEnt.close();
			return static_cast<Entidade*>(esteira);
		}
		void Esteira::setDirecao(int dir)
		{
			direcao = dir;
		}
		void Esteira:: setDesaceleracao(float desac)
		{
			desaceleracao = desac;
		}
	}
}
int Entidades::Obstaculos::Esteira::num_Esteira = 0;
