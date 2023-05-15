#include "Lista.h"

template<class TL>
Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	tam = nullptr;
}
template<class TL>
Lista<TL>::~Lista()
{
	
}
template<class TL>
int Lista<TL>::getTam()
{
	return tam;
}
template<class TL>
TL* Lista<TL>::getElem(int posicao) {
	int i;
	Elemento<TL*> temp = pPrimeiro;
	for (i = 0; i < posicao; i++) {
		temp = temp.pProx; 
	}
	return temp;	
}
template<class TL>
void Lista<TL> ::push(TL* item)
{
	if (item)
	{
		if (pPrimeiro == nullptr)
		{
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setData(item);
			pUltimo = pPrimeiro;
		}
		else
		{
			Elemento<TL>* temp;
			pUltimo->setProx(temp);
			pUltimo = temp;
			pUltimo->setProx(nullptr);
		}
		tam++;
	}

}
template<class TL>
void Lista<TL>::pop(TL item)
{
	Elemento<TL>* temp;
	Elemento<TL>* antTemp;
	while (temp->getData() != item)
	{	
		antTemp = temp;
		temp = temp->getProx();
	}
	if (temp == pPrimeiro)
	{
		pPrimeiro=temp->getProx();
	}
	else if (temp == pUltimo)
	{
		antTemp->setProx(nullptr);
		pUltimo = antTemp;
	}
	else
	{
		antTemp->setProx(temp->getProx());
	}
	delete temp;
	tam--;
}
template<class TL>
Elemento<TL>* Lista<TL>::getPrim()
{
	return pPrimeiro;
}

