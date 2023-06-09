#include "../Entidades/Projetil.h"

namespace Entidades
{
	Projetil::Projetil(sf::Vector2f tam, sf::Vector2f p , sf::Vector2f v ):
		Entidade(tam,p,v),num(num_Projetil)
	{
		textura = Pgrafico->mandaTextura("Arquivos/Imagens/projetil.png");
		box.setTexture(&textura);
		dano = 1;
		existe = false;
		id = "projetil";
		num_Projetil++;
	}
	Projetil::Projetil():
		Entidade(), num(num_Projetil)
	{
		textura = Pgrafico->mandaTextura("Arquivos/Imagens/projetil.png");
		box.setTexture(&textura);
		dano = 1;
		existe = false;
		id = "projetil";
		num_Projetil++;
	}
	Projetil::~Projetil()
	{
	}
	void Projetil::colide(Entidade* secundaria, sf::Vector2f ds)
	{

	}
	void Projetil::move()
	{
		setpos(sf::Vector2f(pos.x + vel.x, pos.y));
	}
	void Projetil::Executar()
	{
		move();
		atualizaposicao();
	}
	const bool Projetil::verificaExiste() 
	{
		return existe;
	}
	void Projetil::setExiste(const bool existindo) 
	{
		existe = existindo;
	}
	void Projetil::atualizaExiste() 
	{
		if (pos.y > 590) {
			existe = false;
		}
	}
	void Projetil::reiniciaProjetil(const sf::Vector2f novapos, const sf::Vector2f novavel)
	{
		pos = novapos;
		vel = novavel;
		existe = true;
	}
	const int Projetil::getDano()
	{
		return dano;
	}

	string Projetil::salvaEnt()
	{
		string aux = criaNomeArquivo(num);
		char* nomeArquivo = &aux[0];
		std::ofstream GravadorEnt(nomeArquivo, std::ios::out);
		if (!GravadorEnt)
		{

			std::cout << "nao foi poss�vel salvar" << std::endl;
			exit(1);
			
		}
		GravadorEnt<< box.getSize().x <<' '<<box.getSize().y<<' ' << pos.x << ' ' << pos.y << ' ' << vel.x << ' ' << vel.y << ' ' << ta_no_chao << ' ' << podeMover << ' ' << vivo << ' ' << existe << ' ' << dano << std::endl;

		GravadorEnt.close();
		return aux;
	}
	Entidade* Projetil::carregarEnt(string arquivo)
	{

		std::ifstream RecuperadorEnt(arquivo, std::ios::in);
		if (!RecuperadorEnt)
		{
			std::cout << "nao foi possivel abrir o arquivo" << std::endl;
			exit(1);
		}
		float posx = 0, posy = 0, velx = 0, vely = 0,tamx=0,tamy=0;
		bool chao = false, move = false,viv = false,exis=false;
		int dan = 0;
		RecuperadorEnt >> tamx>> tamy>>posx >> posy >> velx >> vely >> chao >> move >> viv >> exis>>dan;
		Projetil* projetil = new Projetil(sf::Vector2f(tamx,tamy), sf::Vector2f(posx, posy), sf::Vector2f(velx, vely));
		projetil->setTa_No_Chao(chao);
		projetil->setVivo(viv);
		projetil->setPodeMover(move);
		projetil->setExiste(exis);
		projetil->setDano(dan);

		RecuperadorEnt.close();
		return static_cast<Entidade*>(projetil);

	}
	void Projetil::setDano(int dan)
	{
		dano = dan;
	}

	const bool Projetil::getExiste()
	{
		return existe;
	}

	const bool Projetil::getTanoChao()
	{
		return ta_no_chao;
	}

	const bool Projetil::getMove()
	{
		return podeMover;
	}
	void Projetil::setTextura()
	{
		textura = Pgrafico->mandaTextura("Arquivos/Imagens/projetil.png");
		box.setTexture(&textura);
	}
	
}
int Entidades::Projetil::num_Projetil = 0;
