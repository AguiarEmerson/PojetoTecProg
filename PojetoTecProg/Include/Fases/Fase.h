#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\andomelo.h"
#include "..\Entidades\Personagens\saltitos.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"
#include "..\Entidades\Personagens\robo.h"
#include "..\Entidades\Personagens\zoiudo.h"
#include "..\Gerenciadores\MaquinadeEstados.h"

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
		static Gerenciadores::MaquinadeEstados* pMaquinadeEstados;
		int i;
		int num_saltitos;
		int ganhoFase;
		bool perdeu;
	
	public:
		Fase();
		~Fase();
		void criarobo(sf::Vector2f pos);
		void criazoiudo(sf::Vector2f pos);
		void criaPlataforma(sf::Vector2f pos);
		void criaTrampolim(sf::Vector2f pos);
		void criasaltitos(sf::Vector2f pos);
		virtual void criaEntidade(char id, sf::Vector2i pos)=0;
		virtual void criaMapa(bool p ) = 0;
		virtual void Executar()=0;
		void setFundo(sf::Vector2f posicao);
		sf::RectangleShape getFundo();
		int getTam();
		string salvaEnt(int i);
		string getId(int i);
		virtual void salva()=0;
		void deletaSave();
		void carregaSave();
		virtual void verificaGanho()=0;
		virtual int getGanho()=0;
		virtual void salvaPonto()=0;
		void verificaPerdeu();
		const bool getPerdeu();
	};
}