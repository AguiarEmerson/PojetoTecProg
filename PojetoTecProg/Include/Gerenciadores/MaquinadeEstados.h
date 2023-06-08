#pragma once
#include "..\Estados\Estado.h"

namespace Gerenciadores
{
	class MaquinadeEstados
	{
	private:
		std::stack <Estados::Estado*> PilhadeEstados;

		//singletojjn
		static MaquinadeEstados* pMaquinadeEstados;
		MaquinadeEstados();
	public:
		~MaquinadeEstados();
		static MaquinadeEstados* getMaquinadeEstados();
		void incluir(string i);
		void remove();
		Estados::Estado* getestadoAT();
		void Executar();
	};
}