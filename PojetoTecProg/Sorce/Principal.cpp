#include "..\principal.h"

Gerenciadores::Grafico* Principal::Pgrafico = Gerenciadores::Grafico::getgrafico();

Principal::Principal(Fases::Fase* f):
    fase(f)
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }
}

Principal::~Principal()
{
}

void Principal::executar()
{
    fase->criaMapa();
    while (Pgrafico->verificaJanelaAberta()) {
        //atualiza a fase
        fase->Executar();

        //deseha na tela
        Pgrafico->executar();
    }
}

/*
Principal::Principal():
    jogador(),<<<<<<< Emerson
    plataforma(sf::Vector2f(10000.0, 10.0), sf::Vector2f(-5000.0, 500), sf::Vector2f(0.0, 0.0)),
    plataforma2(sf::Vector2f(50.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    cachorro(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    //sapo(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    macaco(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    // trampolim(15.0f,sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    espinho( sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0))

    plataforma(sf::Vector2f(1000.0, 100.0), sf::Vector2f(0.0, 500), sf::Vector2f(0.0, 0.0)),
   cachorro(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
   sapo(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    macaco(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
   //trampolim(15.0f,sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    espinho( sf::Vector2f(50.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }

    lista.incluir(static_cast<Entidade*>(&plataforma));
    lista.incluir(static_cast<Entidade*>(&jogador));
    lista.incluir(static_cast<Entidade*>(&cachorro));<<<<<<< Emerson
    // lista.incluir(static_cast<Entidade*>(&sapo));
    lista.incluir(static_cast<Entidade*>(&macaco));
    lista.incluir(static_cast<Entidade*>(macaco.getProjetil()));
    //lista.incluir(static_cast<Entidade*>(&trampolim));
    lista.incluir(static_cast<Entidade*>(&espinho));

    lista.incluir(static_cast<Entidade*>(&macaco));
  lista.incluir(static_cast<Entidade*>(macaco.getProjetil()));
   lista.incluir(static_cast<Entidade*>(&trampolim));
  lista.incluir(static_cast<Entidade*>(&espinho));

    

    jogador.setVivo(true);

    colisoes.setLista(&lista);
    Pgrafico->setLista(&lista);

    cachorro.setjogador(&jogador);

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

*/