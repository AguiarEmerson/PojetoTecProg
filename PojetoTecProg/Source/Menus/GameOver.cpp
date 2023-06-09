#include "..\Menus\GameOver.h"

namespace Menus
{
	GameOver::GameOver(bool ganhou) :
		Menu("Game over", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)),
		Estado()
	{
		nomeMenu.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 6.0));
		if (ganhou) {
			Texto situacao(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), "Voce venceu", 75);
			situacao.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 5.0));
		}
		else {
			Texto situacao(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), "Voce Perdeu", 75);
			situacao.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 5.0));
		}
		criabotoes();
	}
	GameOver::~GameOver()
	{

	}

	void GameOver::selecionar(Botao* botao)
	{
		if (botao->getinfo() == "Cadastrar") {
			printf("TA CADASTRANDO");
		}
		else if (botao->getinfo() == "Sair") {
			Pgrafico->fecha();
		}
	}

	void GameOver::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Cadastrar", sf::Vector2f(botaoposx, tamjanela.y / 2.0f));
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f + tambotao.y * 1.2));
		it = listabotao.begin();
		(*it)->seleciona(true);
	}

	void GameOver::Executar()
	{
		Pgrafico->resetarJanela();
		desenha();
		Pgrafico->desenha(nomeMenu.getTexto());
		controlar();
	}
}
