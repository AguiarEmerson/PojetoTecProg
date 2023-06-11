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
		static Estado* criaestado(string i);

		Estado* criaestadojogar_fase1(bool p);
		Estado* criaestadojogar_fase2(bool p);
		Estado* criarestadoCarregarFase();
		Estado* criaestadoMenuPrincipal();
		Estado* criaestadoMenuPausa();
		Estado* criaestadoRanking();
		Estado* criaestadoGameOver(const bool venceu);

		void passaFase1();
		void gameOver(const bool vitoria);
		virtual void Executar() = 0;
		
	};
}
