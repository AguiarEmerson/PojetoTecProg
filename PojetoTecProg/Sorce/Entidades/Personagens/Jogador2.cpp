#include "..\..\..\Include\Entidades\Personagens\Jogador2.h"
namespace Entidades
{
	namespace Personagens
	{
		Jogador2::Jogador2(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h, int xp) :
			Jogador(tam, p, v, h, xp)
		{
			id = "jogador2";
			jogador = NULL;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/jogador2.png");
			box.setTexture(&textura);
		}
		Jogador2::Jogador2() :
			Jogador()
		{
			id = "jogador2";
			jogador = NULL;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/jogador2.png");
			box.setTexture(&textura);
		}
		void Jogador2::move() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				pula();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
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
		void Jogador2::setJogador(Jogador1* joga)
		{
			jogador = joga;
		}
		void Jogador2::controlaCamera()
		{
			if (jogador == NULL || jogador->getVivo() == false)
			{
				Pgrafico->atualizacam(sf::Vector2f(pos.x, TAMW_Y / 2.0));
			}
			else if (vivo == false)
			{
				Pgrafico->atualizacam(sf::Vector2f(jogador->getpos().x, TAMW_Y / 2.0));
			}
			else
			{
				Pgrafico->atualizacam(sf::Vector2f((pos.x + jogador->getpos().x) / 2, TAMW_Y / 2.0));
			}
		}
		void Jogador2::Executar()
		{
			if (vivo == true) {
				move();
				gravidade();
				verificaVida();
			}
			controlaCamera();
		}
		string Jogador2::salvaEnt()
		{
			string aux = criaNomeArquivo();
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi poss�vel salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << pontos << ' ' << std::endl;
			GravadorEnt.close();

			return aux;
		}
		Entidade* Jogador2::carregarEnt(string arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0, acx = 0, acy = 0;
			bool chao = false, move = false, viv = false;
			int dan = 0, num_vida = 0, pont = 0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida >> dan >> acx >> acy >> pont;
			Jogador2* jogador = new Jogador2(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
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
