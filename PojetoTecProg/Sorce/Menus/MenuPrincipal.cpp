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
		if      (botao->getinfo() == "Jogar Fase 1") {
			pMaquinadeEstados->incluir("jogar_fase1");
		}
		else if (botao->getinfo() == "Jogar Fase 2") {
			pMaquinadeEstados->incluir("jogar_fase2");
		}
		else if (botao->getinfo() == "Continuar") {
			printf("TA CARRGANDO........");
		}
		else if (botao->getinfo() == "Placar") {
			printf("TA MOSTRANDO O PLACAR.......");
		}
		else if (botao->getinfo() == "sair") {
			//pMaquinadeEstados->remove();
			Pgrafico->fecha();
		}
	}

	void MenuPrincipal::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Jogar Fase 1", sf::Vector2f(botaoposx, tamjanela.y / 2.0f));
		incluibotao("Jogar Fase 2", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 1.2));
		incluibotao("Continuar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 2.4));
		incluibotao("Placar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 3.6));
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 4.8));
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

