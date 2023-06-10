#pragma once
#include "Lista.h"
#include "..\Entidades\Entidade.h"

using namespace Entidades;
namespace Listas 
{
	class ListaEntidades
	{
	private:
		static Gerenciadores::Grafico* Pgrafico;
		Lista<Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidade* pE);
		void percorrer();
		void desenhar();
		void retirar(Entidade* pE);
		const int getTam();
		Entidade* getEnt(int pos);
		void LimpaLista();
		Lista<Entidade>::Elemento<Entidade>* getPrim();
	};
}
