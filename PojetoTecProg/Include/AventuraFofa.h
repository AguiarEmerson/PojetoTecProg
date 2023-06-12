#pragma once
#include "..\Gerenciadores\Grafico.h"
#include "..\Gerenciadores\MaquinadeEstados.h"

class AventuraFofa
{
private:
	static Gerenciadores::Grafico* Pgrafico;
	static Gerenciadores::MaquinadeEstados* pMaquinadeEstados;
	void inicializa();
public:
	AventuraFofa();
	~AventuraFofa();
	void executar();
};