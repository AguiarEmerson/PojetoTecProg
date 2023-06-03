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
	}
	Fase::~Fase()
	{
	}

	void Fase::criaJogador(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador* jogador = 
			new Entidades::Personagens::Jogador(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(3.0, 0.0));
		if (jogador) {
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

	void Fase::criaEspinho(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Espinho* espinho = 
			new Entidades::Obstaculos::Espinho(sf::Vector2f(50.0,50.0),pos);
		if (espinho) {
			lista.incluir(static_cast<Entidade*>(espinho));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma espinho" << std::endl;
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


	void Fase::criaCachorro(sf::Vector2f pos)
	{
		Entidades::Personagens::Cachorro* cachorro = 
			new Entidades::Personagens::Cachorro(sf::Vector2f (50.0,50.0),pos);
		if (cachorro) {
			int i, tam;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "jogador") { 
					cachorro->setjogador(static_cast<Jogador*>(lista.getEnt(i))); }
			}
			lista.incluir(static_cast<Entidade*>(cachorro));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um cachorro" << std::endl;
			exit(1);
		}
	}

	void Fase::criaSapo(sf::Vector2f pos)
	{
		Entidades::Personagens::Sapo* sapo = 
			new Entidades::Personagens::Sapo(sf::Vector2f (50.0,50.0),pos);
		if (sapo) {
			lista.incluir(static_cast<Entidade*>(sapo));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um sapo" << std::endl;
			exit(1);
		}
	}
	
	void Fase::criaMacaco(sf::Vector2f pos)
	{
		Entidades::Personagens::Macaco* macaco = 
			new Entidades::Personagens::Macaco(sf::Vector2f(50.0,50.0),pos);
		if (macaco) {
			lista.incluir(static_cast<Entidade*>(macaco));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um macaco" << std::endl;
			exit(1);
		}
	}

	void Fase::criaEntidade(char id, sf::Vector2i pos)
	{
		sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
		switch (id)
		{
			case('J'):
			{
				criaJogador(posAux);
			}
			break;

			case('#'):
			{
				criaPlataforma(posAux);
			}
			break;

			case('*'):
			{
				criaEspinho(posAux);
			}
			break;

			case('@'):
			{
				criaTrampolim(posAux);
			}
			break;

			case('C'):
			{
				criaCachorro(posAux);
			}
			break;

			case('S'):
			{
				criaSapo(posAux);
			}
			break;

			case('M'):
			{
				criaMacaco(posAux);
			}
			break;
		
		}
	}
	void Fase::Executar()
	{
		//executa todas as entidades
		lista.percorrer();
		
		//verifica as colisoes
		colisoes.executar();
	}

}