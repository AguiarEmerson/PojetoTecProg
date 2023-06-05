#pragma once
#include"stdafx.h"

//#include"..\Gerenciadores\Grafico.h"
namespace Gerenciadores {
	class Grafico;
}

class Ente
{
protected:
	static Gerenciadores::Grafico* Pgrafico;
	string id;

public:
	Ente();
	~Ente();
	
	const string getId();
	virtual void Executar() = 0;
};