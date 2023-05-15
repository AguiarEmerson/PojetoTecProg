#include "Elemento.h"
template<class TE> 
Elemento<TE>::Elemento()
{
	pProx = nullptr;
	pInfo = nullptr;
}
template<class TE>
Elemento<TE>::~Elemento()
{
}
template<class TE>
TE Elemento<TE>::getData()
{
	return pInfo;
}
template<class TE>
void Elemento<TE>::setData(TE* pp)
{
	pInfo = pp;
}
template<class TE>
void Elemento<TE>::setProx(TE* prox)
{
	pProx = prox;
}
template<class TE>
Elemento<TE>* Elemento<TE>::getProx()
{
	return pProx;
}

