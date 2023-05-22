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
		template <class TL> class Elemento
		{
		private:
			Elemento<TL>* pProx;
			TL* pInfo;
		public:
			Elemento() { pProx = nullptr; pInfo = nullptr; }
			~Elemento() {}
			TL* getData() { return pInfo; }
			void setData(TL* pp) { pInfo = pp; }
			void setProx(Elemento<TL>* prox) { pProx = prox; }
			Elemento<TL>* goProx(Elemento<TL>* temp) { return temp->getProx(); }
			Elemento<TL>* getProx() { return pProx; }

		};


		int getTam();
		TL* getElem(int posicao);
		void push(TL* item);
		void pop(TL* item);
		Elemento<TL>* getPrim() { return pPrimeiro; }



	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;
		int tam;
	};
	template<class TL>
	Lista<TL>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = 0;
		tam = 0;
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
		Elemento<TL>* temp = pPrimeiro;
		for (i = 0; i < posicao; i++) {
			temp = temp->goProx(temp);
		}
		return temp->getData();
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
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* antTemp = nullptr;
		while (temp->getData() != item)
		{
			antTemp = temp;
			temp = temp->goProx(temp);
		}
		if (temp == pPrimeiro)
		{
			pPrimeiro = temp->getProx();
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
	//template<class TL>
	//Lista<TL>::Elemento<TL>* Lista<TL>::getPrim() 
}
