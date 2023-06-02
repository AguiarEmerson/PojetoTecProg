#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\cachorro.h"
#include "..\Entidades\Personagens\Sapo.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"

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
		void criarPlataforma(sf::Vector2f pos);
		void criarJogador(sf::Vector2f pos);
		void criarCachorro(sf::Vector2f pos);
		void criarSapo(sf::Vector2f pos);
		void criarEntidade(char id, sf::Vector2f pos);
		virtual void executar() = 0;
	};
}