#include "..\Estados\EstadoJogar.h"

namespace Estados
{
	EstadoJogar::EstadoJogar(string i)
	{
		if (i == "Fase1" || i == "Fase2") {
			criafase(i);
		}
		else {
			std::cout << "ERROR parametro de estado jogar errado" << std::endl;
			exit(1);
		}
	}
	EstadoJogar::~EstadoJogar()
	{
		if (fase) {
			delete(fase);
			fase = nullptr;
		}
	}
	void EstadoJogar::criafase(string i)
	{
		if (i == "Fase1") {
			fase = static_cast<Fases::Fase*>(new Fases::Fase1());
		}
		if (i == "Fase2") {
			fase = static_cast<Fases::Fase*>(new Fases::Fase1());
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