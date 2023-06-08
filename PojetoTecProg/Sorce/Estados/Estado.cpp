#include "..\Estados\Estado.h"
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\MenuPrincipal.h"
#include "..\Menus\MenuPausa.h"
#include "..\Estados\EstadoJogar.h"
#include "..\Fases\Fase1.h"
#include "..\Fases\Fase2.h"

namespace Estados
{
	Gerenciadores::MaquinadeEstados* Estado::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

	Estado::Estado()
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

	Estado* Estado::criaestadoMenuPrincipal()
	{
		Menus::MenuPrincipal* menuprincipal=new Menus::MenuPrincipal();
		return static_cast <Estados::Estado*>(menuprincipal);
	}

	Estado* Estado::criaestadoMenuPausa()
	{
		Menus::MenuPausa* menupausa = new Menus::MenuPausa(static_cast<Estados::EstadoJogar*>(pMaquinadeEstados->getestadoAT())->getfase());
			return static_cast <Estados::Estado*>(menupausa);
	}

	Estado* Estado::criaestado(string i) {
		Estado* estado = NULL;
		if      (i == "jogar_fase1") {
			estado = estado->criaestadojogar_fase1();
		} 
		else if (i == "jogar_fase2") {
			estado = estado->criaestadojogar_fase2();
		}
		else if (i == "Menu_principal") {
			estado = estado->criaestadoMenuPrincipal();
		}
		else if (i == "Menu_pausa") {
			estado = estado->criaestadoMenuPausa();
		}
		return estado;
	}
	
}
