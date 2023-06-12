#pragma once
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\Menu.h"
#include "..\Estados\EstadoJogar.h"
#include "..\Fases\Floresta.h"

namespace Menus
{
	class MenuPausa : public Menu, public Estados::Estado
	{
	private:
		Fases::Fase* fase;
		void criabotoes();
	public:
		MenuPausa(Fases::Fase* fase);
		~MenuPausa();
		void selecionar(Botao* botao);
		void Executar();
	};
}