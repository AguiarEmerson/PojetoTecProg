#include "..\Estados\Estado.h"
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\MenuPrincipal.h"
#include "..\Menus\MenuPausa.h"
#include "..\Menus\GameOver.h"
#include "..\Estados\EstadoJogar.h"
#include "..\Fases\Floresta.h"
#include "..\Fases\Ceus.h"
#include "..\Estados\Ranking.h"

namespace Estados
{
	Gerenciadores::MaquinadeEstados* Estado::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

	Estado::Estado()
	{
	}
	Estado::~Estado()
	{
	}

	Estado* Estado::criaestadojogar_Floresta(bool p) 
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Floresta());
		fase->criaMapa(p);
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Floresta" << std::endl;
			exit(1);
		}
	}

	Estado* Estado::criaestadojogar_Ceus(bool p)
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Ceus());
		fase->criaMapa(p);
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Ceus" << std::endl;
			exit(1);
		}
	}
	Estado* Estado::criarestadoCarregarFase()
	{
		std::ifstream qualFase("fase.dat", std::ios::in);
		if (!qualFase)
		{
			std::cout << "nao foi possivel carregar fase" << std::endl;
			exit(1);
		}
		string fas;
		qualFase >> fas;
		Fases::Fase* Floresta = static_cast<Fases::Fase*>(new Fases::Floresta());
		Fases::Fase* Ceus = static_cast<Fases::Fase*>(new Fases::Ceus());
		if (fas == "Ceus") {
			Ceus->carregaSave();
			if (Ceus) {
				Estados::EstadoJogar* estado = new EstadoJogar(Ceus);
				return static_cast<Estados::Estado*> (estado);
			}
		}
		else if (fas == "Floresta") {
			Floresta->carregaSave();
			if (Floresta) {
				Estados::EstadoJogar* estado = new EstadoJogar(Floresta);
				return static_cast<Estados::Estado*> (estado);
			}
		}
		else
		{
			std::cout << "nao foi possivel carregar fase" << std::endl;
			exit(1);
		}
		qualFase.close();
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

	Estado* Estado::CriaestadoGameOver(bool ganhou)
	{
		Menus::GameOver* gameover = new Menus::GameOver(ganhou);
		return static_cast<Estados::Estado*>(gameover);
	}
	Estado* Estado::criaestadoRanking()
	{
		Ranking* ranking = new Ranking();
		return static_cast<Estados::Estado*>(ranking);
	}

	Estado* Estado::criaestado(string i) {
		Estado* estado = NULL;
		if      (i == "jogar_Floresta_1p") {
			estado = estado->criaestadojogar_Floresta(false);
		}
		else if (i == "jogar_Floresta_2p") {
			estado = estado->criaestadojogar_Floresta(true);
		}
		else if (i == "jogar_Ceus_1p") {
			estado = estado->criaestadojogar_Ceus(false);
		}
		else if (i == "jogar_Ceus_2p") {
			estado = estado->criaestadojogar_Ceus(true);
		}
		else if (i == "Menu_principal") {
			estado = estado->criaestadoMenuPrincipal();
		}
		else if (i == "Menu_pausa") {
			estado = estado->criaestadoMenuPausa();
		}
		else if (i == "carregar_fase") {
			estado = estado->criarestadoCarregarFase();
		}
		else if (i == "Game_over_win") {
			estado = estado->CriaestadoGameOver(true);
		}
		else if (i == "Game_over_lose") {
			estado = estado->CriaestadoGameOver(false);
		}
		else if (i == "ranking") {
			estado = estado->criaestadoRanking();
		}
		return estado;
	}

	void Estado::passaFloresta()
	{
		pMaquinadeEstados->remove();
		std::ifstream recuperaPonto("ponto1.dat", std::ios::in);
		if (!recuperaPonto)
			exit(1);
		string i,j;
		recuperaPonto >> i >> j;
		Estado* estado = NULL;
		if (i=="zoiudo") 
			pMaquinadeEstados->incluir("jogar_Ceus_1p");
		else
			pMaquinadeEstados->incluir("jogar_Ceus_2p");
		recuperaPonto.close();
	}
	void Estado::gameOver(const bool vitoria)
	{
		if (vitoria)
			pMaquinadeEstados->incluir("Game_over_win");
		else
			pMaquinadeEstados->incluir("Game_over_lose");
	}

	
}
