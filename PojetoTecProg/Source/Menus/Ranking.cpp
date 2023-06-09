#include "..\..\Include\Menus\Ranking.h"
namespace Menus
{
	Gerenciadores::Grafico* Ranking::Pgrafico = Gerenciadores::Grafico::getgrafico();
	Ranking::Ranking() :
	Estado(),
	botao("voltar", sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y),sf::Vector2f(100.0,100.0))
	{
		criaNumero();
		criaNomes();
	}
	Ranking::~Ranking()
	{
		textos.clear();
	}
	void Ranking::selecionar(Botao* botao)
	{
		if (botao->getinfo() == "voltar")
			pMaquinadeEstados->remove();
	}
	void Ranking::controlar()
	{
		botao.seleciona(true);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			selecionar(&botao);
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
		std::list<Texto*>::iterator it;
		for (it = textos.begin(); it != textos.end(); it++) {
			Texto* aux;
			aux = *it;
			Pgrafico->desenha(aux->getTexto());
		}
	}
	void Ranking::criaNumero()
	{
		int i;
		for (i = 1; i < 6; i++)
		{
			Texto* aux = new Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), std::to_string(i));
			aux->setPos(sf::Vector2f(60.0f, (100.0f + 75.0f * i)));
			textos.push_back(aux);
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
			Texto* aux = new Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), nome);
			aux->setPos(sf::Vector2f(90.0f, (100.0f + 75.0f * i)));
			Texto* aux2 = new Texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"), ponto);
			aux2->setPos(sf::Vector2f(700.0f, (100.0f + 75.0f * i)));
			textos.push_back(aux);
			textos.push_back(aux2);
		}
		pegaRanking.close();
	}

}