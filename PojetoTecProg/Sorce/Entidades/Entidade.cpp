#include "..\Entidades\Entidade.h"

namespace Entidades
{
	Entidade::Entidade( sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
		Ente(tam),
		ta_no_chao(false)
	{
		setpos(p);
		setvel(v);
	}

	Entidade::Entidade() :
		Ente(),
		ta_no_chao(false)
	{
		setpos(sf::Vector2f(500.0, 0.0));
		setvel(sf::Vector2f(3.0, 0.0));
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::setpos(sf::Vector2f p)
	{
		pos = p;
		box.setPosition(p.x, p.y);
	}

	sf::Vector2f Entidade::getpos()
	{
		return pos;
	}

	void Entidade::setvel(sf::Vector2f v)
	{
		vel = v;
	}

	sf::Vector2f Entidade::getvel()
	{
		return vel;
	}

	void Entidade::gravidade()
	{
		if (ta_no_chao) {
			setvel(sf::Vector2f(vel.x, 0.0));
		}
		else {
			setvel(sf::Vector2f(vel.x, vel.y + GRAVIDADE)); //0.3 == gravidade
		}
		setpos(sf::Vector2f(pos.x, pos.y + vel.y));
	}

	void Entidade::chaotemp()
	{
		if (pos.y > 500) {
			ta_no_chao = true;
			setpos(sf::Vector2f(pos.x, 500));
		}
		else {
			ta_no_chao = false;
		}
	}
	sf::Vector2f Entidade::getTam()
	{
		return tam;
	}
}
