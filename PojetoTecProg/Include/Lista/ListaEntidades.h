#pragma once
#include "Lista.h"
#include "..\Entidades\Entidade.h"
using namespace Entidades;
namespace Listas 
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidade* pE);
		void percorrer();
		void retirar(Entidade* pE);
		int getTam();
		Entidade* getEnt(int pos);
	};
}
