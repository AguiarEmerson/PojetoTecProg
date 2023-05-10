#pragma once
#include "Entidade.h"

class Player :public Entidade
{
private:
	int hp;
public:
	Player(int vida = 1);
	~Player();
	//void operator++() 
	//void operator--() sobrecarga de operadores pra cumprir o requesito
	void move();
	void Execute();
};
