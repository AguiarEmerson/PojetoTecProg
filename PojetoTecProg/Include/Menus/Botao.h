#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "Texto.h"

namespace Menus
{
	class Botao 
	{
	protected:
		sf::RectangleShape caixa;
		Texto texto;
		sf::Vector2f pos;
		sf::Vector2f tam;
		bool selecionado;
		const sf::Color corselecionado;
		static Gerenciadores::Grafico* Pgrafico;
	public:
		Botao(const std::string info,const sf::Vector2f tam, sf::Vector2f pos);
		~Botao();
		void seleciona(const bool selecionado);
		const bool getselecionado() const;
		void atualizapos(sf::Vector2f pos);
		const sf::Vector2f getpos() const;
		const Texto gettexto() const;
		void desenha();
	};
}