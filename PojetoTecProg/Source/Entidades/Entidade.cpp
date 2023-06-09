#include "..\Entidades\Entidade.h"

namespace Entidades
{
	Entidade::Entidade( sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
		Ente(),
		ta_no_chao(false)
	{
		podeMover = true;
		setbox(tam);
		setpos(p);
		setvel(v);
		vivo = true;
	}

	Entidade::Entidade() :
		Ente(),
		ta_no_chao(false)
	{
		setbox(sf::Vector2f(50.0, 50.0));
		setpos(sf::Vector2f(0.0, 0.0));
		setvel(sf::Vector2f(3.0, 0.0));
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::setbox(sf::Vector2f tam)
	{
		box = sf::RectangleShape(tam);
	}

	const sf::RectangleShape Entidade::getbox()
	{
		return box;
	}


	void Entidade::setpos(sf::Vector2f p)
	{
		pos = p;
		box.setPosition(p.x, p.y);
	}

	const sf::Vector2f Entidade::getpos()
	{
		return pos;
	}

	void Entidade::setvel(const sf::Vector2f v)
	{
		vel = v;
	}

	const sf::Vector2f Entidade::getvel()
	{
		return vel;
	}

	void Entidade::atualizaposicao()
	{
		if (ta_no_chao) {
			vel.y = 0.0;
		}
		else {
			vel.y += GRAVIDADE;
		}
		setpos(sf::Vector2f(pos.x+vel.x, pos.y + vel.y));
	}
	const sf::Vector2f Entidade::getTam()
	{
		return box.getSize();
	}
	void Entidade::setTa_No_Chao(const bool chao)
	{
		ta_no_chao = chao;
	}
	void Entidade::setPodeMover(const bool mover)
	{
		podeMover = mover;
	}
	void Entidade::setVivo(const bool vive) {
		vivo = vive;
	}
	const bool Entidade::getVivo() {
		return vivo;
	}

	string Entidade::criaNomeArquivo(int num)
	{
		return id + std::to_string(num) + ".dat";
	}
	string Entidade::criaNomeArquivo()
	{
		
		return id+".dat";

	}
}
