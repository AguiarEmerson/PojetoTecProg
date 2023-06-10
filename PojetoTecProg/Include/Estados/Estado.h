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
		Estado* criaestadojogar_fase1(bool p);
		Estado* criaestadojogar_fase2(bool p);
		Estado* criaestadoMenuPrincipal();
		Estado* criaestadoMenuPausa();
		Estado* CriaestadoGameOver(bool ganhou);
		Estado* criaestadoRanking();
		static Estado* criaestado(string i);
		virtual void Executar() = 0;
		Estado* criarestadoCarregarFase();
		void passaFase1();
		void gameOver(const bool vitoria);
		Estado* criaestadoGameOver(const bool venceu);
	};
}
