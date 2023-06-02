#include "..\Ente.h"
#include"..\Gerenciadores\Grafico.h"


Gerenciadores::Grafico* Ente::Pgrafico = Gerenciadores::Grafico::getgrafico();

Ente::Ente()
{
}

Ente::~Ente()
{
}

string Ente::getId()
{
	return id;
}