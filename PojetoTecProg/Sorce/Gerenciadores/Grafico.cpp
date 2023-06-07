#include"..\Gerenciadores\Grafico.h"

namespace Gerenciadores {

	Grafico* Grafico::gerenciador_grafico = nullptr;

	Grafico* Grafico::getgrafico()
	{
		if (gerenciador_grafico == nullptr) {
			gerenciador_grafico= new Grafico();
		}
		return gerenciador_grafico;
	}

	Grafico::Grafico():
	lista(nullptr),
	window(new sf::RenderWindow(sf::VideoMode((unsigned int)TAMW_X, (unsigned int)TAMW_Y), "UAAU FUNCIONA", sf::Style::Titlebar | sf::Style::Close)),
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
	void Grafico:: desenha(sf::RectangleShape box)
	{
		window->draw(box);
		 
	}

	void Grafico::desenha(sf::Text tex)
	{
		window->draw(tex);
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

	sf::Clock Grafico::getrelogio()
	{
		return relogio;
	}

	void Grafico::setLista(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
	}

	void Grafico::executar() {
		int i, tam;
		tam = lista->getTam();
		atualizaFundo();
		if (verificaJanelaAberta()) {
			sf::Event evento;
			if (window->pollEvent(evento)) {
				if (evento.type == sf::Event::Closed) {
					fecha();
				}
			}
			limpa();
			desenha(fundo);
			for (i = 0; i < tam; i++) {
				if (lista->getEnt(i)->getVivo() == true) {
					desenha(lista->getEnt(i)->getbox());
				}
			}
			mostra();
			window->setFramerateLimit(60);
		}
	}
	//essa função retorn

	sf::Font Grafico::carregarFonte(const char* caminhoFonte) {

		sf::Font fonte;
		if (!fonte.loadFromFile(caminhoFonte)) {
			std::cout << "ERRO nao foi possivel encontrar o caminho da Fonte - " << caminhoFonte << std::endl;
			exit(1);
		}
		return fonte;
	}
	
	sf::Texture Grafico::carregarTextura(const char* caminhoTextura) {

		sf::Texture textura;
		if (!textura.loadFromFile(caminhoTextura)) {
			std::cout << "ERRO::Jungle::Gerenciador::GerenciadorGrafico::nao foi possivel encontrar o caminho da textura - " << caminhoTextura << std::endl;
			exit(1);
		}
		return textura;
	}
	sf::Texture Grafico::mandaTextura(const char* caminhoTextura)
	{
		sf::Texture textura;
		std::map<const char*, sf::Texture>::iterator it = mapatexturas.begin();
		while (it != mapatexturas.end())
		{
			if (it->first == caminhoTextura)
			{
				return it->second;
			}
			it++;
		}
		return carregarTextura(caminhoTextura);
	}
	void Grafico::setFundo(sf::RectangleShape box) {
		fundo = box;
	}
	void Grafico::atualizaFundo()
	{
		fundo.setPosition(camera.getCenter() - sf::Vector2f((camera.getSize().x / 2), (camera.getSize().y / 2)));
	}
}	


