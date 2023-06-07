#include "..\Entidades\Personagens\Canhao.h"
#include "..\Gerenciadores\Grafico.h"

namespace Entidades
{
	namespace Personagens {
		Canhao::Canhao(sf::Vector2f tam, sf::Vector2f p, sf::Vector2f v, int h) :
			Inimigo(tam, p, v, h),num(num_Canhao),
			projetil(sf::Vector2f(15.0,15.0),sf::Vector2f(p.x,p.y+tam.y+0.5),sf::Vector2f(0.0,0.0))
		{
			textura = Pgrafico->mandaTextura("Imagens/Canhao.png");
			box.setTexture(&textura);
			primeiro_ciclo = 1;
			id = "Canhao";
			num_Canhao++;
		}
		Canhao::Canhao():
			Inimigo(),
			projetil(), num(num_Canhao)
		{
			textura = Pgrafico->mandaTextura("Imagens/Canhao.png");
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

		char* Canhao::salvaEnt()
		{
			string aux = criaNomeArquivo(num);
			char* nomeArquivo = &aux[0];

			std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
			if (!GravadorEnt)
			{

				std::cout << "nao foi poss�vel salvar" << std::endl;
				exit(1);
			}


			return nomeArquivo;
		}
		Entidade* Canhao::carregarEnt(char* arquivo)
		{
			Canhao* canhao = new Canhao;

			std::ifstream RecuperadorEnt(arquivo, std::ios::in);
			if (!RecuperadorEnt)
			{
				std::cout << "nao foi possivel abrir o arquivo" << std::endl;
				exit(1);
			}



			return static_cast<Entidade*>(canhao);
		}


	}
}
int Entidades::Personagens::Canhao::num_Canhao = 0;