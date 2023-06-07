#include "..\..\..\Include\Entidades\Obstaculos\Espinho.h"
#include "..\Gerenciadores\Grafico.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v)
		{
			textura = Pgrafico->mandaTextura("Imagens/espinho.png");
			box.setTexture(&textura);
			dt = 0.0f;
			danoso = true;
			dano = 1;
			id = "espinho";
		}
		Espinho::Espinho() :
			Obstaculo()
		{
			textura = Pgrafico->mandaTextura("Imagens/espinho.png");
			box.setTexture(&textura);
			dt = 0.0f;
			danoso = true;
			dano = 1;
			id = "espinho";
		}
		Espinho::~Espinho()
		{
		}
		void Espinho::Executar()
		{	
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
		}
		void Espinho::colide(Entidade* secundaria, sf::Vector2f ds) {

		}
		void Espinho::danoPersonagem(Personagem* personagem) {
			if (dt >= TEMPOESPINHO) {
				personagem->tomaDano(dano);
				tempo_total+=TEMPOESPINHO;
			}


		}

		void Espinho::primTempoTotal() {
			if (primeiro_ciclo)
			{
				primeiro_ciclo = 0;
				tempo_total = Pgrafico->getrelogio().getElapsedTime().asSeconds();
			}
		}
		char* Espinho::salvaEnt()
		{
		}
	}
}