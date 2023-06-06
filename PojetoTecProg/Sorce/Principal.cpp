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
    pMaquinadeEstados->incluir("jogar_fase1");
}

void Principal::executar()
{
    while (Pgrafico->verificaJanelaAberta()) {
        //atualiza a fase
        pMaquinadeEstados->Executar();

        //deseha na tela
        Pgrafico->executar();
    }
}

/*
Principal::Principal():
    jogador(),<<<<<<< Emerson
    plataforma(sf::Vector2f(10000.0, 10.0), sf::Vector2f(-5000.0, 500), sf::Vector2f(0.0, 0.0)),
    plataforma2(sf::Vector2f(50.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    RoboAnda(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    //RoboPula(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    Canhao(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    // trampolim(15.0f,sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    espinho( sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0))

    plataforma(sf::Vector2f(1000.0, 100.0), sf::Vector2f(0.0, 500), sf::Vector2f(0.0, 0.0)),
   RoboAnda(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
   RoboPula(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
    Canhao(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0)),
   //trampolim(15.0f,sf::Vector2f(200.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0)),
    espinho( sf::Vector2f(50.0, 50.0), sf::Vector2f(0.0, 320.0), sf::Vector2f(0.0, 0.0
{
    if (Pgrafico == nullptr) {
        std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
        exit(1);
    }

    lista.incluir(static_cast<Entidade*>(&plataforma));
    lista.incluir(static_cast<Entidade*>(&jogador));
    lista.incluir(static_cast<Entidade*>(&RoboAnda));<<<<<<< Emerson
    // lista.incluir(static_cast<Entidade*>(&RoboPula));
    lista.incluir(static_cast<Entidade*>(&Canhao));
    lista.incluir(static_cast<Entidade*>(Canhao.getProjetil()));
    //lista.incluir(static_cast<Entidade*>(&trampolim));
    lista.incluir(static_cast<Entidade*>(&espinho));

    lista.incluir(static_cast<Entidade*>(&Canhao));
  lista.incluir(static_cast<Entidade*>(Canhao.getProjetil()));
   lista.incluir(static_cast<Entidade*>(&trampolim));
  lista.incluir(static_cast<Entidade*>(&espinho));

    

    jogador.setVivo(true);

    colisoes.setLista(&lista);
    Pgrafico->setLista(&lista);

    RoboAnda.setjogador(&jogador);

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