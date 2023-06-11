#include "..\Menus\GameOver.h"

namespace Menus
{
	GameOver::GameOver(bool ganhou) :
		Menu("Game over", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y)), 
		pontuacao(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), "Sua pontuacao foi:"),
		Estado(),nome(Pgrafico->carregarFonte("Arquivos/Fonte.ttf")), situacao(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"))
	{
		nomeMenu.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 6.0));
		nome.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 2.4));
		situacao.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 4.8));
		pontuacao.setPos(sf::Vector2f(tamjanela.x / 2.0f - tambotao.x / 2.0f, tamjanela.y / 2.0f - tambotao.y * 3.6));
		if (ganhou) {
			situacao.setinfo("Voce ganhou");
		}
		else {
			situacao.setinfo("Voce Perdeu");
		}
		criabotoes();
	}
	GameOver::~GameOver()
	{
	}

	void GameOver::selecionar(Botao* botao)
	{
		if (botao->getinfo() == "Sair") {


			Pgrafico->fecha();
		}
	}

	void GameOver::cadastrar()
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			nome.pop();
		}
		
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
		nome + ' ';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			nome + 'Q';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			nome + 'W';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			nome + 'E';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			nome + 'R';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			nome + 'T';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			nome + 'Y';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			nome + 'U';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			nome + 'I';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			nome + 'O';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			nome + 'P';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			nome + 'A';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			nome + 'S';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			nome + 'D';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			nome + 'F';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			nome + 'G';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			nome + 'H';
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			nome + 'J';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			nome + 'K';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
		{
			nome + 'L';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			nome + 'Z';
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			nome + 'X';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			nome + 'C';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			nome + 'V';
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			nome + 'B';
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			nome + 'N';
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			nome + 'M';
		}
	}

	void GameOver::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f ));
		it = listabotao.begin();
		(*it)->seleciona(true);
	}

	void GameOver::Executar()
	{
		Pgrafico->resetarJanela();
		desenha();
		Pgrafico->desenha(nomeMenu.getTexto());
		Pgrafico->desenha(nome.getTexto());
		Pgrafico->desenha(situacao.getTexto());
		Pgrafico->desenha(pontuacao.getTexto());
		cadastrar();
		controlar();
	}
}
