#pragma once
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\Menu.h"
#include "..\Estados\Estado.h"

namespace Menus
{
	class MenuPrincipal: public Menu,public Estados::Estado
	{
	private:
		static Gerenciadores::MaquinadeEstados* pMaquinadeEstados;
		void criabotoes();
	public:
		MenuPrincipal();
		~MenuPrincipal();
		void controlar();
		void selecionar(Botao*);
		void Executar();
	};
}