#pragma once
#include"stdafx.h"

class Ente
{
protected:               
	sf::RectangleShape box;
	sf::Clock relogio;
public:
	Ente( sf::Vector2f tam = sf::Vector2f(10.0, 10.0));
	~Ente();

	sf::RectangleShape print(); 

	virtual void Executar() = 0;
};