#pragma once
#include "..\Lista\ListaEntidades.h"
using namespace Listas;
namespace Gerenciadores
{
	class Gerenciador_Colisao
	{
	private:
		ListaEntidades* lista;
	public:
		Gerenciador_Colisao(ListaEntidades* listaEnt);
		Gerenciador_Colisao();
		~Gerenciador_Colisao();
		void setLista(ListaEntidades* listaEnt);
		void executar();
		sf::Vector2f calculaColisao(Entidade* entidade1, Entidade* entidade2);


	};
}

