#include "Espinho.h"
namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v)
		{
			dt = 0.0f;
			danoso = true;
			dano = 1;
			id = "espinho";
		}
		Espinho::Espinho() :
			Obstaculo()
		{
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
			dt = relogio.getElapsedTime().asSeconds();
		}
		void Espinho::colide(Entidade* secundaria, sf::Vector2f ds) {

		}
		void Espinho::danoPersonagem(Personagem* personagem) {
			if (dt >= 8) {
				personagem->tomaDano(dano);
				relogio.restart();
			}


		}

	}
}