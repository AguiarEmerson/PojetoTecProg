#pragma once
#include "..\Lista\ListaEntidades.h"
#include"..\Lista\Lista.h"
using namespace Listas;
namespace Gerenciadores
{
	class Colisao
	{
	private:
		ListaEntidades* lista;
		std::list<Entidade*>listaInimigo;
		std::list<Entidade*>listaObstaculo;
		std::vector<Entidade*>listaJogador;


	public:
		Colisao(ListaEntidades* listaEnt);
		Colisao();
		~Colisao();
		void setLista(ListaEntidades* listaEnt);
		void executar();
		sf::Vector2f calculaColisao(Entidade* entidade1, Entidade* entidade2);


	};
}

