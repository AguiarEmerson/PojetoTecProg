#pragma once
//apagar
#include<stdio.h>

namespace Listas
{
	template <class TL>
	class Lista
	{
	public:
		Lista();
		~Lista();
		template <class TE> class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pInfo;
		public:
			Elemento() { pProx = nullptr; pInfo = nullptr; }
			~Elemento() {}
			TE* getData() { return pInfo; }
			void setData(TE* pp) { pInfo = pp;}
			void setProx(Elemento<TE>* prox) { pProx = prox; }
			Elemento<TE>* getProx() { return pProx; }

		};


		int getTam();
		TL* getElem(int posicao);
		void push(TL* item);
		void pop(TL* item);
		Elemento<TL>* getPrim() { return pPrimeiro; }



	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;
		Elemento<TL>* pAtual;
		int tam;	
	};
	template<class TL>
	Lista<TL>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		pAtual = nullptr;
		tam = 0;
	}
	template<class TL>
	Lista<TL>::~Lista()
	{
		Elemento<TL>* aux=NULL;
		aux = pPrimeiro;
		Elemento<TL>* auxAnt=NULL;
		while (aux->getProx() != NULL)
		{
			delete(aux->getData());
			auxAnt = aux;
			aux = aux->getProx();
			delete(auxAnt);

		}

	}

	template<class TL>
	int Lista<TL>::getTam()
	{
		return tam;
	}
	template<class TL>
	TL* Lista<TL>::getElem(int posicao) {
		int i;
		pAtual = pPrimeiro;
		for (i = 0; i < posicao; i++) {
			pAtual=pAtual->getProx();
		}
		return pAtual->getData();
	}
	template<class TL>
	void Lista<TL> ::push(TL* item)
	{
		if (item)
		{
			if (pPrimeiro == nullptr)
			{
				Elemento<TL>* aux = new Elemento<TL>;
				if (aux != nullptr) {
					aux->setData(item);
					pPrimeiro = aux;
					pUltimo = aux;
					tam++;
				}


			}
			else
			{
				Elemento<TL>* temp = new Elemento<TL>;
				temp->setData(item);
				if (temp != nullptr)
				{
					pUltimo->setProx(temp);
					pUltimo = temp;
					tam++;
				}

			}


		}

	}
	template<class TL>
	void Lista<TL>::pop(TL* item)
	{
		pAtual = pPrimeiro;
		Elemento<TL>* antAtual = nullptr;
		while (pAtual->getData() != item)
		{
			antAtual = pAtual;
			pAtual=pAtual->getProx();
		}
		if (pAtual == pPrimeiro)
		{
			pPrimeiro = pAtual->getProx();
		}
		else if (pAtual == pUltimo)
		{
			antAtual->setProx(nullptr);
			pUltimo = antAtual;
		}
		else
		{
			antAtual->setProx(pAtual->getProx());
		}
		delete pAtual;
		tam--;
		pAtual = nullptr;
	}
	
}