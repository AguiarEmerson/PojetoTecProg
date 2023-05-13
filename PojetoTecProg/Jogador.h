#pragma once
#include "Personagem.h"

class Jogador :public Personagem
{
private:
	int pontos;
public:
	Jogador(float tam = 10.0, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(3.0, 0.0), int h = 3,int xp=0);
	~Jogador();
	void pula();
	void move();
	void Executar();
};
