#pragma once
#include "..\Ente.h"
#include "..\Fases\Fase1.h"
#include "..\Fases\Fase2.h"

namespace Estados
{
	class Estado : public Ente
	{
	public:
		Estado();
		~Estado();
		Estado* criaestadojogar_fase1();
		Estado* criaestadojogar_fase2();
		static Estado* criaestado(string i);
		virtual void Executar() = 0;
	};
}
