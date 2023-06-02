#pragma once
#include "..\Lista\ListaEntidades.h"
#include"..\Lista\Lista.h"
#include"..\..\Macaco.h"
using namespace Listas;
using namespace Entidades;
using namespace Personagens;
namespace Gerenciadores
{
	class Colisao
	{
	private:
		ListaEntidades* lista;
		std::list<Entidade*>listaInimigo;
		std::list<Entidade*>listaObstaculo;
		std::vector<Entidade*>listaJogador;
		std::list<Entidade*>listaProjetil;




	public:
		Colisao(ListaEntidades* listaEnt);
		Colisao();
		~Colisao();
		void setLista(ListaEntidades* listaEnt);
		void executar();
		sf::Vector2f calculaColisao(Entidade* entidade1, Entidade* entidade2);


	};
}

