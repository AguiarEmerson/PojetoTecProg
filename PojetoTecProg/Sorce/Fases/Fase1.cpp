#include "..\Fases\Fase1.h"

namespace Fases
{
	Fase1::Fase1() :
		Fase()
	{
        textura = Grafico::getgrafico()->carregarTextura("Imagens/fundo1.png");
        criaMapa();
        fundo.setTexture(&textura);
	}
	Fase1::~Fase1()
	{
	}

	void Fase1::criaMapa()
	{
        std::ifstream arquivo;
        std::string linha;
        arquivo.open("Arquivos/Mapa_fase1.txt");
        if (!arquivo.is_open()) {
            std::cout << "nao foi possivel abrir o arquivo: Mapa_fase1" << std::endl;
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
    void Fase1::criaEsteira(sf::Vector2f pos)
    {
        Entidades::Obstaculos::Esteira* Esteira =
            new Entidades::Obstaculos::Esteira(sf::Vector2f(50.0, 50.0), pos, sf::Vector2f(0.0, 0.0));
        if (Esteira) {
            lista.incluir(static_cast<Entidade*>(Esteira));
        }
        else {
            std::cout << "ERROR::nao foi possivel criar uma Esteira" << std::endl;
            exit(1);
        }
    }
    void Fase1::criaRoboAnda(sf::Vector2f pos)
    {
        Entidades::Personagens::RoboAnda* RoboAnda =
            new Entidades::Personagens::RoboAnda(sf::Vector2f(50.0, 50.0), pos);
        if (RoboAnda) {
            int i, tam;
            tam = lista.getTam();
            for (i = 0; i < tam; i++) {
                if (lista.getEnt(i)->getId() == "jogador") {
                    RoboAnda->setjogador(static_cast<Jogador*>(lista.getEnt(i)));
                }
            }
            lista.incluir(static_cast<Entidade*>(RoboAnda));
        }
        else {
            std::cout << "ERROR::nao foi possivel criar um RoboAnda" << std::endl;
            exit(1);
        }
    }
	void Fase1::criaEntidade(char id, sf::Vector2i pos)
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
			criaRoboAnda(posAux);
		}
		break;

		case('S'):
		{
			criaRoboPula(posAux);
		}
		break;

		case('%'):
		{
			criaEsteira(posAux);
		}
		break;

		}
	}
}