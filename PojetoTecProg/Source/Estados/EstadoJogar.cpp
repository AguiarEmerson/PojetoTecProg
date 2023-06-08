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
	}
}