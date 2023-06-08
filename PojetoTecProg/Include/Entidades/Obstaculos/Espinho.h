#pragma once
#include "Obstaculo.h"
#include "..\Personagens\Personagem.h"

namespace Entidades
{
	using namespace Personagens;
	namespace Obstaculos
	{
		class Espinho:public Obstaculo
		{
		protected:
			float dt;
			float tempo_total;
			bool primeiro_ciclo;
			int dano;
			static int num_Espinhos;
			const int num;
		public:
			Espinho(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Espinho();
			~Espinho();
			void Executar();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void danoPersonagem(Personagem* personagem);

			void primTempoTotal();

			string salvaEnt();

			static Entidade* carregarEnt(string arquivo);

			void setDano(int dan);
		};
	}
}

