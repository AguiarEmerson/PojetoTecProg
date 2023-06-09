#pragma once
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "Botao.h"

namespace Menus
{
	class Menu
	{
	protected:
		std::list<Botao*> listabotao;
		std::list<Botao*>::iterator it;
		sf::Vector2f tambotao;
		sf::Vector2f tamjanela;
		Texto nomeMenu;
		static Gerenciadores::Grafico* Pgrafico;
		virtual void criabotoes() = 0;
	public:
		Menu(const string nome, sf::Vector2f tambotao, const int tamfonte=75);
		~Menu();
		void incluibotao(const std::string info, const sf::Vector2f pos);
		void selecionacima();
		void selecionabaixo();
		virtual void selecionar(Botao* botao) = 0;
		Botao* getbotaoselecionado();
		void desenha();
		void controlar();
	};
}
