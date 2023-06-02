#pragma once
#include "Entidade.h"
namespace Entidades
{
	class Projetil : public Entidade
	{

	protected:
		bool existe;
		int dano;
	public:
		Projetil(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(8.0, 0.0));
		Projetil();
		~Projetil();
		void colide(Entidade* secundaria, sf::Vector2f ds);
		void move();
		void Executar();
		const bool verificaExiste();
		void setExiste(const bool existindo);
		void atualizaExiste();
		void reiniciaProjetil(sf::Vector2f novapos,sf::Vector2f novavel);
		int getDano();


	};
}

