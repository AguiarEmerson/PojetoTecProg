#include "..\Gerenciadores\MaquinadeEstados.h"

namespace Gerenciadores
{
	MaquinadeEstados* MaquinadeEstados::pMaquinadeEstados = NULL;

	MaquinadeEstados* MaquinadeEstados::getMaquinadeEstados() 
	{
		if (pMaquinadeEstados == NULL) {
			pMaquinadeEstados = new MaquinadeEstados();
		}
		return pMaquinadeEstados;
	}
	MaquinadeEstados::MaquinadeEstados() :
		PilhadeEstados()
	{
	}
	MaquinadeEstados::~MaquinadeEstados() 
	{
		while (!PilhadeEstados.empty()) {
			delete(PilhadeEstados.top());
			PilhadeEstados.top() = nullptr;
			PilhadeEstados.pop();
		}
	}

	void MaquinadeEstados::incluir(string i)
	{
		Estados::Estado* estado = Estados::Estado::criaestado(i);
		if (estado) {
			PilhadeEstados.push(estado);
		}
		else {
			std::cout << "ERROR nao foi possivel incluir um estado na pilha" << std::endl;
			exit(1);
		}
	}
	void MaquinadeEstados::remove()
	{
		if (PilhadeEstados.top() != nullptr) {
			delete(PilhadeEstados.top());
			PilhadeEstados.top() = nullptr;
			PilhadeEstados.pop();
		}
		else {
			Grafico* Pgrafico = Pgrafico->getgrafico();
			Pgrafico->fecha();
		}
	}
	Estados::Estado* MaquinadeEstados::getestadoAT()
	{
		return PilhadeEstados.top();
	}
	void MaquinadeEstados::Executar()
	{
		if (!PilhadeEstados.empty()) {
			PilhadeEstados.top()->Executar();
		}
	}
}