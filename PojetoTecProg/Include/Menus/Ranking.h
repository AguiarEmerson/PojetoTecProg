#pragma once
#include "..\Estados\Estado.h"
#include "Botao.h"
#include "..\Gerenciadores\MaquinadeEstados.h"
#include"..\Gerenciadores\Grafico.h"

namespace Menus
{
	class Ranking:public Estados::Estado
	{
	protected:
		static Gerenciadores::Grafico* Pgrafico;
		Botao botao;
		std::list<Texto*>textos;
	public:
		Ranking();
		~Ranking();
		void selecionar(Botao* botao);
		void controlar();
		void Executar();
		void desenha();
		void criaNumero();
		void criaNomes();



	};
}

