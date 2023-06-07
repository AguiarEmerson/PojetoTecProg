#pragma once
#include "..\Fases\Fase1.h"
#include "..\Fases\Fase2.h"
#include "..\stdafx.h"

namespace Estados
{
	class Estado
	{
	public:
		Estado();
		~Estado();
		Estado* criaestadojogar_fase1();
		Estado* criaestadojogar_fase2();
		Estado* criaestadoMenuPrincipal();
		static Estado* criaestado(string i);
		virtual void Executar() = 0;
	};
}
