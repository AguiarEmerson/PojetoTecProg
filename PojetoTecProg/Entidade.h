#pragma once
#include"Ente.h"

class Entidade :public Ente
{
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
public:
	Entidade(float tam,float x=0.0,float y=0.0);
	~Entidade();
	
	void setpos(float x = 0.0, float y = 0.0);
	sf::Vector2f getpos();

	void setvel(float x = 0.0, float y = 0.0);
	sf::Vector2f getvel();

	virtual void Execute() = 0;
};
