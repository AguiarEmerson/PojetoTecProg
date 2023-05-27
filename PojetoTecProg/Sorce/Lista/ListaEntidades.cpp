#include "ListaEntidades.h"

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
		LEs.getElem(pos);
	}
}

