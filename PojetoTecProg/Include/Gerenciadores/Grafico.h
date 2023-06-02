#pragma once
#include "..\stdafx.h"
#include "..\Entidades\Personagens\Jogador.h"

#include "..\Lista\ListaEntidades.h"
using namespace Listas;

namespace Gerenciadores
{
	class Grafico
	{
	private:
		sf::RenderWindow* window;
		sf::View camera;
		sf::Clock relogio;

		ListaEntidades* lista;

		//singleton
		static Grafico* gerenciador_grafico;
		Grafico();
	public:
		~Grafico();
		static Grafico* getgrafico();
		void desenha(sf::RectangleShape box);
		const bool verificaJanelaAberta();
		void mostra();
		void limpa();
		void fecha();
		void atualizacam(sf::Vector2f pos);
		sf::View getcamera();
		void resetarJanela();
		sf::Vector2f getTamJanela();
		sf::RenderWindow* getjanela();
		sf::Clock getrelogio();
		void setLista(ListaEntidades* listaEnt);
		void executar();
	};
}