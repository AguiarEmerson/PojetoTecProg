#include "..\..\..\Include\Entidades\Obstaculos\Espinho.h"
#include "..\Gerenciadores\Grafico.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v),num(num_Espinhos)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/espinho.png");
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
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/espinho.png");
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
		string Espinho::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo=&aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << danoso << ' ' << dano << ' ' << std::endl;
			GravadorEnt.close();

			return aux;
		}
		Entidade* Espinho::carregarEnt(string arquivo)
		{
			

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}

			float posx = 0, posy = 0, velx = 0, vely = 0;
			bool chao = false, move = false, danos = false,viv=false;
			int dan = 0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> danos >> dan;
			Espinho* espinho = new Espinho(sf::Vector2f(50.0,50.0),sf::Vector2f(posx,posy),sf::Vector2f(velx,vely));
			espinho->setTa_No_Chao(chao);
			espinho->setVivo(viv);
			espinho->setPodeMover(move);
			espinho->setDanoso(danos);
			espinho->setDano(dan);

			RecuperadorEnt.close();

			return static_cast<Entidade*>(espinho);


		}
		void Espinho::setDano(int dan)
		{
			dano = dan;
		}

	}
}
int Entidades::Obstaculos::Espinho::num_Espinhos = 0;