#pragma once
#include "Elemento.h"
template <class TL> class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int tam;
public:
	Lista();
	~Lista();
	int getTam();
	TL* getElem(int posicao);
	void push(TL* item);
	void pop(TL item);
	Elemento<TL>* getPrim();


};

