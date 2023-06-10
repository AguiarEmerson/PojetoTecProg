#include "..\Estados\EstadoJogar.h"

namespace Estados
{
	EstadoJogar::EstadoJogar(Fases::Fase* fase) :
		fase(fase)
	{
	}
	EstadoJogar::~EstadoJogar()
	{
		if (fase) {
			delete(fase);
			fase = nullptr;
		}
	}
	Fases::Fase* EstadoJogar::getfase()
	{
		return fase;
	}
	void EstadoJogar::Executar()
	{				
		fase->Executar();
		if (fase->getGanho() == 1) {
			fase->salvaPonto();
			passaFase1();
		}
		else if (fase->getGanho() == 2)
		{
			fase->salvaPonto();
			gameOver(true);
		}
		else if (fase->getPerdeu() == true)
		{
			fase->salvaPonto();
			gameOver(false);
		}
	}
}