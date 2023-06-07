#include "..\Fases\Fase1.h"

namespace Fases
{
	Fase1::Fase1() :
		Fase()
	{
        textura = Grafico::getgrafico()->carregarTextura("Arquivos/Imagens/fundo1.png");
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
        arquivo.open("Arquivos/Fases/Mapa_fase1.txt");
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
}