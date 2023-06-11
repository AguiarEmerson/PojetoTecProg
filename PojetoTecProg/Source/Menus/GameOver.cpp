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
		primeiroCadastro = true;
	}
	GameOver::~GameOver()
	{
	}

	void GameOver::selecionar(Botao* botao)
	{
		if (botao->getinfo() == "Sair") {
			Pgrafico->fecha();
		}
		else if (botao->getinfo() == "Cadastrar")
		{
			if (primeiroCadastro) {
				cadastraPontuacao();
			}
			else {
				cadastrasegundaPontuacao();
			}
		}
	}

	void GameOver::cadastrar()
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && Podedigitar())
		{
			nome.pop();
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Podedigitar())
		{
		nome + ' ';
		tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&&Podedigitar())
		{
			nome + 'Q';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Podedigitar())
		{
			nome + 'W';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && Podedigitar())
		{
			nome + 'E';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && Podedigitar())
		{
			nome + 'R';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Podedigitar())
		{
			nome + 'T';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && Podedigitar())
		{
			nome + 'Y';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && Podedigitar())
		{
			nome + 'U';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && Podedigitar())
		{
			nome + 'I';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && Podedigitar())
		{
			nome + 'O';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && Podedigitar())
		{
			nome + 'P';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Podedigitar())
		{
			nome + 'A';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Podedigitar())
		{
			nome + 'S';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Podedigitar())
		{
			nome + 'D';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && Podedigitar())
		{
			nome + 'F';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && Podedigitar())
		{
			nome + 'G';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && Podedigitar())
		{
			nome + 'H';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Podedigitar())
		{
			nome + 'J';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Podedigitar())
		{
			nome + 'K';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && Podedigitar())
		{
			nome + 'L';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Podedigitar())
		{
			nome + 'Z';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && Podedigitar())
		{
			nome + 'X';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && Podedigitar())
		{
			nome + 'C';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && Podedigitar())
		{
			nome + 'V';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && Podedigitar())
		{
			nome + 'B';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && Podedigitar())
		{
			nome + 'N';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && Podedigitar())
		{
			nome + 'M';
			tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
		}
	}

	void GameOver::criabotoes()
	{
		float botaoposx = tamjanela.x / 2.0f - tambotao.x / 2.0f;
		incluibotao("Sair", sf::Vector2f(botaoposx, tamjanela.y / 2.0f ));
		incluibotao("Cadastrar", sf::Vector2f(botaoposx, tamjanela.y / 2 + tamjanela.y / 4));
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
		tempo = Pgrafico->getrelogio().getElapsedTime().asSeconds();
	}
	void GameOver::salvaPonto(string nomeJ, int ponto)
	{
		std::ifstream pegaRanking("ranking.dat", std::ios::in);

		int i;
		string nomeAux;
		int pontoAux;
		std::multimap<int,string>ranking;
		for (i = 0; i < 5; i++)
		{
			pegaRanking >> nomeAux >> pontoAux;
			ranking.insert(std::pair<int,string>(pontoAux , nomeAux));
		}
		pegaRanking.clear();
		pegaRanking.close();
		
		ranking.insert(std::pair<int, string>(ponto, nomeJ));
		std::ofstream geraRanking("ranking.dat", std::ios::out);
		std::multimap<int, string> aux;
		std::multimap<int, string>::iterator it;
		int j;
		for(i=0;i<5;i++)
		{
			it = ranking.begin();
			for (j=0;j<ranking.size()-i-1;j++)
			{
				it++;
			}
			aux.insert(std::pair<int, string>(it->first, it->second));
			
		}
		for (it = aux.begin(); it != aux.end(); it++)
			geraRanking << it->second << ' ' << it->first << std::endl;
		geraRanking.close();
		

	}
	void GameOver::cadastraPontuacao() {
		
		std::ifstream pegaPonto("ponto2.dat", std::ios::in);
		if (!pegaPonto)
		{
			printf("nao deu pra pegar a pontuacao");
			exit(1);
		}
		string nomeJ;
		int pont;
		pegaPonto >> nomeJ >> pont;
		if (nomeJ == "jogador2")
		{
			pegaPonto.close();
			salvaPonto(nome.getinfo(), pont);
			Pgrafico->fecha();

		}
		else if(nomeJ=="jogador1")
		{
			salvaPonto(nome.getinfo(), pont);
			nome.setinfo("");
			primeiroCadastro = 0;
			pegaPonto.close();
		}
		else
		{
			std::cout << "houve um erro no cadastro" << std::endl;
			exit(1);
		}
	}
	void GameOver::cadastrasegundaPontuacao()
	{
		printf("oi");
		std::ifstream pegaPonto("ponto2.dat", std::ios::in);
		if (!pegaPonto)
		{
			printf("nao deu pra pegar a pontuacao");
			exit(1);
		}
		string nomeJ;
		int pont;
		pegaPonto >> nomeJ >> pont;
		pegaPonto >> nomeJ >> pont;
		
		salvaPonto(nome.getinfo(), pont);
		pegaPonto.close();
		Pgrafico->fecha();
		
	}
}
