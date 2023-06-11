#include "..\Entidades\Personagens\saltitos.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		saltitos::saltitos(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),num(num_saltitos)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/saltitos.png");
			box.setTexture(&textura);
			id = "saltitos";
			direcao = rand() % 2;
			altura = 0;
			num_saltitos++;
			ponto = 200;
		}
		saltitos::saltitos() :
			Inimigo(), num(num_saltitos)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/saltitos.png");
			box.setTexture(&textura);
			id = "saltitos";
			altura = 0;
			direcao = rand() % 2;
			num_saltitos++;
		}
		saltitos::~saltitos()
		{
		}
		void saltitos::move() {
			if (ta_no_chao) {
				dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
				if (dt >= TEMPOsaltitos) {
					pula();
					tempo_total += TEMPOsaltitos;
					direcao = rand() % 2;
				}
				

			}
			else {
				if(direcao==1)
					setpos(sf::Vector2f(pos.x + vel.x, pos.y));
				else
					setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}
		}


		void saltitos::Executar() {
			primTempoTotal();
			move();
			gravidade();
			verificaVida();	
		}

		void saltitos::pula() {
			if (ta_no_chao) {
				altura = float(rand() % 10)+6.5f;
				setvel(sf::Vector2f(vel.x, vel.y - altura));
				setpos(sf::Vector2f(pos.x, pos.y + vel.y));
			}
			ta_no_chao = false;

			setpos(sf::Vector2f(pos.x, pos.y + vel.y));
		}

		string saltitos::salvaEnt()
		{

			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];
			
			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{
				
				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			//escolher oq quer salvar e salvar
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << direcao <<' '<<altura<< std::endl;

			GravadorEnt.close();
			return aux;
		}

	}
	Entidade* saltitos:: carregarEnt(string arquivo)
	{

		std::ifstream RecuperadorEnt(arquivo, std::ios::in);
		if (!RecuperadorEnt)
		{
			std::cout << "nao foi possivel abrir o arquivo" << std::endl;
			exit(1);
		}
		float posx = 0, posy = 0, velx = 0, vely = 0, acx = 0, acy = 0,altura=0;
		bool chao = false, move = false, viv = false;
		int dan = 0, num_vida = 0, direca = 0;
		RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida >> dan >> acx >> acy >> direca>>altura;
		saltitos* saltitos = new Personagens::saltitos(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
		saltitos->setTa_No_Chao(chao);
		saltitos->setVivo(viv);
		saltitos->setPodeMover(move);
		saltitos->setAc(sf::Vector2f(acx, acy));
		saltitos->setDirecao(direca);
		saltitos->setDano(dan);
		saltitos->setAltura(altura);

		RecuperadorEnt.close();



		return static_cast<Entidade*>(saltitos);
	}
	void saltitos::setAltura(float alt)
	{
		altura = alt;
	}
}
int Entidades::Personagens::saltitos::num_saltitos = 0;