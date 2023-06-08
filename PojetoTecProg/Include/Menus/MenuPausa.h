#pragma once
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\Menu.h"
#include "..\Estados\Estado.h"

namespace Menus
{
	class MenuPausa : public Menu, public Estados::Estado
	{
	private:
		void criabotoes();
	public:
		MenuPausa();
		~MenuPausa();
		void selecionar(Botao* botao);
		void Executar();
	};
}