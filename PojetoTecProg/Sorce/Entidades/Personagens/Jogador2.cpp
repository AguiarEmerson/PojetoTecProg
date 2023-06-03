#include "..\..\..\Include\Entidades\Personagens\Jogador2.h"
namespace Entidades
{
	namespace Personagens
	{
		Jogador2::Jogador2(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h, int xp) :
			Jogador(tam, p, v, h, xp)
		{
			box.setFillColor(sf::Color::Red);
		}
		Jogador2::Jogador2() :
			Jogador()
		{

		}
		void Jogador2::move() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				pula();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (!(ac.x >= -0.5 && ac.x <= 0.5))
			{
				pos = pos - ac;

				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
			}
		}
		void Jogador2::setJogador(Jogador1* joga)
		{
			jogador = joga;
		}
		void Jogador2::controlaCamera()
		{
			if (jogador == NULL || jogador->getVivo() == false)
			{
				Pgrafico->atualizacam(sf::Vector2f(pos.x, TAMW_Y / 2.0));
			}
			else if (vivo == false)
			{
				Pgrafico->atualizacam(sf::Vector2f(jogador->getpos().x, TAMW_Y / 2.0));
			}
			else
			{
				Pgrafico->atualizacam(sf::Vector2f((pos.x + jogador->getpos().x) / 2, TAMW_Y / 2.0));
			}
		}
		void Jogador2::Executar()
		{
			if (vivo == true) {
				move();
				gravidade();
				verificaVida();
			}
			controlaCamera();
		}
	}
}
