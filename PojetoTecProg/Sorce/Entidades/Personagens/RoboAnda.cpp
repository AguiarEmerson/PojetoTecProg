#include "..\Entidades\Personagens\RoboAnda.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		RoboAnda::RoboAnda(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h) :
			Inimigo(tam, p, v, h),num(num_RoboAnda)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/RoboAnda.png");
			box.setTexture(&textura);
			id = "RoboAnda";
			direcao = rand() % 2;
			num_RoboAnda++;
		}
		RoboAnda::RoboAnda():
			Inimigo(), num(num_RoboAnda)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/RoboAnda.png");
			box.setTexture(&textura);
			direcao = rand() % 2;
			id = "RoboAnda";
			num_RoboAnda++;

		}
		RoboAnda::~RoboAnda()
		{
			listaJogador.clear();
		}


		void RoboAnda::setjogador(Jogador* j)
		{
			listaJogador.push_back (j);
		}

		void RoboAnda::moveraleatorio()
		{
			if (direcao == 0)
			{
				setpos(sf::Vector2f(pos.x + vel.x, pos.y));
			}
			if (direcao == 1)
			{
				setpos(sf::Vector2f(pos.x - vel.x, pos.y));
			}

			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
			if (dt >= TEMPORoboAnda) {
				direcao = rand() % 2;
				tempo_total += TEMPORoboAnda;
			}
		}

		void RoboAnda:: move()
		{
			if (!(ac.x >= -0.5 && ac.x <= 0.5 && ac.y >= -0.5 && ac.y <= 0.5))
			{
				pos = pos - ac;

				if (ac.x < 0)
					ac.x += 0.5;
				else
					ac.x -= 0.5;
				if (ac.y < 0)
					ac.y += 0.5;
				else
					ac.y -= 0.5;
			}
			sf::Vector2f posjogador = decideJogador()->getpos();
			if (fabs(posjogador.x - pos.x) < RAIO_VISAO && fabs(posjogador.y - pos.y) < RAIO_VISAO)
			{
				Perseguir();
			}
			else
				moveraleatorio();
		}

		void RoboAnda::Perseguir()
		{
			if (podeMover) {
				if (decideJogador()->getpos().x > pos.x)
				{
					setpos(sf::Vector2f(pos.x + vel.x, pos.y));
				}
				if (decideJogador()->getpos().x < pos.x)
				{
					setpos(sf::Vector2f(pos.x - vel.x, pos.y));
				}
			}

		}

		void RoboAnda::Executar()
		{
			primTempoTotal();
			move();
			gravidade();
			verificaVida();
		}
		Jogador* RoboAnda::decideJogador()
		{
			if (listaJogador.front()->getVivo() == true)
				return listaJogador.front();
			else
				return listaJogador.back();
		}
		string RoboAnda::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << num_vidas << ' ' << dano << ' ' << ac.x << ' ' << ac.y << ' ' << direcao << std::endl;

			GravadorEnt.close();
			return aux;
		}
		Entidade* RoboAnda::carregarEnt(char* arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0, acx = 0, acy = 0;
			bool chao = false, move = false, viv = false;
			int dan = 0, num_vida = 0, direca = 0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida >> dan >> acx >> acy >> direca;
			RoboAnda* roboAnda = new RoboAnda(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
			roboAnda->setTa_No_Chao(chao);
			roboAnda->setVivo(viv);
			roboAnda->setPodeMover(move);
			roboAnda->setAc(sf::Vector2f(acx, acy));
			roboAnda->setDirecao(direca);
			roboAnda->setDano(dan);

			RecuperadorEnt.close();
			return static_cast<Entidade*>(roboAnda);

		}
	}
}
int Entidades::Personagens::RoboAnda::num_RoboAnda = 0;