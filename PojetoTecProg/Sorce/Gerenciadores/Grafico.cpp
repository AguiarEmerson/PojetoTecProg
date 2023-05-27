#include"..\Gerenciadores\Grafico.h"



namespace Gerenciadores {

	Grafico* gerenciador_grafico = nullptr;

	Grafico* Grafico::getgrafico()
	{
		if (gerenciador_grafico == nullptr) {
			Grafico();
		}
		return gerenciador_grafico;
	}

	Grafico::Grafico():
	window(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "UAAU FUNCIONA", sf::Style::Titlebar | sf::Style::Close)),
	cam(sf::Vector2f(LARGURA / 2, ALTURA / 2), sf::Vector2f(LARGURA, ALTURA))
	{
	}

	Grafico::~Grafico()
	{
		gerenciador_grafico = nullptr;
	}
	void Grafico::Render(sf::RectangleShape box)
	{
		window->draw(box);
	}

	void Grafico::display()
	{
		if (window->isOpen()) {
			window->display();
		}
	}

	void Grafico::clear()
	{
		if (window->isOpen()) {
			window->clear();
		}
	}

	void Grafico::close()
	{
		window->close();
	}

	void Grafico::setPjogador(Entidades::Personagens::Jogador* p)
	{
		Pjogador = p;
	}

	void Grafico::alinhacam()
	{
		cam.setCenter(sf::Vector2f(Pjogador->getpos().x, Pjogador->getpos().y));
		window->setView(cam);
	}

	sf::RenderWindow* Grafico::getwindow() {
		return window;
	}
}