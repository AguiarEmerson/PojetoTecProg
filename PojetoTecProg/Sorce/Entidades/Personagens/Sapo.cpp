#include "..\Entidades\Personagens\Sapo.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Sapo::Sapo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h)
		{
			textura = Pgrafico->mandaTextura("Imagens/sapo.png");
			box.setTexture(&textura);
			id = "sapo";
			direcao = rand() % 2;
			altura = 0;
		}
		Sapo::Sapo() :
			Inimigo()
		{
			textura = Pgrafico->mandaTextura("Imagens/sapo.png");
			box.setTexture(&textura);
			id = "sapo";
			altura = 0;
			direcao = rand() % 2;
		}
		Sapo::~Sapo()
		{
		}
		void Sapo::move() {
			if (ta_no_chao) {
				dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
				if (dt >= TEMPOSAPO) {
					pula();
					tempo_total += TEMPOSAPO;
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


		void Sapo::Executar() {

			primTempoTotal();
			move();
			gravidade();
			verificaVida();	
		}

		void Sapo::pula() {
			if (ta_no_chao) {
				altura = float(rand() % 10)+6.5f;
				setvel(sf::Vector2f(vel.x, vel.y - altura));
				setpos(sf::Vector2f(pos.x, pos.y + vel.y));
			}
			ta_no_chao = false;

			setpos(sf::Vector2f(pos.x, pos.y + vel.y));
		}

	}
}