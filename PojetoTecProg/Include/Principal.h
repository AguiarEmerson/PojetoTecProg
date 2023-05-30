#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"

using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
using namespace Obstaculos;

class Principal
{
private:
	static Grafico* Pgrafico;
	Colisao colisoes;
	ListaEntidades lista;

	Jogador jogador;
	Plataforma plataforma;
	Plataforma plataforma2;
	Inimigo inimigo;

public:
	Principal();
	~Principal();
	void executar();
};