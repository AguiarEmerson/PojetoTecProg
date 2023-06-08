#include "..\Menus\Menu.h"

namespace Menus
{
	Gerenciadores::Grafico* Menu::Pgrafico = Gerenciadores::Grafico::getgrafico();
	Gerenciadores::MaquinadeEstados* Menu::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

	Menu::Menu(const string nome, sf::Vector2f tambotao, const int tamfonte):
		nomeMenu(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"),nome,tamfonte),
		listabotao(), it(),tambotao(tambotao),tamjanela(Pgrafico->getTamJanela())
	{
	}

	Menu::~Menu()
	{
		if (!listabotao.empty()) {
			for (it = listabotao.begin(); it != listabotao.end(); it++) {
				delete(*it);
				*it = nullptr;
			}
			listabotao.clear();
		}
	}

	void Menu::incluibotao(const std::string info, const sf::Vector2f pos)
	{
		Botao* botao = new Botao(info, tambotao, pos);
		if (botao)
		{
			listabotao.push_back(botao);
		}
		else
		{
			std::cout << "ERROR nao foi possivel criar uma janela grafica" << std::endl;
			exit(1);
		}
	}

	void Menu::selecionacima() {
		Botao* botao = *it;
		botao->seleciona(false);
		if (it == listabotao.begin()) {
			it = listabotao.end();
		}
		it--;
		botao = *it;
		botao->seleciona(true);
	}

	void Menu::selecionabaixo() {
		Botao* botao = *it;
		botao->seleciona(false);
		it++;
		if (it == listabotao.end()) {
			it = listabotao.begin();
		}
		botao = *it;
		botao->seleciona(true);
	}

	Botao* Menu::getbotaoselecionado()
	{
		return *it;
	}
	
	void Menu::desenha()
	{
		std::list<Botao*>::iterator aux;
		for (aux = listabotao.begin(); aux != listabotao.end(); aux++)
		{
			Botao* botao = *aux;
			botao->desenha();
			botao = nullptr;
		}
	}

	void Menu::controlar()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			selecionacima();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			selecionabaixo();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			selecionar(getbotaoselecionado());
		}
	}
}