#include "..\Lista\ListaEntidades.h"
#include "..\Gerenciadores\Grafico.h"

namespace Listas {

	Gerenciadores::Grafico* ListaEntidades::Pgrafico = Gerenciadores::Grafico::getgrafico();

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

	void ListaEntidades::desenhar() {
		int i, tam = LEs.getTam();
		for (i = 0; i < tam; i++)
		{
			if (LEs.getElem(i)->getVivo() == true) {
				Pgrafico->desenha(LEs.getElem(i)->getbox());
			}
		}
	}

	void ListaEntidades::retirar(Entidade* pE) {
		LEs.pop(pE);
	}
	const int ListaEntidades::getTam()
	{
		return LEs.getTam();
	}
	Entidade* ListaEntidades::getEnt(int pos)
	{
		return LEs.getElem(pos);
	}
	void ListaEntidades::LimpaLista()
	{
		int i = 0, tam = 0;
		tam = LEs.getTam();
		for (i = 0; i < tam; i++)
			LEs.pop(LEs.getElem(i));
	}
	Lista<Entidade>::Elemento<Entidade>* ListaEntidades::getPrim()
	{
		return LEs.getPrim();
	}
	
}

