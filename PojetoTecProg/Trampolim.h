#pragma once
#include "Include/Entidades/Obstaculos/Obstaculo.h"
#include "Include/Entidades/Entidade.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Trampolim :public Obstaculo
		{
		protected:
			float dt;
			bool podePular;
			float velocidade;
		public:
			Trampolim(float velocidades,sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Trampolim();
			~Trampolim();

			void colide(Entidade* secundaria, sf::Vector2f ds);
			void Executar();
			void jogadorPula(Entidade* joga);

			const bool getPodePular();

		};

	}
}