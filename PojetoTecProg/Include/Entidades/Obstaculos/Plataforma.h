#pragma once
#include "Obstaculo.H"
#include "..\..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma :public Obstaculo
		{
		protected:
			static int num_Plataforma;
			const int num;

		public:
			Plataforma(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(0.0, 0.0));
			Plataforma();
			~Plataforma();
			void colide(Entidade* secundaria, sf::Vector2f ds);
			void Executar();

			string salvaEnt();
			 static Entidade* carregarEnt(string arquivo);
		};
	}
}