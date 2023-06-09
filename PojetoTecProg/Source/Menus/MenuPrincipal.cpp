#include "..\Menus\MenuPrincipal.h"

namespace Menus
{
	MenuPrincipal::MenuPrincipal():
		Menu("Menu Principal", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
		Estado()
	{
		criabotoes();
	}
	MenuPrincipal::~MenuPrincipal()
	{

	}
	
	void MenuPrincipal::selecionar(Botao* botao)
	{
		if      (botao->getinfo() == "Jogar Fase 1: 1 player") {
			pMaquinadeEstados->incluir("jogar_fase1_1p");
		}
		else if (botao->getinfo() == "Jogar Fase 1: 2 player") {
			pMaquinadeEstados->incluir("jogar_fase1_2p");
		}
		else if (botao->getinfo() == "Jogar Fase 2: 1 player") {
			pMaquinadeEstados->incluir("jogar_fase2_1p");
		}
		else if (botao->getinfo() == "Jogar Fase 2: 2 player") {
			pMaquinadeEstados->incluir("jogar_fase2_2p");
		}
		else if (botao->getinfo() == "Continuar") {
			pMaquinadeEstados->incluir("carregar_fase");
		}
		else if (botao->getinfo() == "Placar") {
			pMaquinadeEstados->incluir("ranking");
		}
		else if (botao->getinfo() == "sair") {
			Pgrafico->fecha();
		}
	}

	void MenuPrincipal::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		nomeMenu.setPos(sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 6.0));
		incluibotao("Jogar Fase 1: 1 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 3.6));
		incluibotao("Jogar Fase 1: 2 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 2.4));
		incluibotao("Jogar Fase 2: 1 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 1.2));
		incluibotao("Jogar Fase 2: 2 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f));
		incluibotao("Continuar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 1.2));
		incluibotao("Placar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 2.4));
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 3.6));
		it = listabotao.begin();
		(*it)->seleciona(true);
	}

	void MenuPrincipal::Executar()
	{
		Pgrafico->resetarJanela();
		desenha();
		Pgrafico->desenha(nomeMenu.getTexto());
		controlar();
	}
}

