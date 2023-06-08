#include "..\Fases\Fase2.h"

namespace Fases
{
    Fase2::Fase2() :
        Fase()
    {
    }
    Fase2::~Fase2()
    {
    }

    void Fase2::criaMapa()
    {
        std::ifstream arquivo;
        std::string linha;
        deletaSave();
        arquivo.open("Arquivos/Fases/Mapa_fase2.txt");
        if (!arquivo.is_open()) {
            std::cout << "nao foi possivel abrir o arquivo: Mapa_fase2" << std::endl;
            exit(1);
        }
        int j = 0;
        while (std::getline(arquivo, linha)) {
            for (int i = 0; i < linha.size(); i++) {
                if (linha[i] != ' ') {
                    criaEntidade(linha[i], sf::Vector2i(i, j));
                }
            }
            j++;
        }
        arquivo.close();
        colisoes.setLista(&lista);
        Pgrafico->setLista(&lista);
    }
    void Fase2::criaEspinho(sf::Vector2f pos)
    {
        Entidades::Obstaculos::Espinho* espinho =
            new Entidades::Obstaculos::Espinho(sf::Vector2f(50.0, 50.0), pos);
        printf("%d,%d\n",j,num_Obstaculo);
        if (espinho&&j<num_Obstaculo) {
            lista.incluir(static_cast<Entidade*>(espinho));
            j++;
        }
        else if(!espinho){
            std::cout << "ERROR::nao foi possivel criar uma espinho" << std::endl;
            exit(1);
        }
    }
    void Fase2::criaCanhao(sf::Vector2f pos)
    {
        Entidades::Personagens::Canhao* Canhao =
            new Entidades::Personagens::Canhao(sf::Vector2f(50.0, 50.0), pos);
        if (Canhao) {
            lista.incluir(static_cast<Entidade*>(Canhao));
            lista.incluir(static_cast<Entidade*>(Canhao->getProjetil()));
        }
        else {
            std::cout << "ERROR::nao foi possivel criar um Canhao" << std::endl;
            exit(1);
        }
    }
    void Fase2::criaEntidade(char id, sf::Vector2i pos)
    {
        sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
        switch (id)
        {
        case('J'):
        {
            criaJogador1(posAux);
        }
        break;

        case('P'):
        {
            criaJogador2(posAux);
        }
        break;

        case('#'):
        {
            criaPlataforma(posAux);
        }
        break;

        case('*'):
        {
            criaEspinho(posAux);
        }
        break;

        case('@'):
        {
            criaTrampolim(posAux);
        }
        break;

        case('S'):
        {
            criaRoboPula(posAux);
        }
        break;

        case('M'):
        {
            criaCanhao(posAux);
        }
        break;

        }
    }
    void Fase2::salva()
    {
        std::ofstream GravadorFase("fase.dat", std::ios::out);

        if (!GravadorFase)
        {
            std::cout << " nao pode salvar fase" << std::endl;
            exit(1);
        }
        GravadorFase << "Fase2" << std::endl;

        int i = 0;
        int tam = lista.getTam();
        
        for (i = 0; i < tam; i++)
        {
            GravadorFase << lista.getEnt(i)->getId() << ' ' << lista.getEnt(i)->salvaEnt() << ' ' << std::endl;
        }
        GravadorFase.close();
    }
}