#pragma once
#include"stdafx.h"

//#include"..\Gerenciadores\Grafico.h"
namespace Gerenciadores {
	class Grafico;
}
class Ente
{
protected:
	static Gerenciadores::Grafico* Pgrafico;
	sf::RectangleShape box;
	sf::Clock relogio;
	string id;


public:
	Ente(sf::Vector2f tam = sf::Vector2f(60.0, 60.0));
	~Ente();
	
	sf::RectangleShape getbox(); 
	string getId();
	virtual void Executar() = 0;
};