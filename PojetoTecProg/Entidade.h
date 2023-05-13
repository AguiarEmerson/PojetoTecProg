#pragma once
#include"Ente.h"

class Entidade :public Ente
{
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	bool ta_no_chao;
public:
	Entidade(float tam=10.0, sf::Vector2f p= sf::Vector2f(0.0,0.0), sf::Vector2f v = sf::Vector2f(8.0, 0.0));
	~Entidade();
	
	void setpos(sf::Vector2f p);
	sf::Vector2f getpos();

	void setvel(sf::Vector2f v);
	sf::Vector2f getvel();

	void gravidade();
	void chaotemp();   // chaozinho temporario pra testar enquanto ainda n tem plataforma

	virtual void Executar() = 0;
};
