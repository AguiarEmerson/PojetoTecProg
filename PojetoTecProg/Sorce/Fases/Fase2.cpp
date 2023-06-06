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
        arquivo.open("Arquivos/Mapa_fase2.txt");
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
}