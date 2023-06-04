#include "..\Entidades\Personagens\Cachorro.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Cachorro::Cachorro(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h) :
			Inimigo(tam, p, v, h)
		{
			textura = Pgrafico->mandaTextura("Imagens/cachorro.png");
			box.setTexture(&textura);
			id = "cachorro";
			direcao = rand() % 2;
		}
		Cachorro::Cachorro():
			Inimigo()
		{
			textura = Pgrafico->mandaTextura("Imagens/cachorro.png");
			box.setTexture(&textura);
			direcao = rand() % 2;
			id = "cachorro";

		}
		Cachorro::~Cachorro()
		{
			listaJogador.clear();
		}


		void Cachorro::setjogador(Jogador* j)
		{
			listaJogador.push_back (j);
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
			sf::Vector2f posjogador = decideJogador()->getpos();
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
				if (decideJogador()->getpos().x > pos.x)
				{
					setpos(sf::Vector2f(pos.x + vel.x, pos.y));
				}
				if (decideJogador()->getpos().x < pos.x)
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
		Jogador* Cachorro::decideJogador()
		{
			if (listaJogador.front()->getVivo() == true)
				return listaJogador.front();
			else
				return listaJogador.back();
		}
	}
}