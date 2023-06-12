#include "..\..\..\Include\Entidades\Personagens\zoiudo.h"
namespace Entidades
{
	namespace Personagens
	{
		zoiudo::zoiudo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h, int xp) :
			Jogador(tam, p, v, h, xp)
		{
			id = "zoiudo";
			jogador = NULL;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/zoiudo.png");
			box.setTexture(&textura);
		}
		zoiudo::zoiudo() :
			Jogador()
		{
			id = "zoiudo";
			jogador = NULL;
			textura = Pgrafico->carregarTextura("Arquivos/Imagens/zoiudo.png");
			box.setTexture(&textura);
		}
		void zoiudo::move() {
			vel.x = 0.0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				pula();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				vel.x = -VELOCIDADEJOGADOR;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
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
		void zoiudo::setJogador(robo* joga)
		{
			jogador = joga;
		}
		void zoiudo::controlaCamera()
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
		void zoiudo::Executar()
		{
			if (vivo == true&&!ganhouFase) {
				verificaGanhou();
				move();
				atualizaposicao();
				verificaVida();
			}
			controlaCamera();
		}
		string zoiudo::salvaEnt()
		{
			string aux = criaNomeArquivo();
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << pontos << ' ' << std::endl;
			GravadorEnt.close();

			return aux;
		}
		Entidade* zoiudo::carregarEnt(string arquivo)
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
			zoiudo* jogador = new zoiudo(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
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
