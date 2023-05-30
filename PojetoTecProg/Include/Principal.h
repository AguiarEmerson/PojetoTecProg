#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Gerenciadores\Grafico.h"

class Principal
{
private:
	static Gerenciadores::Grafico* Pgrafico;
public:
	Principal();
	~Principal();
	void exectutar();
};