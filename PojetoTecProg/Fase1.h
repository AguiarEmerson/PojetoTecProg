#pragma once
#include"..\Fases\Fase.h"

namespace Fases
{
	class Fase1 :public Fase
	{
	public:
		Fase1();
		~Fase1();
		void criarmapa();
		void executar();
	};
}