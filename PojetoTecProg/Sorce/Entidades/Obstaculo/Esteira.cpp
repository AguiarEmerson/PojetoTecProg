#include "..\Entidades\Obstaculos\Esteira.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Esteira::Esteira(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam, p, v)
		{
			direcao = rand() % 2;
			if(direcao)
				textura = Pgrafico->mandaTextura("Imagens/esteirad.png");
			else
				textura = Pgrafico->mandaTextura("Imagens/esteirae.png");
			box.setTexture(&textura);
			id = "Esteira";
			desaceleracao = 2.0f;
		}
		Esteira::Esteira() :
			Obstaculo()
		{
			direcao = rand()%2;
			if (direcao)
				textura = Pgrafico->mandaTextura("Imagens/esteirad.png");
			else
				textura = Pgrafico->mandaTextura("Imagens/esteirae.png");
			box.setTexture(&textura);
			id = "Esteira";
			desaceleracao = 2.0f;
		}
		Esteira::~Esteira() {
		}
		void Esteira::colide(Entidade* secundaria, sf::Vector2f ds)
		{
		}
		void Esteira::Executar()
		{
		}
		void Esteira::colideJogador(Personagem* personagem)
		{
			personagem->setTa_No_Chao(true);
			if(direcao)
				personagem->setAc(sf::Vector2f(personagem->getAc().x + desaceleracao, personagem->getAc().y));
			else
				personagem->setAc(sf::Vector2f(personagem->getAc().x - desaceleracao, personagem->getAc().y));

		}
		char* Esteira::salvaEnt()
		{
			char* oi = 0;
			return oi;
		}
	}
}
