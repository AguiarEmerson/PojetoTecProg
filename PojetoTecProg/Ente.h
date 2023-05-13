#pragma once
#include"stdafx.h"

class Ente
{
protected:
	int id;                        //n sei pra q serve
	sf::RectangleShape box;
public:
	Ente(float tam);
	~Ente();

	sf::RectangleShape print();  //vai mudar depois que tiver o derenciador grafico

	virtual void Executar() = 0;
};