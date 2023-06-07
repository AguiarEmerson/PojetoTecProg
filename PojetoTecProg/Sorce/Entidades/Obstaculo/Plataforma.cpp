#include "..\Entidades\Obstaculos\Plataforma.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v) :
			Obstaculo(tam,p,v)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/plataforma.png");
			box.setTexture(&textura);
			id = "plataforma";
			estatico = true;
		}
		Plataforma::Plataforma() :
			Obstaculo()
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/plataforma.png");
			box.setTexture(&textura);
      id = "plataforma";
			estatico = true;
		}
		Plataforma::~Plataforma() {

		}
		void Plataforma::colide(Entidade* secundaria, sf::Vector2f ds)
		{
			//ele não colide com o personagem, o personagem colide com ele
		}
		void Plataforma::Executar()
		{
		}

		

	}
}