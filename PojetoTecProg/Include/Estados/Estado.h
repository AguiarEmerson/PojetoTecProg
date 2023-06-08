#pragma once
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
		Estado* criaestadoMenuPausa();
		static Estado* criaestado(string i);
		virtual void Executar() = 0;
	};
}
