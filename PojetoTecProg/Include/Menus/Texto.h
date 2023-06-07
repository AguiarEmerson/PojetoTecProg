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
		Texto(const sf::Font fonte, const std::string info, const unsigned int tamFonte = 50);
		~Texto();
		const sf::Text getTexto() const;
		void setPos(const sf::Vector2f pos);
		sf::Vector2f getTam();
	};
}