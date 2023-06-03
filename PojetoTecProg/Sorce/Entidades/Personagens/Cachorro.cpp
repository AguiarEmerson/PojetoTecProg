#include "..\Entidades\Personagens\Cachorro.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Cachorro::Cachorro(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h) :
			jogador(NULL),
			Inimigo(tam, p, v, h)
		{
			textura = Pgrafico->mandaTextura("Imagens/cachorro.png");
			box.setTexture(&textura);
			id = "cachorro";
			direcao = rand() % 2;
		}
		Cachorro::Cachorro():
			Inimigo(),
			jogador(NULL)
		{
			textura = Pgrafico->mandaTextura("Imagens/cachorro.png");
			box.setTexture(&textura);
			direcao = rand() % 2;
			id = "cachorro";
		}
		Cachorro::~Cachorro()
		{
			jogador = NULL;
		}


		void Cachorro::setjogador(Jogador* j)
		{
			jogador = j;
		}

		void Cachorro::moveraleatorio()
		{
			if (direcao == 0)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (direcao == 1)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
			if (dt >= TEMPOCACHORRO) {
				direcao = rand() % 2;
				tempo_total += TEMPOCACHORRO;
			}
		}

		void Cachorro:: move()
		{
			if (!(ac.x >= -0.5 && ac.x <= 0.5 && ac.y >= -0.5 && ac.y <= 0.5))
			{
				pos = pos - ac;

				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
				if (ac.y < 0)
					ac.y += 0.5;
				else
					ac.y -= 0.5;
			}
			sf::Vector2f posjogador = jogador->getpos();
			if (fabs(posjogador.x - pos.x) < RAIO_VISAO && fabs(posjogador.y - pos.y) < RAIO_VISAO)
			{
				Perseguir();
			}
			else
				moveraleatorio();
		}

		void Cachorro::Perseguir()
		{
			if (podeMover) {
				if (jogador->getpos().x > pos.x)
				{
					setpos(sf::Vector2f(pos.x + vel.x, pos.y));
				}
				if (jogador->getpos().x < pos.x)
				{
					setpos(sf::Vector2f(pos.x - vel.x, pos.y));
				}
			}

		}

		void Cachorro::Executar()
		{
			primTempoTotal();
			move();
			gravidade();
			verificaVida();
		}
	}
}