#include "..\..\..\Include\Entidades\Personagens\Jogador1.h"
namespace Entidades
{
	namespace Personagens
	{
		Jogador1::Jogador1(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h , int xp ) :
		Jogador(tam,p,v,h,xp)
		{
			id = "jogador1";
			cura = false;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/jogador1.png");
			box.setTexture(&textura);
		
		}
		Jogador1::Jogador1():
		Jogador()
		{
			id = "jogador1";
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
		string Jogador1::salvaEnt()
		{
			string aux = criaNomeArquivo();
			char* nomeArquivo = &aux[0];
			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << pontos <<' ' << std::endl;
			GravadorEnt.close();


			return aux;
		}
		Entidade* Jogador1::carregarEnt(string arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0, acx = 0, acy = 0;
			bool chao = false, move = false, viv = false;
			int dan = 0, num_vida = 0,pont=0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida >> dan >> acx >> acy>>pont;
			Jogador1* jogador = new Jogador1(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
			jogador->setTa_No_Chao(chao);
			jogador->setVivo(viv);
			jogador->setPodeMover(move);
			jogador->setAc(sf::Vector2f(acx, acy));
			jogador->setDano(dan);
			jogador->setPontos(pont);


			RecuperadorEnt.close();
			return static_cast<Entidade*>(jogador);

		}
	}
}
