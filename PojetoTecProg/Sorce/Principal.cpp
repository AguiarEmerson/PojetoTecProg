#include "..\principal.h"

Gerenciadores::Grafico* Ente::Pgrafico = Gerenciadores::Grafico::getgrafico();

Principal::Principal()
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
}

Principal::~Principal()
{
}

void Principal::exectutar()
{
    while (Pgrafico->verificaJanelaAberta()) {
        //limpa janela
        Pgrafico->limpa();

        //mostra tudo na janela
        Pgrafico->mostra();
    }
}
}
