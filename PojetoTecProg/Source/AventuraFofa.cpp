#include "..\principal.h"

Gerenciadores::Grafico* Principal::Pgrafico = Gerenciadores::Grafico::getgrafico();
Gerenciadores::MaquinadeEstados* Principal::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

Principal::Principal()
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

Principal::~Principal()
{
}

void Principal::inicializa() 
{

    pMaquinadeEstados->incluir("Menu_principal");
}

void Principal::executar()
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