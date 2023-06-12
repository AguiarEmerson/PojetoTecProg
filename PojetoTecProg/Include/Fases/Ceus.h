#pragma once
#include "..\Fases\Fase.h"

namespace Fases
{
	class Ceus : public Fase
	{
	protected:
		int j;
		int num_Espinho;
	public:
		Ceus();
		~Ceus();
		void criaCanhao(sf::Vector2f pos);
		void criaEspinho(sf::Vector2f pos);
		void criaEntidade(char id, sf::Vector2i pos);
		void criaMapa(bool p);
		void salva();
		void verificaGanho();
		int getGanho();
		void Executar();
		void salvaPonto();
		void carregaPonto();

	};
}