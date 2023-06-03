#pragma once
#include "..\Fases\Fase.h"


class Principal
{
private:
	static Gerenciadores::Grafico* Pgrafico;
	Fases::Fase* fase;
public:
	Principal(Fases::Fase* f);
	~Principal();
	void executar();
};
/*
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\Cachorro.h"
#include "..\Entidades\Personagens\Sapo.h"
#include "..\Entidades\Personagens\Macaco.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"
#include "..\Entidades\Obstaculos\Espinho.h"


using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
using namespace Obstaculos;
*/