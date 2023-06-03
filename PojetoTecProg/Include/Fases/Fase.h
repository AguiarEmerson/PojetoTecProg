#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\cachorro.h"
#include "..\Entidades\Personagens\Sapo.h"
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

	public:
		Fase();
		~Fase();
		void criaJogador1(sf::Vector2f pos);
		void criaJogador2(sf::Vector2f pos);
		void criaPlataforma(sf::Vector2f pos);
		void criaEspinho(sf::Vector2f pos);
		void criaTrampolim(sf::Vector2f pos);
		void criaCachorro(sf::Vector2f pos);
		void criaSapo(sf::Vector2f pos);
		void criaMacaco(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		virtual void criaMapa() = 0;
		void Executar();
	};
}