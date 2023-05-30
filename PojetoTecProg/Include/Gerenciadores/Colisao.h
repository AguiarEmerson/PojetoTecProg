#pragma once
#include "..\Lista\ListaEntidades.h"
using namespace Listas;
namespace Gerenciadores
{
	class Colisao
	{
	private:
		ListaEntidades* lista;
	public:
		Colisao(ListaEntidades* listaEnt);
		Colisao();
		~Colisao();
		void setLista(ListaEntidades* listaEnt);
		void executar();
		sf::Vector2f calculaColisao(Entidade* entidade1, Entidade* entidade2);


	};
}

