#pragma once
#include "..\Menus\Menu.h"
#include "..\Estados\Estado.h"

namespace Menus
{
	class GameOver :public Menu, public Estados::Estado
	{
	private:
		void criabotoes();
	public:
		GameOver(bool Ganhou);
		~GameOver();
		void selecionar(Botao* botao);
		void Executar();
	};

}
