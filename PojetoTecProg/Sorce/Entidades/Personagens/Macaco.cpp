#include "..\Entidades\Personagens\Macaco.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Macaco::Macaco(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),
			projetil(sf::Vector2f(15.0,15.0),sf::Vector2f(p.x,p.y+tam.y+0.5),sf::Vector2f(0.0,0.0))
		{
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

	
			float dt = Pgrafico->getrelogio().getElapsedTime().asSeconds();
			if (dt >= 2.0&&dt<=4) {
				direcao = rand() % 2;
			}
			else if (dt <= 4.0)
			{
				if (direcao == 1)
					setpos(sf::Vector2f(getpos().x + getvel().x, getpos().y));
				if (direcao == 0)
					setpos(sf::Vector2f(getpos().x - getvel().x, getpos().y));
			}
			else
				Pgrafico->getrelogio().restart();
		}
		void Macaco::Executar()
		{
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