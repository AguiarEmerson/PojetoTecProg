#pragma once
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\Menu.h"
#include "..\Estados\Estado.h"

namespace Menus
{
	class MenuPrincipal: public Menu,public Estados::Estado
	{
	private:
		void criabotoes();
		 
	public:
		MenuPrincipal();
		~MenuPrincipal();
		void selecionar(Botao* botao);
		void Executar();
	};
}