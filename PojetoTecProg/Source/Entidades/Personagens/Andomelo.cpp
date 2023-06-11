#include "..\Entidades\Personagens\andomelo.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		andomelo::andomelo(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v , int h) :
			Inimigo(tam, p, v, h),num(num_andomelo)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/andomelo.png");
			box.setTexture(&textura);
			id = "andomelo";
			direcao = rand() % 2;
			num_andomelo++;
			ponto = 100;
		}
		andomelo::andomelo():
			Inimigo(), num(num_andomelo)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/andomelo.png");
			box.setTexture(&textura);
			direcao = rand() % 2;
			id = "andomelo";
			num_andomelo++;

		}
		andomelo::~andomelo()
		{
			listaJogador.clear();
		}


		void andomelo::setjogador(Jogador* j)
		{
			listaJogador.push_back (j);
		}

		void andomelo::moveraleatorio()
		{
			if (direcao == 0)
			{
				vel.x = VELOCIDADEINIMIGO;
			}
			if (direcao == 1)
			{
				vel.x = -VELOCIDADEINIMIGO;
			}

			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
			if (dt >= TEMPOandomelo) {
				direcao = rand() % 2;
				tempo_total += TEMPOandomelo;
			}
		}

		void andomelo:: move()
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

		void andomelo::Perseguir()
		{
			if (podeMover) {
				if (decideJogador()->getpos().x > pos.x)
				{
					vel.x = VELOCIDADEINIMIGO;
				}
				if (decideJogador()->getpos().x < pos.x)
				{
					vel.x = -VELOCIDADEINIMIGO;
				}
			}

		}

		void andomelo::Executar()
		{
			primTempoTotal();
			move();
			atualizaposicao();
			verificaVida();
		}

		Jogador* andomelo::decideJogador()
		{
			if (listaJogador.front()->getVivo() == true)
				return listaJogador.front();
			else
				return listaJogador.back();
		}
		string andomelo::salvaEnt()
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
		Entidade* andomelo::carregarEnt(string arquivo)
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
			andomelo* andomelo = new Entidades::andomelo(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely), num_vida);
			andomelo->setTa_No_Chao(chao);
			andomelo->setVivo(viv);
			andomelo->setPodeMover(move);
			andomelo->setAc(sf::Vector2f(acx, acy));
			andomelo->setDirecao(direca);
			andomelo->setDano(dan);

			RecuperadorEnt.close();
			return static_cast<Entidade*>(andomelo);

		}
	}
}
int Entidades::Personagens::andomelo::num_andomelo = 0;