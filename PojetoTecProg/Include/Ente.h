#pragma once
#include"stdafx.h"

#include"..\Gerenciadores\Grafico.h"

class Ente
{
protected:
	static Gerenciadores::Grafico* Pgrafico;
	sf::RectangleShape box;
	sf::Clock relogio;
	string id;
public:
	Ente(sf::Vector2f tam = sf::Vector2f(10.0, 10.0));
	~Ente();

	sf::RectangleShape print(); 

	virtual void Executar() = 0;
	string getId();
};