#include"..\Gerenciadores\Grafico.h"



namespace Gerenciadores {

	Grafico* gerenciador_grafico = nullptr;

	Grafico* Grafico::getgrafico()
	{
		if (gerenciador_grafico == nullptr) {
			gerenciador_grafico= new Grafico();
		}
		return gerenciador_grafico;
	}

	Grafico::Grafico():
	window(new sf::RenderWindow(sf::VideoMode(TAMW_X, TAMW_Y), "UAAU FUNCIONA", sf::Style::Titlebar | sf::Style::Close)),
	camera(sf::Vector2f(TAMW_X / 2,TAMW_Y  / 2), sf::Vector2f(TAMW_X, TAMW_Y))
	{
		if (window == nullptr) {
			std::cout << "ERROR nao foi possivel criar uma janela grafica" << std::endl;
			exit(1);
		}
	}

	Grafico::~Grafico()
	{
		if (window) {
			delete(window);
			window = nullptr;
		}
	}
	void Grafico::desenha(sf::RectangleShape box)
	{
		window->draw(box);
	}

	const bool Grafico::verificaJanelaAberta() {
		return window->isOpen();
	}

	void Grafico::mostra()
	{
		if (window->isOpen()) {
			window->display();
		}
	}

	void Grafico::limpa()
	{
		if (window->isOpen()) {
			window->clear();
		}
	}

	void Grafico::fecha()
	{
		window->close();
	}


	void Grafico::atualizacam(sf::Vector2f pos)
	{
		camera.setCenter(pos);
		window->setView(camera);
	}

	sf::View Grafico::getcamera() {
		return camera;
	}

	void Grafico::resetarJanela() {
		camera.setCenter(TAMW_X / 2.0f, TAMW_Y / 2.0f);
		window->setView(camera);
	}

	sf::Vector2f Grafico::getTamJanela(){
		return (sf::Vector2f)window->getSize();
	}

	sf::RenderWindow* Grafico::getjanela() {
		return window;
	}

	void Grafico::setLista(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
	}

	void Grafico::executar() {
		int i, tam;
		tam = lista->getTam();
		if (verificaJanelaAberta()) {
			limpa();
			for (i = 0; i < tam; i++) {
				desenha(lista->)
			}




		}
	}
}	