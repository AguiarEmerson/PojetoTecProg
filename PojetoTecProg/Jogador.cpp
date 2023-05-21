#include "Jogador.h"

namespace Entidades
{
	Jogador::Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h, int xp) :
		Personagem(tam, p, v, h),
		pontos(xp)
	{
		box.setFillColor(sf::Color::Green);
	}

	Jogador::Jogador() :
		Personagem(),
		pontos(0)
	{
	}

	Jogador::~Jogador()
	{

	}

	void Jogador::pula()
	{
		if (ta_no_chao) {
			setvel(sf::Vector2f(vel.x, vel.y - 10));
		}
		setpos(sf::Vector2f(pos.x, pos.y + vel.y));
	}

	void Jogador::move()
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {		n tem porque mudar em y
			setpos(pos.x, pos.y - vel);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			setpos(pos.x, pos.y + vel);
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			setpos(sf::Vector2f(pos.x - vel.x, pos.y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			setpos(sf::Vector2f(pos.x + vel.x, pos.y));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			pula();
		}
		chaotemp();
		gravidade();
	}
	void Jogador::Executar()
	{
		move();
	}
}