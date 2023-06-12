    #include "..\Fases\Floresta.h"
using namespace Listas;

namespace Fases
{
	Floresta::Floresta() :
		Fase()
	{
        textura = Grafico::getgrafico()->carregarTextura("Arquivos/Imagens/fundo1.png");
        fundo.setTexture(&textura);
        num_Esteira = 2 + rand() % 6;
        j = 0;
	}
	Floresta::~Floresta()
	{
	}

	void Floresta::criaMapa(bool p)
	{
        std::ifstream arquivo;
        std::string linha;
        deletaSave();
        if (p) {
            arquivo.open("Arquivos/Fases/Mapa_Floresta_2p.txt");
        }
        else {
            arquivo.open("Arquivos/Fases/Mapa_Floresta_1p.txt");
        }
        if (!arquivo.is_open()) {
            std::cout << "nao foi possivel abrir o arquivo: Mapa_Floresta" << std::endl;
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
    void Floresta::criaEsteira(sf::Vector2f pos)
    {
        Entidades::Obstaculos::Esteira* Esteira =
            new Entidades::Obstaculos::Esteira(sf::Vector2f(50.0, 50.0), pos, sf::Vector2f(0.0, 0.0));
        if (Esteira&&j<num_Esteira) {
            lista.incluir(static_cast<Entidade*>(Esteira));
            j++;
        }
        else if(!Esteira) {
            std::cout << "ERROR::nao foi possivel criar uma Esteira" << std::endl;
            exit(1);
        }
    }
    void Floresta::criaandomelo(sf::Vector2f pos)
    {
        Entidades::Personagens::andomelo* andomelo =
            new Entidades::Personagens::andomelo(sf::Vector2f(50.0, 50.0), pos);
        if (andomelo) {
            int i, tam;
            tam = lista.getTam();
            for (i = 0; i < tam; i++) {
                if (lista.getEnt(i)->getId() == "jogador1"|| lista.getEnt(i)->getId() == "jogador2") {
                    andomelo->setjogador(static_cast<Jogador*>(lista.getEnt(i)));
                }
            }
            lista.incluir(static_cast<Entidade*>(andomelo));
        }
        else {
            std::cout << "ERROR::nao foi possivel criar um andomelo" << std::endl;
            exit(1);
        }
    }
	void Floresta::criaEntidade(char id, sf::Vector2i pos)
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

		case('@'):
		{
			criaTrampolim(posAux);
		}
		break;

		case('C'):
		{
			criaandomelo(posAux);
		}
		break;

		case('S'):
		{
			criasaltitos(posAux);
		}
		break;

		case('%'):
		{
			criaEsteira(posAux);
		}
		break;

		}
	}
    void Floresta::salva()
    {
        std::ofstream GravadorFase("fase.dat", std::ios::out);
        
            if (!GravadorFase)
            {
                std::cout <<" nao pode salvar fase" << std::endl;
                exit(1);
            }
            GravadorFase << "Floresta" << std::endl;

            int i = 0;
            int tam = getTam();
            for (i = 0; i < tam; i++)
            {
                GravadorFase <<getId(i)<< ' '<<salvaEnt(i)<< ' ' << std::endl;
            }
            GravadorFase.close();
    }
    void Floresta::Executar()
    {
        //verifica se a fase foi vencida
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
    void Floresta::verificaGanho() {
        Lista<Entidade>::Elemento<Entidade>* aux;
        aux = lista.getPrim();
        int i, tam = lista.getTam();
        ganhoFase = 1;
        for (i = 0; i < tam; i++)
        {
            if (aux->getData()->getId() == "jogador1"||aux->getData()->getId()=="jogador2")
            {
                Jogador* joga = NULL;
                joga = static_cast<Jogador*>(aux->getData());
                if (joga->getGanhou() == false)
                    ganhoFase = 0;
            }
            aux = aux->getProx();
        }

    }
    int Floresta::getGanho()
    {
        return ganhoFase;
    }
    void Floresta::salvaPonto()
    {
        std::ifstream ifs("ponto1.dat");
        if (ifs)
        {
            remove("ponto1.dat");
        }
        std::ofstream gravaPonto("ponto1.dat", std::ios::out);
        if (!gravaPonto)
            exit(1);
        Lista<Entidade>::Elemento<Entidade>* aux;
        aux = lista.getPrim();
        int i, tam = lista.getTam();
        for (i = 0; i < tam; i++)
        {
            if (aux->getData()->getId() == "jogador1" || aux->getData()->getId() == "jogador2")
            {

                Jogador* joga = NULL;
                joga = static_cast<Jogador*>(aux->getData());
                gravaPonto << joga->getId() << ' ' << joga->getPonto() << std::endl;
            }
            aux = aux->getProx();
        }
        gravaPonto.close();
    }
}