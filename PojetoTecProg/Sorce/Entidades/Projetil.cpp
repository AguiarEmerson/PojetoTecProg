#include "../Entidades/Projetil.h"

namespace Entidades
{
	Projetil::Projetil(sf::Vector2f tam, sf::Vector2f p , sf::Vector2f v ):
		Entidade(tam,p,v)
	{
		textura = Pgrafico->mandaTextura("Imagens/projetil.png");
		box.setTexture(&textura);
		dano = 1;
		existe = false;
		id = "projetil";
	}
	Projetil::Projetil():
		Entidade()
	{
		textura = Pgrafico->mandaTextura("Imagens/projetil.png");
		box.setTexture(&textura);
		dano = 1;
		existe = false;
		id = "projetil";
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
	void Projetil::reiniciaProjetil(const sf::Vector2f novapos, const sf::Vector2f novavel)
	{
		pos = novapos;
		vel = novavel;
		existe = true;
	}
	const int Projetil::getDano()
	{
		return dano;
	}

}
