#include "..\Fases\Fase.h"

namespace Fases
{
	Fase::Fase() :
		Ente(), lista(), colisoes()
	{
	}
	Fase::~Fase()
	{
	}

	void Fase::criarPlataforma(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma();
		if (plataforma) {
			plataforma->setpos(pos);
			plataforma->setbox(sf::Vector2f(50.0, 50.0));
			plataforma->setvel(sf::Vector2f(0.0, 0.0)); //mudar dps da gravidade
			lista.incluir(static_cast<Entidade*>(plataforma));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma plataforma" << std::endl;
			exit(1);
		}
	}

	void Fase::criarJogador(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador();
		if (jogador) {
			jogador->setpos(pos);
			jogador->setbox(sf::Vector2f(50.0, 50.0));
			jogador->setvel(sf::Vector2f(3.0, 0.0));
			lista.incluir(static_cast<Entidade*>(jogador));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um jogador" << std::endl;
			exit(1);
		}
	}

	void Fase::criarCachorro(sf::Vector2f pos)
	{
		Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro();
		if (cachorro) {
			cachorro->setpos(pos);
			cachorro->setbox(sf::Vector2f(50.0, 50.0));
			cachorro->setvel(sf::Vector2f(1.0, 0.0));
			lista.incluir(static_cast<Entidade*>(cachorro));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um cachorro" << std::endl;
			exit(1);
		}
	}

	void Fase::criarSapo(sf::Vector2f pos)
	{
		Entidades::Personagens::Sapo* sapo = new Entidades::Personagens::Sapo();
		if (sapo) {
			sapo->setpos(pos);
			sapo->setbox(sf::Vector2f(50.0, 50.0));
			sapo->setvel(sf::Vector2f(1.0, 0.0));
			lista.incluir(static_cast<Entidade*>(sapo));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um sapo" << std::endl;
			exit(1);
		}
	}

	void Fase::criarEntidade(char id, sf::Vector2f pos)
	{
		sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
		switch (id)
		{
			case('#'):
			{
				criarPlataforma(posAux);
			}
			break;

			case('j'):
			{
				criarJogador(posAux);
			}
			break;

			case('c'):
			{
				criarCachorro(posAux);
			}
			break;

			case('s'):
			{
				criarSapo(posAux);
			}
			break;
		}
	}

}