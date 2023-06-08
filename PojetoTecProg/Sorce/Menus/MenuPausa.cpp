#include "..\Menus\MenuPausa.h"

namespace Menus
{
	MenuPausa::MenuPausa(Fases::Fase* fase) :
		Estado(), fase(fase),
		Menu("Pausado", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y))
	{
		criabotoes();
	}
	MenuPausa::~MenuPausa()
	{
	}
	void MenuPausa::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Salvar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f));
		incluibotao("Voltar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 1.2));
		it = listabotao.begin();
		(*it)->seleciona(true);
	}

	void MenuPausa::selecionar(Botao* botao)
	{
		if (botao->getinfo() == "Salvar") 
		{
			fase->salva();
		}
		else if (botao->getinfo() == "Voltar") {
			pMaquinadeEstados->remove();
		}
	}

	void MenuPausa::Executar()
	{
		desenha();
		Pgrafico->desenha(nomeMenu.getTexto());
		controlar();
	}
	
}