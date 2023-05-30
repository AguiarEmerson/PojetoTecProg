#include "..\principal.h"

Gerenciadores::Grafico* Principal::Pgrafico = Gerenciadores::Grafico::getgrafico();

Principal::Principal():
    jogador(),
    plataforma(sf::Vector2f(10000.0, 100.0), sf::Vector2f(-5000.0, 580.0), sf::Vector2f(0.0, 0.0)),
    plataforma2(sf::Vector2f(800.0, 10.0), sf::Vector2f(0.0, 410.0), sf::Vector2f(0.0, 0.0)),
    inimigo(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0))
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }

    lista.incluir(static_cast<Entidade*>(&plataforma));
    lista.incluir(static_cast<Entidade*>(&plataforma2));
    lista.incluir(static_cast<Entidade*>(&jogador));
    lista.incluir(static_cast<Entidade*>(&inimigo));

    colisoes.setLista(&lista);
    Pgrafico->setLista(&lista);

    inimigo.setjogador(&jogador);

    executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
    while (Pgrafico->verificaJanelaAberta()) {
        lista.percorrer();
        Pgrafico->executar();
        colisoes.executar();
    }
}

