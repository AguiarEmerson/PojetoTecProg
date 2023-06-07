#include "..\Fases\Fase.h"


namespace Fases
{
	Fase::Fase() :
		Ente(), lista()
	{
		if (Pgrafico == nullptr) {
			std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
			exit(1);
		}
		fundo = sf::RectangleShape(sf::Vector2f(1000.0f, 600.0f));
		primeiroCiclo = true;
		
	}
	Fase::~Fase()
	{
	}

	

	void Fase::criaJogador1(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador* jogador = 
			new Entidades::Personagens::Jogador1(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(3.0, 0.0));
		if (jogador) {
			int i, tam;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "jogador") {
					std::cout << "nao foi possivel gerar a fase pois o jogador 2 esta depois do 1" << std::endl;
					exit(1);
				}
			}
			lista.incluir(static_cast<Entidade*>(jogador));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um jogador" << std::endl;
			exit(1);
		}
	}
	void Fase::criaJogador2(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador2* jogador =
			new Entidades::Personagens::Jogador2(sf::Vector2f(50.0, 50.0), pos, sf::Vector2f(3.0, 0.0));
		if (jogador) {
			int i, tam;
			bool achoJogador = false;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "jogador") {
					achoJogador = 1;
					jogador->setJogador(static_cast<Jogador1*>(lista.getEnt(i)));
				}
			}
			if (achoJogador == false)
			{
				jogador->setJogador(NULL);
			}
			lista.incluir(static_cast<Entidade*>(jogador));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um jogador" << std::endl;
			exit(1);
		}
	}

	void Fase::criaPlataforma(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Plataforma* plataforma =
			new Entidades::Obstaculos::Plataforma(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(0.0,0.0));
		if (plataforma) {
			lista.incluir(static_cast<Entidade*>(plataforma));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma plataforma" << std::endl;
			exit(1);
		}
	}

	void Fase::criaTrampolim(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Trampolim* trampolim =
			new Entidades::Obstaculos::Trampolim(20.0, sf::Vector2f(50.0,50.0),pos);
		if (trampolim) {
			lista.incluir(static_cast<Entidade*>(trampolim));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma trampolim" << std::endl;
			exit(1);
		}
	}

	void Fase::criaRoboPula(sf::Vector2f pos)
	{
		Entidades::Personagens::RoboPula* RoboPula = 
			new Entidades::Personagens::RoboPula(sf::Vector2f (50.0,50.0),pos);
		if (RoboPula) {
			lista.incluir(static_cast<Entidade*>(RoboPula));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um RoboPula" << std::endl;
			exit(1);
		}
	}
	void Fase::Executar()
	{
		if (primeiroCiclo)
		{
			primeiroCiclo = false;
			Grafico::getgrafico()->setFundo(fundo);
		}
		//desenha o fundo
		Pgrafico->atualizaFundo();
		//executa todas as entidades
		lista.percorrer();
		//desenha todas as entidades
		lista.desenhar();
		
		//verifica as colisoes
		colisoes.executar();
	}
	void Fase::setFundo(sf::Vector2f posicao)
	{
		fundo.setPosition(posicao);
	}
	sf::RectangleShape Fase::getFundo()
	{
		return fundo;
	}

}