#pragma once
#include "..\Fases\Fase1.h"
#include "..\Fases\Fase2.h"
#include "..\Estados\Estado.h"

namespace Estados
{
	class EstadoJogar : public Estado
	{
	private:
		Fases::Fase* fase;
	public:
		EstadoJogar(string i);
		~EstadoJogar();
		void criafase(string i);
		Fases::Fase* getfase();
		void Executar();
	};
}
