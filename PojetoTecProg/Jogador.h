#pragma once
#include "Personagem.h"

namespace Entidades
{
	class Jogador :public Personagem
	{
	protected:
		int pontos;
	public:
		Jogador(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3, int xp = 0);
		Jogador();
		~Jogador();
		void pula();
		void move();
		void Executar();
	};
}