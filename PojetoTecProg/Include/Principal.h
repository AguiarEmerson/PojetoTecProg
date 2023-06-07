#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\MaquinadeEstados.h"

class Principal
{
private:
	static Gerenciadores::Grafico* Pgrafico;
	static Gerenciadores::MaquinadeEstados* pMaquinadeEstados;
	void inicializa();
public:
	Principal();
	~Principal();
	void executar();
};
/*
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\RoboAnda.h"
#include "..\Entidades\Personagens\RoboPula.h"
#include "..\Entidades\Personagens\Canhao.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"
#include "..\Entidades\Obstaculos\Espinho.h"


using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
using namespace Obstaculos;
*/