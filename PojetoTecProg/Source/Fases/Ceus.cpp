#include "..\Fases\Ceus.h"

namespace Fases
{
    Ceus::Ceus() :
        Fase()
    {
        textura = Grafico::getgrafico()->carregarTextura("Arquivos/Imagens/fundo2.png");
        fundo.setTexture(&textura);
        num_Espinho = 3 + rand() % 10;
        j = 0;
    }
    Ceus::~Ceus()
    {
    }

    void Ceus::criaMapa(bool p)
    {
        std::ifstream arquivo;
        std::string linha;
        deletaSave();
        if (p) {
            arquivo.open("Arquivos/Fases/Mapa_Ceus_2p.txt");
        }
        else {
            arquivo.open("Arquivos/Fases/Mapa_Ceus_1p.txt");
        }
        if (!arquivo.is_open()) {
            std::cout << "nao foi possivel abrir o arquivo: Mapa_Ceus" << std::endl;
            exit(1);
        }
        unsigned int j = 0;
        while (std::getline(arquivo, linha)) {
            for (unsigned int i = 0; i < linha.size(); i++) {
                if (linha[i] != ' ') {
                    criaEntidade(linha[i], sf::Vector2i(i, j));
                }
            }
            j++;
        }
        arquivo.close();
        colisoes.setLista(&lista);
        Pgrafico->setLista(&lista);
       carregaPonto();
    }
    void Ceus::criaEspinho(sf::Vector2f pos)
    {
        Entidades::Obstaculos::Espinho* espinho =
            new Entidades::Obstaculos::Espinho(sf::Vector2f(50.0, 50.0), pos);
        if (espinho&&j<num_Espinho) {
            lista.incluir(static_cast<Entidade*>(espinho));
            j++;
        }
        else if(!espinho){
            std::cout << "ERROR::nao foi possivel criar uma espinho" << std::endl;
            exit(1);
        }
    }
    void Ceus::criaCanhao(sf::Vector2f pos)
    {
        Entidades::Personagens::Canhao* Canhao =
            new Entidades::Personagens::Canhao(sf::Vector2f(100.0, 100.0), pos);
        if (Canhao) {
            lista.incluir(static_cast<Entidade*>(Canhao->getProjetil()));
            lista.incluir(static_cast<Entidade*>(Canhao));
        }
        else {
            std::cout << "ERROR::nao foi possivel criar um Canhao" << std::endl;
            exit(1);
        }
    }
    void Ceus::criaEntidade(char id, sf::Vector2i pos)
    {
        sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
        switch (id)
        {
        case('J'):
        {
            criarobo(posAux);
        }
        break;

        case('P'):
        {
            criazoiudo(posAux);
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
            criasaltitos(posAux);
        }
        break;

        case('M'):
        {
            criaCanhao(posAux);
        }
        break;

        }
    }
    void Ceus::salva()
    {
        std::ofstream GravadorFase("fase.dat", std::ios::out);

        if (!GravadorFase)
        {
            std::cout << " nao pode salvar fase" << std::endl;
            exit(1);
        }
        GravadorFase << "Ceus" << std::endl;

        int i = 0;
        int tam = lista.getTam();
        
        for (i = 0; i < tam; i++)
        {
            GravadorFase << lista.getEnt(i)->getId() << ' ' << lista.getEnt(i)->salvaEnt() << ' ' << std::endl;
        }
        GravadorFase.close();
    }
    void Ceus::Executar()
    {
        verificaGanho();
        verificaPerdeu();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            pMaquinadeEstados->incluir("Menu_pausa");
        }
        if (primeiroCiclo)
        {
            primeiroCiclo = false;
            Grafico::getgrafico()->setFundo(fundo);
        }
        //desenha o fundo
        Pgrafico->atualizaFundo();
        //executa todas as entidades
        lista.percorrer();
        //desenha todas as entidades
        lista.desenhar();
        //verifica as colisoes
        colisoes.executar();
    }
    void Ceus::verificaGanho()
    {
        Lista<Entidade>::Elemento<Entidade>* aux;
        aux = lista.getPrim();
        int i, tam = lista.getTam();
        ganhoFase = 2;
        for (i = 0; i < tam; i++)
        {
            if (aux->getData()->getId() == "Canhao")
            {
                if (aux->getData()->getVivo() == true) {
                    ganhoFase = 0;
                    
                }
            }
            aux = aux->getProx();
        }
    }
    int Ceus::getGanho()
    {
        return ganhoFase;
    }
    void Ceus::salvaPonto()
    {
        std::ifstream ifs("ponto2.dat");
        if (ifs)
        {
            remove("ponto2.dat");
        }
        std::ofstream gravaPonto("ponto2.dat", std::ios::out);
        if (!gravaPonto)
            exit(1);
        Lista<Entidade>::Elemento<Entidade>* aux;
        aux = lista.getPrim();
        int i, tam = lista.getTam();
        for (i = 0; i < tam; i++)
        {
            if (aux->getData()->getId() == "robo" || aux->getData()->getId() == "zoiudo")
            {

                Jogador* joga = NULL;
                joga = static_cast<Jogador*>(aux->getData());

                gravaPonto << joga->getId() << ' ' << joga->getPonto() << std::endl;
            }
            aux = aux->getProx();
        }
        gravaPonto.close();
    }
    void Ceus::carregaPonto()
    {
        std::ifstream RecuperaPonto("ponto1.dat", std::ios::in);
        if (!RecuperaPonto) {
            return;
        }
        string id;
        int ponto;
        Lista<Entidade>::Elemento<Entidade>* aux;
        aux = lista.getPrim();
        int i, tam = lista.getTam();
        RecuperaPonto >> id >> ponto;
        int t;
        if (id == "zoiudo")
            t = 1;
        else
            t = 2;
        Jogador* joga = NULL;
        if (t == 1)
        {
            for (i = 0; i < tam; i++)
            {
                if (aux->getData()->getId() == "zoiudo") {
                    joga = static_cast<Jogador*>(aux->getData());
                    joga->setPontos(ponto);
                }
                aux = aux->getProx();
            }
        }
        if (t == 2)
        {
            aux = lista.getPrim();
            for (i = 0; i < tam; i++)
            {
                if (aux->getData()->getId() == "zoiudo") {
                    joga = static_cast<Jogador*>(aux->getData());
                    joga->setPontos(ponto);
                }
                aux = aux->getProx();
            }
            RecuperaPonto >> id >> ponto;
            aux = lista.getPrim();
            for (i = 0; i < tam; i++)
            {
                if (aux->getData()->getId() == "robo") {
                    joga = static_cast<Jogador*>(aux->getData());
                    joga->setPontos(ponto);
                }
                aux = aux->getProx();
            }
        }
       
        
        RecuperaPonto.close();


    }
    
}