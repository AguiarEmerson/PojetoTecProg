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

		Estado* criaestadojogar_Floresta(bool p);
		Estado* criaestadojogar_Ceus(bool p);
		Estado* criarestadoCarregarFase();
		Estado* criaestadoMenuPrincipal();
		Estado* criaestadoMenuPausa();
		Estado* CriaestadoGameOver(bool ganhou);
		Estado* criaestadoRanking();


		void passaFloresta();
		void gameOver(const bool vitoria);
		virtual void Executar() = 0;
		
	};
}
