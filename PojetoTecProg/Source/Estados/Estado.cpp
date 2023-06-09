#include "..\Estados\Estado.h"
#include "..\Gerenciadores\MaquinadeEstados.h"
#include "..\Menus\MenuPrincipal.h"
#include "..\Menus\MenuPausa.h"
#include "..\Menus\GameOver.h"
#include "..\Estados\EstadoJogar.h"
#include "..\Fases\Fase1.h"
#include "..\Fases\Fase2.h"
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

	Estado* Estado::criaestadojogar_fase1(bool p) 
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Fase1());
		fase->criaMapa(p);
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Fase1" << std::endl;
			exit(1);
		}
	}

	Estado* Estado::criaestadojogar_fase2(bool p)
	{
		Fases::Fase* fase = static_cast<Fases::Fase*>(new Fases::Fase2());
		fase->criaMapa(p);
		if (fase) {
			Estados::EstadoJogar* estado = new EstadoJogar(fase);
			return static_cast<Estados::Estado*> (estado);
		}
		else {
			std::cout << "ERROR nao foi possivel criar uma Fase2" << std::endl;
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
		Fases::Fase* fase1 = static_cast<Fases::Fase*>(new Fases::Fase1());
		Fases::Fase* fase2 = static_cast<Fases::Fase*>(new Fases::Fase2());
		if (fas == "Fase2") {
			fase2->carregaSave();
			if (fase2) {
				Estados::EstadoJogar* estado = new EstadoJogar(fase2);
				return static_cast<Estados::Estado*> (estado);
			}
		}
		else if (fas == "Fase1") {
			fase1->carregaSave();
			if (fase1) {
				Estados::EstadoJogar* estado = new EstadoJogar(fase1);
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
	Estado* Estado::criaestadoRanking()
	{
		Ranking* ranking = new Ranking();
		return static_cast<Estados::Estado*>(ranking);
	}

	Estado* Estado::criaestado(string i) {
		Estado* estado = NULL;
		if      (i == "jogar_fase1_1p") {
			estado = estado->criaestadojogar_fase1(false);
		}
		else if (i == "jogar_fase1_2p") {
			estado = estado->criaestadojogar_fase1(true);
		}
		else if (i == "jogar_fase2_1p") {
			estado = estado->criaestadojogar_fase2(false);
		}
		else if (i == "jogar_fase2_2p") {
			estado = estado->criaestadojogar_fase2(true);
		}
		else if (i == "Menu_principal") {
			estado = estado->criaestadoMenuPrincipal();
		}
		else if (i == "Menu_pausa") {
			estado = estado->criaestadoMenuPausa();
		}
		else if (i == "carregar_fase")
			estado = estado->criarestadoCarregarFase();
		else if (i == "Game_overVenceu") {
			estado = estado->criaestadoGameOver(true);
		}
		else if (i == "Game_overPerdeu") {
			estado = estado->criaestadoGameOver(false);
		}
		else if (i == "ranking") {
			estado = estado->criaestadoRanking();
		}
		return estado;
	}

	void Estado::passaFase1()
	{
		pMaquinadeEstados->remove();
		std::ifstream recuperaPonto("ponto.dat", std::ios::in);
		if (!recuperaPonto)
			exit(1);
		string i,j;
		recuperaPonto >> i >> j;
		Estado* estado = NULL;
		if (i=="jogador2") 
			pMaquinadeEstados->incluir("jogar_fase2_1p");
		else
			pMaquinadeEstados->incluir("jogar_fase2_2p");
		recuperaPonto.close();
	}
	void Estado::gameOver(const bool vitoria)
	{
		if (vitoria)
			pMaquinadeEstados->incluir("Game_overVenceu");
		else
			pMaquinadeEstados->incluir("Game_overPerdeu");
	}
	Estado* Estado::criaestadoGameOver(const bool venceu)
	{
		Menus::GameOver* gameover = new Menus::GameOver(venceu);
		return static_cast <Estados::Estado*>(gameover);
	}
	
}
