#include "..\Estados\Estado.h"
#include "..\Estados\EstadoJogar.h"

namespace Estados
{
	Estado::Estado():
		Ente()
	{
	}
	Estado::~Estado()
	{
	}

	Estado* Estado::criaestadojogar_fase1() 
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Fase1());
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Fase1" << std::endl;
			exit(1);
		}
	}

	Estado* Estado::criaestadojogar_fase2()
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Fase2());
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Fase2" << std::endl;
			exit(1);
		}
	}

	Estado* Estado::criaestado(string i) {
		Estado* estado = NULL;
		if      (i == "jogar_fase1") {
			estado = estado->criaestadojogar_fase1();
		} 
		else if (i == "jogar_fase2") {
			estado = estado->criaestadojogar_fase2();
		}
		return estado;
	}
}