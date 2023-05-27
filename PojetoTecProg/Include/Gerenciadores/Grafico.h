#pragma once
#include "..\stdafx.h"
#include "..\Entidades\Personagens\Jogador.h"

namespace Gerenciadores
{
	class Grafico
	{
	private:
		sf::RenderWindow* window;
		sf::View cam;
		Entidades::Personagens::Jogador* Pjogador;

		static Grafico* gernciador_grafico;
		Grafico(); //singleton

	public:
		~Grafico();
		static Grafico* getgrafico();
		void Render(sf::RectangleShape box);
		void display();
		void clear();
		void close();
		void setPjogador(Entidades::Personagens::Jogador* p);
		void alinhacam();
		sf::RenderWindow* getwindow();

	};
}