#include "..\..\Include\Estados\Ranking.h"

namespace Estados
{
	Gerenciadores::Grafico* Ranking::Pgrafico = Gerenciadores::Grafico::getgrafico();
	Ranking::Ranking() :
	Estado(),
	botao("voltar", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),sf::Vector2f(100.0,100.0))
	{
		criaNumero();
		criaNomes();
		tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
	}
	Ranking::~Ranking()
	{
		textos.clear();
	}
	void Ranking::selecionar(Menus::Botao* botao)
	{
		if (botao->getinfo() == "voltar")
			pMaquinadeEstados->remove();
	}

	void Ranking::controlar()
	{
		botao.seleciona(true);
		if (Pgrafico->getrelogio().getElapsedTime().asSeconds() > tempo_total + 2.0f) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				selecionar(&botao);
			}
		}
	}
	void Ranking::Executar()
	{
		Pgrafico->resetarJanela();
		desenha();
		controlar();
	}
	void Ranking::desenha() {
		botao.desenha();
		std::list<Menus::Texto*>::iterator it;
		for (it = textos.begin(); it != textos.end(); it++) {
			Menus::Texto* aux;
			aux = *it;
			Pgrafico->desenha(aux->getTexto());
		}
	}
	void Ranking::criaNumero()
	{
		int i;
		int j;
		j = 5;
		for (i = 1; i < 6; i++)
		{

			Menus::Texto* aux = new Menus::Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), std::to_string(j));
			aux->setPos(sf::Vector2f(60.0f, (100.0f + 75.0f * i)));
			textos.push_back(aux);
			j--;
		}
	}
	void Ranking::criaNomes()
	{
		std::ifstream pegaRanking("ranking.dat", std::ios::in);
		if (!pegaRanking)
		{
			std::cout << "nao foi possivel abrir o ranking" << std::endl;
			exit(1);
		}
		int i;
		string nome;
		string ponto;
		for (i = 1; i < 6; i++)
		{
			pegaRanking >> nome >> ponto;
			Menus::Texto* aux = new Menus::Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), nome);
			aux->setPos(sf::Vector2f(90.0f, (100.0f + 75.0f * i)));
			Menus::Texto* aux2 = new Menus::Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), ponto);
			aux2->setPos(sf::Vector2f(700.0f, (100.0f + 75.0f * i)));
			textos.push_back(aux);
			textos.push_back(aux2);
		}
		pegaRanking.close();
	}

}