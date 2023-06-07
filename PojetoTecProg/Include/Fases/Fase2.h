#pragma once
#include "..\Fases\Fase.h"

namespace Fases
{
	class Fase2 : public Fase
	{
	public:
		Fase2();
		~Fase2();
		void criaCanhao(sf::Vector2f pos);
		void criaEspinho(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		void criaMapa();
	};
}