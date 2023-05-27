#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens {
		Inimigo::Inimigo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Personagem(tam, p, v, h),
			jogador(NULL)
		{
			direcao = rand() % 2;
			box.setFillColor(sf::Color::Red);
		}

		Inimigo::Inimigo() :
			Personagem(),
			jogador(NULL)
		{
			direcao = rand() % 2;
			box.setFillColor(sf::Color::Red);
		}

		Inimigo::~Inimigo()
		{
			jogador = NULL;
		}

		void Inimigo::setjogador(Jogador* j)
		{
			jogador = j;
		}

		void Inimigo::moveraleatorio()
		{
			if (direcao == 0)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (direcao == 1)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

			float dt = relogio.getElapsedTime().asSeconds();
			if (dt >= 1.0) {
				direcao = rand() % 2;
				relogio.restart();
			}
		}

		void Inimigo::move()
		{
			sf::Vector2f posjogador = jogador->getpos();
			if (fabs(posjogador.x - pos.x) < RAIO_VISAO && fabs(posjogador.y - pos.y) < RAIO_VISAO)
			{
				Perseguir();
			}
			else
				moveraleatorio();
		}

		void Inimigo::Perseguir()
		{
			if (jogador->getpos().x > pos.x)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (jogador->getpos().x < pos.x)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

		}

		void Inimigo::Executar()
		{
			move();
			chaotemp();
			gravidade();
		}
	}
}