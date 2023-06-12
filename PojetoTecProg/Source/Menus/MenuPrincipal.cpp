#include "..\Menus\MenuPrincipal.h"

namespace Menus
{
	MenuPrincipal::MenuPrincipal():
		Menu("Menu Principal", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
		Estado()
	{
		nomeMenu.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 6.0f));
		criabotoes();
		tempo = 0.0f;
	}
	MenuPrincipal::~MenuPrincipal()
	{

	}
	
	void MenuPrincipal::selecionar(Botao* botao)
	{
		if      (botao->getinfo() == "Jogar Fase 1: 1 player") {
			pMaquinadeEstados->incluir("jogar_Floresta_1p");
		}
		else if (botao->getinfo() == "Jogar Fase 1: 2 player") {
			pMaquinadeEstados->incluir("jogar_Floresta_2p");
		}
		else if (botao->getinfo() == "Jogar Fase 2: 1 player") {
			pMaquinadeEstados->incluir("jogar_Ceus_1p");
		}
		else if (botao->getinfo() == "Jogar Fase 2: 2 player") {
			pMaquinadeEstados->incluir("jogar_Ceus_2p");
		}
		else if (botao->getinfo() == "Continuar") {
			pMaquinadeEstados->incluir("carregar_fase");
		}
		else if (botao->getinfo() == "Placar") {
			pMaquinadeEstados->incluir("ranking");
		}
		else if (botao->getinfo() == "Sair") {
			Pgrafico->fecha();
		}
	}

	void MenuPrincipal::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Jogar Fase 1: 1 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 3.6f));
		incluibotao("Jogar Fase 1: 2 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 2.4f));
		incluibotao("Jogar Fase 2: 1 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f - tambotao.y * 1.2f));
		incluibotao("Jogar Fase 2: 2 player", sf::Vector2f(botaoposx, tamjanela.y / 2.0f));
		incluibotao("Continuar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 1.2f));
		incluibotao("Placar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 2.4f));
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 3.6f));
		it = listabotao.begin();
		(*it)->seleciona(true);
	}

	void MenuPrincipal::Executar()
	{
		Pgrafico->resetarJanela();
		desenha();
		Pgrafico->desenha(nomeMenu.getTexto());
		controlar();
		tempo = Pgrafico->getrelogio().getElapsedTime().asSeconds();
	}
}

