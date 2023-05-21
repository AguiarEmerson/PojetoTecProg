#pragma once
#include "Entidade.h"

namespace Entidades
{
	class Personagem : public Entidade
	{
	private:	//private pra usar a sobrecarga de operadores e farmar requisito
		int hp;
	public:
		Personagem(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h);
		Personagem();
		~Personagem();

		void operator++();
		void operator--();

		virtual void Executar() = 0;
	};
}