#include "..\Entidades\Personagens\Macaco.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Macaco::Macaco(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),
			projetil(sf::Vector2f(15.0,15.0),sf::Vector2f(p.x,p.y+tam.y+0.5),sf::Vector2f(0.0,0.0))
		{
			primeiro_ciclo = 1;
			id = "macaco";
		}
		Macaco::Macaco():
			Inimigo(),
			projetil()
		{
			id = "macaco";
		}
		Macaco::~Macaco()
		{
		}

		void Macaco::move() {

	
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
			if (dt >= TEMPOMOVEMACACO / 2 &&dt<= TEMPOMOVEMACACO) {
				direcao = rand() % 2;
			}
			else if (dt <= TEMPOMOVEMACACO/2)
			{
				if (direcao == 1)
					setpos(sf::Vector2f(getpos().x + getvel().x, getpos().y));
				if (direcao == 0)
					setpos(sf::Vector2f(getpos().x - getvel().x, getpos().y));
			}
			else {
				tempo_total += TEMPOMOVEMACACO;
			}
		}
		void Macaco::Executar()
		{
			primTempoTotal();
			controlaProjetil();
			move();
			gravidade();
			verificaVida();
		}

		void Macaco::controlaProjetil()
		{
			projetil.atualizaExiste();
			if (projetil.verificaExiste() == false)
			{
				sf::Vector2f novapos;
				sf::Vector2f novavel;
				int direcao;
				direcao = rand() % 2;
				novapos.x = pos.x + rand() % int(getTam().x - projetil.getTam().x);
				novapos.y = pos.y - (projetil.getTam().y + 1.0f);
				if (direcao == 1) 
					novavel.x = (rand() % 5)+5.0f;
				
				else
					novavel.x = ( - rand() % 5 )- 5.0f;
				novavel.y = -((rand() % 5) + 10.0f);

				projetil.reiniciaProjetil(novapos, novavel);
			}
		}
		Projetil* Macaco::getProjetil()
		{
			return &projetil;
		}



	}
}