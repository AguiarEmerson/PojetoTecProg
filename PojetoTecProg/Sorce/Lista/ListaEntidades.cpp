#include "..\Lista\ListaEntidades.h"

namespace Listas {
	ListaEntidades::ListaEntidades() {
	}
	ListaEntidades::~ListaEntidades()
	{
	}
	void ListaEntidades::incluir(Entidade* pE) {
		LEs.push(pE);
	}
	void ListaEntidades::percorrer(){
		int i,tam = LEs.getTam();
		for (i = 0; i < tam; i++)
		{
			if(LEs.getElem(i)->getVivo()==true&&LEs.getElem(i)->getId()!="jogador")
				LEs.getElem(i)->Executar();
			else
				LEs.getElem(i)->Executar();
		}
	}
	void ListaEntidades::retirar(Entidade* pE) {
		LEs.pop(pE);
	}
	int ListaEntidades::getTam()
	{
		return LEs.getTam();
	}
	Entidade* ListaEntidades::getEnt(int pos)
	{
		return LEs.getElem(pos);
	}
	
}

