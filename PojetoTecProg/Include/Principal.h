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