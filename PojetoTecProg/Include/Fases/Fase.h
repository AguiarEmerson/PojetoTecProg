#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\RoboAnda.h"
#include "..\Entidades\Personagens\RoboPula.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"
#include "..\Entidades\Personagens\Jogador1.h"
#include "..\Entidades\Personagens\Jogador2.h"

namespace Fases
{
	class Fase : public Ente
	{
	protected:
		Listas::ListaEntidades lista;
		Gerenciadores::Colisao colisoes;
		sf::RectangleShape fundo;
		sf::Texture textura;
		bool primeiroCiclo;

	public:
		Fase();
		~Fase();
		void criaJogador1(sf::Vector2f pos);
		void criaJogador2(sf::Vector2f pos);
		void criaPlataforma(sf::Vector2f pos);
		void criaEspinho(sf::Vector2f pos);
		void criaTrampolim(sf::Vector2f pos);
		void criaRoboAnda(sf::Vector2f pos);
		void criaRoboPula(sf::Vector2f pos);
		void criaCanhao(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		void criaEsteira(sf::Vector2f pos);
		virtual void criaMapa() = 0;
		void Executar();
		void setFundo(sf::Vector2f posicao);
		sf::RectangleShape getFundo();
	};
}