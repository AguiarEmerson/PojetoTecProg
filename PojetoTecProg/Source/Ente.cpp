#include "..\Ente.h"
#include"..\Gerenciadores\Grafico.h"


Gerenciadores::Grafico* Ente::Pgrafico = Gerenciadores::Grafico::getgrafico();

Ente::Ente()
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
}

Ente::~Ente()
{
}

const string Ente::getId()
{
	return id;
}