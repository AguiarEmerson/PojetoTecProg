#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\Cachorro.h"
#include "..\Entidades\Personagens\Sapo.h"
#include "..\Entidades\Personagens\Macaco.h"
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
	Cachorro cachorro;
	Sapo sapo;
	Macaco macaco;
	Trampolim trampolim;

public:
	Principal();
	~Principal();
	void executar();
};