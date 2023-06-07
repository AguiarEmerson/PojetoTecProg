#include "..\Entidades\Personagens\RoboPula.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		RoboPula::RoboPula(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),num(num_RoboPula)
		{
			textura = Pgrafico->mandaTextura("Imagens/RoboPula.png");
			box.setTexture(&textura);
			id = "RoboPula";
			direcao = rand() % 2;
			altura = 0;
			num_RoboPula++;
		}
		RoboPula::RoboPula() :
			Inimigo(), num(num_RoboPula)
		{
			textura = Pgrafico->mandaTextura("Imagens/RoboPula.png");
			box.setTexture(&textura);
			id = "RoboPula";
			altura = 0;
			direcao = rand() % 2;
			num_RoboPula++;
		}
		RoboPula::~RoboPula()
		{
		}
		void RoboPula::move() {
			if (ta_no_chao) {
				dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
				if (dt >= TEMPORoboPula) {
					pula();
					tempo_total += TEMPORoboPula;
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


		void RoboPula::Executar() {
			primTempoTotal();
			move();
			gravidade();
			verificaVida();	
		}

		void RoboPula::pula() {
			if (ta_no_chao) {
				altura = float(rand() % 10)+6.5f;
				setvel(sf::Vector2f(vel.x, vel.y - altura));
				setpos(sf::Vector2f(pos.x, pos.y + vel.y));
			}
			ta_no_chao = false;

			setpos(sf::Vector2f(pos.x, pos.y + vel.y));
		}

		char* RoboPula::salvaEnt()
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
			

			return nomeArquivo;
		}

	}
}
int Entidades::Personagens::RoboPula::num_RoboPula = 0;