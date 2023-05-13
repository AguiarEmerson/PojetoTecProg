#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
private:	//private pra usar a sobrecarga de operadores e farmar requisito
	int hp;
public:
	Personagem(float tam = 10.0, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(3.0, 0.0),int h=3);
	~Personagem();

	void operator++();
	void operator--();

	virtual void Executar() = 0;
};