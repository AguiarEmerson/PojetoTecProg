#pragma once
#include "..\stdafx.h"

namespace Gerenciadores
{
	class MaquinadeEstados;
}

namespace Estados
{
	class Estado
	{
	protected:
		static Gerenciadores::MaquinadeEstados* pMaquinadeEstados;
	public:
		Estado();
		~Estado();
		Estado* criaestadojogar_fase1();
		Estado* criaestadojogar_fase2();
		Estado* criaestadoMenuPrincipal();
		Estado* criaestadoMenuPausa();
		static Estado* criaestado(string i);
		virtual void Executar() = 0;
		Estado* criarestadoCarregarFase();
	};
}
