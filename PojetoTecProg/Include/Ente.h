#pragma once
#include"stdafx.h"


class Ente
{
protected:               
	sf::RectangleShape box;
	sf::Clock relogio;
	string id;
public:
	Ente(sf::Vector2f tam = sf::Vector2f(60.0, 60.0));
	~Ente();

	sf::RectangleShape desenhar(); 

	virtual void Executar() = 0;
	string getId();
};