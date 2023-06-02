#include "Projetil.h"
namespace Entidades
{
	Projetil::Projetil(sf::Vector2f tam, sf::Vector2f p , sf::Vector2f v ):
		Entidade(tam,p,v)
	{
		existe = false;
		id = "projetil";
	}
	Projetil::Projetil():
		Entidade()
	{
		existe = false;
	}
	Projetil::~Projetil()
	{
	}
	void Projetil::colide(Entidade* secundaria, sf::Vector2f ds)
	{

	}
	void Projetil::move()
	{
		setpos(sf::Vector2f(pos.x + vel.x, pos.y));

	}
	void Projetil::Executar()
	{
		move();
		gravidade();
	}
	const bool Projetil::verificaExiste() {
		return existe;
	}
	void Projetil::setExiste(const bool existindo) {
		existe = existindo;
	}
	void Projetil::atualizaExiste() {
		if (pos.y > 590) {
			existe = false;
		}
	}
	void Projetil::reiniciaProjetil(sf::Vector2f novapos, sf::Vector2f novavel)
	{
		pos = novapos;
		vel = novavel;
		existe = true;
	}

}
