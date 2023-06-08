#pragma once
#include "..\Fases\Fase.h"

namespace Fases
{
	class Fase1 : public Fase
	{
	public:
		Fase1();
		~Fase1();

		void criaRoboAnda(sf::Vector2f pos);
		void criaEsteira(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		void criaMapa();
		void salva();
	};
}