#pragma once
#include "..\Estados\Estado.h"
#include "..\Menus\Botao.h"
#include "..\Gerenciadores\MaquinadeEstados.h"
#include"..\Gerenciadores\Grafico.h"
#include "..\Menus\Menu.h"

namespace Estados
{
	class Ranking:public Estados::Estado
	{
	protected:
		static Gerenciadores::Grafico* Pgrafico;
		Menus::Botao botao;
		std::list<Menus::Texto*>textos;
		float tempo_total;
	public:
		Ranking();
		~Ranking();
		void selecionar(Menus::Botao* botao);
		void controlar();
		void Executar();
		void desenha();
		void criaNumero();
		void criaNomes();



	};
}

