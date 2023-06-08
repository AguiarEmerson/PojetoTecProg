#include "..\..\..\Include\Entidades\Personagens\Jogador1.h"
namespace Entidades
{
	namespace Personagens
	{
		Jogador1::Jogador1(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h , int xp ) :
		Jogador(tam,p,v,h,xp)
		{
			cura = false;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/jogador1.png");
			box.setTexture(&textura);
		
		}
		Jogador1::Jogador1():
		Jogador()
		{
			cura = false;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/jogador1.png");
			box.setTexture(&textura);
		}
		Jogador1::~Jogador1()
		{}
		void Jogador1::move() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				pula();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (!(ac.x >= -0.5 && ac.x <= 0.5))
			{
				pos = pos - ac;

				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
			}
		}
		void Jogador1::Executar()
		{
			if (vivo == true) {
				move();
				gravidade();
				verificaVida();
			}
		}
		char* Jogador1::salvaEnt()
		{
			string aux = criaNomeArquivo();
			char* nomeArquivo = &aux[0];
			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}


			return nomeArquivo;
		}
		Entidade* Jogador1::carregarEnt(char* arquivo)
		{
			Jogador1* jogador = new Jogador1;

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}



			return static_cast<Entidade*>(jogador);

		}
	}
}
