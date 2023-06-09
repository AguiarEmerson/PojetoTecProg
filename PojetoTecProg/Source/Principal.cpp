#include "..\AventuraFofa.h"

Gerenciadores::Grafico* AventuraFofa::Pgrafico = Gerenciadores::Grafico::getgrafico();
Gerenciadores::MaquinadeEstados* AventuraFofa::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

AventuraFofa::AventuraFofa()
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
    if (pMaquinadeEstados == nullptr) {
        std::cout << "ERROR nao foi possivel criar a Maquina de estados" << std::endl;
        exit(1);
    }
    inicializa();
}

AventuraFofa::~AventuraFofa()
{
}

void AventuraFofa::inicializa()
{

    pMaquinadeEstados->incluir("Menu_principal");
}

void AventuraFofa::executar()
{
    while (Pgrafico->verificaJanelaAberta()) {
        //limpa a tela
        Pgrafico->limpa();

        //executa o estado no topo da pilha
        pMaquinadeEstados->Executar();

        //desenha as entidades na tela
        Pgrafico->mostra();
    }
}