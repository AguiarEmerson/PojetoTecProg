#pragma once
#include "..\Estados\Estado.h"

namespace Estados
{
	class EstadoJogar : public Estado
	{
	private:
		Grafico* grafo;
		Fases::Fase* fase;
	public:
		EstadoJogar(Fases::Fase* fase);
		~EstadoJogar();
		Fases::Fase* getfase();
		void Executar();
	};
}
