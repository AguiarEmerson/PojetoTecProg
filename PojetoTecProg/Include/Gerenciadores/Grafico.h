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
		std::map<const char*, sf::Texture> mapatexturas;
		sf::RectangleShape fundo;

		ListaEntidades* lista;

		//singleton
		static Grafico* gerenciador_grafico;
		Grafico();
		
	public:
		~Grafico();
		static Grafico* getgrafico();
		void desenha(sf::RectangleShape box);
		void desenha(sf::Text tex);
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
		sf::Font carregarFonte(const char* caminhoFonte);
		sf::Texture carregarTextura(const char* caminhoTextura);
		sf::Texture mandaTextura(const char* caminhoTextura);
		void setFundo(sf::RectangleShape box);
		void atualizaFundo();
		
	};
}