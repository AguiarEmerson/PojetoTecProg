#pragma once
#include "..\stdafx.h"

namespace Menus
{
	class Texto 
	{
	protected:
		sf::Text texto;
		const sf::Font fonte;
		std::string info;
		sf::Vector2f tam;
		int tamFonte;
		sf::Color cortexto;
		sf::Color corborda;
		void inicializa();
	public:
		Texto(const sf::Font fonte, const std::string info="", const unsigned int tamFonte = 50);
		~Texto();
		const sf::Text getTexto() const;
		const std::string getinfo() const;
		void setinfo(const std::string i);
		void setPos(const sf::Vector2f pos);
		void operator+(char l);
		void pop();
		sf::Vector2f getTam();
	};
}