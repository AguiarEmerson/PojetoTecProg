#pragma once
#include "..\Fases\Fase.h"

namespace Fases
{
	class Fase1 : public Fase
	{
	protected:
		int j;
		int num_Esteira;
	public:
		Fase1();
		~Fase1();

		void criaRoboAnda(sf::Vector2f pos);
		void criaEsteira(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		void criaMapa(bool p);
		void salva();
	};
}