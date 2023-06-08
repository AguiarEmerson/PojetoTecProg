#include "..\Entidades\Personagens\Canhao.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Canhao::Canhao(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),num(num_Canhao),
			projetil(sf::Vector2f(15.0,15.0),sf::Vector2f(p.x,p.y+tam.y+0.5),sf::Vector2f(0.0,0.0))
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/Canhao.png");
			box.setTexture(&textura);
			primeiro_ciclo = 1;
			id = "Canhao";
			num_Canhao++;
		}
		Canhao::Canhao():
			Inimigo(),
			projetil(), num(num_Canhao)
		{
			textura = Pgrafico->mandaTextura("Arquivos/Imagens/Canhao.png");
			box.setTexture(&textura);
			id = "Canhao";
			num_Canhao++;
		}
		Canhao::~Canhao()
		{
		}

		void Canhao::move() {

	
			dt = Pgrafico->getrelogio().getElapsedTime().asSeconds()-tempo_total;
			if (dt >= TEMPOMOVECanhao / 2 &&dt<= TEMPOMOVECanhao) {
				direcao = rand() % 2;
			}
			else if (dt <= TEMPOMOVECanhao/2)
			{
				if (direcao == 1)
					setpos(sf::Vector2f(getpos().x + getvel().x, getpos().y));
				if (direcao == 0)
					setpos(sf::Vector2f(getpos().x - getvel().x, getpos().y));
			}
			else {
				tempo_total += TEMPOMOVECanhao;
			}
		}
		void Canhao::Executar()
		{
			primTempoTotal();
			controlaProjetil();
			move();
			gravidade();
			verificaVida();
		}

		void Canhao::controlaProjetil()
		{
			projetil.atualizaExiste();
			if (projetil.verificaExiste() == false&&vivo==1)
			{
				sf::Vector2f novapos;
				sf::Vector2f novavel;
				int direcao;
				direcao = rand() % 2;
				novapos.x = pos.x + rand() % int(getTam().x - projetil.getTam().x);
				novapos.y = pos.y - (projetil.getTam().y + 1.0f);
				if (direcao == 1) 
					novavel.x = (rand() % 5)+VELMINPROJETILX;
				
				else
					novavel.x = ( - rand() % 5 )- VELMINPROJETILX;
				novavel.y = -((rand() % 5) + VELMINPROJETILY);

				projetil.reiniciaProjetil(novapos, novavel);
			}
		}
		Projetil* Canhao::getProjetil()
		{
			return &projetil;
		}

		string Canhao::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi possível salvar" << std::endl;
				exit(1);
			}
			GravadorEnt << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo <<' '<< num_vidas <<' '<< dano <<' '<< ac.x <<' '<< ac.y << ' ' << direcao << std::endl;

			GravadorEnt.close();


			return aux;
		}
		Entidade* Canhao::carregarEnt(char* arquivo)
		{

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}
			float posx = 0, posy = 0, velx = 0, vely = 0,acx=0,acy=0;
			bool chao = false, move = false, viv = false;
			int dan = 0, num_vida = 0, direca = 0;
			RecuperadorEnt >> posx >> posy >> velx >> vely >> chao >> move >> viv >> num_vida>>dan>>acx>>acy>>direca;
			Canhao* canhao = new Canhao(sf::Vector2f(50.0, 50.0), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely),num_vida);
			canhao->setTa_No_Chao(chao);
			canhao->setVivo(viv);
			canhao->setPodeMover(move);
			canhao->setAc(sf::Vector2f(acx, acy));
			canhao->setDirecao(direca);
			canhao->setDano(dan);


			RecuperadorEnt.close();
			return static_cast<Entidade*>(canhao);
		}


	}
}
int Entidades::Personagens::Canhao::num_Canhao = 0;