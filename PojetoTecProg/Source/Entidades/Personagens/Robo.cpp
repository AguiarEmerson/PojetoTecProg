#include "..\..\..\Include\Entidades\Personagens\robo.h"
namespace Entidades
{
	namespace Personagens
	{
		robo::robo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h , int xp ) :
		Jogador(tam,p,v,h,xp)
		{
			id = "robo";
			sozinho = false;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/robo.png");
			box.setTexture(&textura);
		
		}
		robo::robo():
		Jogador()
		{
			id = "robo";
			sozinho = false;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/robo.png");
			box.setTexture(&textura);
		}
		robo::~robo()
		{}
		void robo::move() {
			vel.x = 0.0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				pula();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				vel.x = -VELOCIDADEJOGADOR;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				vel.x = VELOCIDADEJOGADOR;
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
		void robo::Executar()
		{
			if (vivo == true&&!ganhouFase) {
				verificaGanhou();
				move();
				atualizaposicao();
				verificaVida();
			}
		}
		string robo::salvaEnt()
		{
			string aux = criaNomeArquivo();
			char* nomeArquivo = &aux[0];
			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi poss�vel salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << pontos <<' ' << ganhouFase<<' '<<std::endl;
			GravadorEnt.close();


			return aux;
		}
		Entidade* robo::carregarEnt(string arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0, acx = 0, acy = 0;
			bool chao = false, move = false, viv = false,ganhou=false;
			int dan = 0, num_vida = 0,pont=0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida >> dan >> acx >> acy>>pont>>ganhou;
			robo* jogador = new robo(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
			jogador->setTa_No_Chao(chao);
			jogador->setVivo(viv);
			jogador->setPodeMover(move);
			jogador->setAc(sf::Vector2f(acx, acy));
			jogador->setDano(dan);
			jogador->setPontos(pont);
			jogador->setGanhou(ganhou);


			RecuperadorEnt.close();
			return static_cast<Entidade*>(jogador);

		}
	}
}
