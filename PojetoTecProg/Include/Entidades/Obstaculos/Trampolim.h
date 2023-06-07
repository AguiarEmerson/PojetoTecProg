#pragma once
#include "../Obstaculos/Obstaculo.h"
#include "../Entidades/Entidade.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Trampolim :public Obstaculo
		{
		protected:
			float dt;
			float tempo_total;
			bool primeiro_ciclo;
			bool podePular;
			float velocidade;
			static int num_Trampolim;
			const int num;
		public:
			Trampolim(float velocidades,sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Trampolim();
			~Trampolim();

			void colide(Entidade* secundaria, sf::Vector2f ds);
			void Executar();
			void jogadorPula(Entidade* joga);

			const bool getPodePular();
			void setPodePular(const bool pula);

			void primTempoTotal();

			char* salvaEnt();
			static Entidade* carregarEnt(char* arquivo);

		};

	}
}