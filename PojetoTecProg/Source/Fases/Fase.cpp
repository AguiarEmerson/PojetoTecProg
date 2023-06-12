#include "..\Fases\Fase.h"


namespace Fases
{
	Gerenciadores::MaquinadeEstados* Fase::pMaquinadeEstados = Gerenciadores::MaquinadeEstados::getMaquinadeEstados();

	Fase::Fase() :
		Ente(), lista()
	{
		if (Pgrafico == nullptr) {
			std::cout << "ERROR nao foi possivel criar o GerenciadorGrafico" << std::endl;
			exit(1);
		}
		fundo = sf::RectangleShape(sf::Vector2f(1000.0f, 600.0f));
		primeiroCiclo = true;
		i = 0;
		srand(Pgrafico->getrelogio().getElapsedTime().asSeconds());
		num_saltitos = 2+rand()%6;
		ganhoFase = 0;
		perdeu = false;
		
		
	}
	Fase::~Fase()
	{
	}

	

	void Fase::criarobo(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador* jogador = 
			new Entidades::Personagens::robo(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(0.0, 0.0));
		if (jogador) {
			int i, tam;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "robo") {
					std::cout << "nao foi possivel gerar a fase pois o jogador 2 esta depois do 1" << std::endl;
					exit(1);
				}
			}
			lista.incluir(static_cast<Entidade*>(jogador));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um jogador" << std::endl;
			exit(1);
		}
	}
	void Fase::criazoiudo(sf::Vector2f pos)
	{
		Entidades::Personagens::zoiudo* jogador =
			new Entidades::Personagens::zoiudo(sf::Vector2f(50.0, 50.0), pos, sf::Vector2f(0.0, 0.0));
		if (jogador) {
			int i, tam;
			bool achoJogador = false;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "robo") {
					achoJogador = 1;
					jogador->setJogador(static_cast<robo*>(lista.getEnt(i)));
				}
			}
			if (achoJogador == false)
			{
				jogador->setJogador(NULL);
			}
			lista.incluir(static_cast<Entidade*>(jogador));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar um jogador" << std::endl;
			exit(1);
		}
	}

	void Fase::criaPlataforma(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Plataforma* plataforma =
			new Entidades::Obstaculos::Plataforma(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(0.0,0.0));
		if (plataforma) {
			lista.incluir(static_cast<Entidade*>(plataforma));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma plataforma" << std::endl;
			exit(1);
		}
	}

	void Fase::criaTrampolim(sf::Vector2f pos)
	{
		Entidades::Obstaculos::Trampolim* trampolim =
			new Entidades::Obstaculos::Trampolim(20.0, sf::Vector2f(50.0,50.0),pos);
		if (trampolim) {
			lista.incluir(static_cast<Entidade*>(trampolim));
		}
		else {
			std::cout << "ERROR::nao foi possivel criar uma trampolim" << std::endl;
			exit(1);
		}
	}

	void Fase::criasaltitos(sf::Vector2f pos)
	{
		Entidades::Personagens::saltitos* saltitos = 
			new Entidades::Personagens::saltitos(sf::Vector2f (50.0,50.0),pos);
		if (saltitos&&i<num_saltitos) {
			lista.incluir(static_cast<Entidade*>(saltitos));
			i++;
		}
		else if(!saltitos){
			std::cout << "ERROR::nao foi possivel criar um saltitos" << std::endl;
			exit(1);
		}
	}
	void Fase::setFundo(sf::Vector2f posicao)
	{
		fundo.setPosition(posicao);
	}
	sf::RectangleShape Fase::getFundo()
	{
		return fundo;
	}
	int Fase::getTam()
	{
		return lista.getTam();
	}
	
	string Fase:: salvaEnt(int i)
	{
		return lista.getEnt(i)->salvaEnt();
	}
	string Fase::getId(int i)
	{
		return lista.getEnt(i)->getId();
	}
	void Fase::deletaSave()
	{
		std::ifstream Deletasave("fase.dat", std::ios::in);
		if (!Deletasave)
		{
		}
		else
		{
			string i, nomeArq;
			char* nomeArquivo;
			Deletasave >> i;
			while (!Deletasave.eof())
			{
				Deletasave >> i >> nomeArq;
				nomeArquivo = &nomeArq[0];
				remove(nomeArquivo);
			}
			Deletasave.close();
			remove("fase.dat");
		}
	}
	void Fase::carregaSave()
	{
		std::ifstream carregasave("fase.dat", std::ios::in);
		if (!carregasave)
		{
			std::cout << "nao existe save" << std::endl;
		}
		else
		{
			string id;
			string nomeArquivo;
			carregasave >> id;
			while (!carregasave.eof())
			{
				carregasave >> id >> nomeArquivo;
				if (id == "espinho")
					lista.incluir(Espinho::carregarEnt(nomeArquivo));
				else if (id == "Esteira")
					lista.incluir(Esteira::carregarEnt(nomeArquivo));
				else if (id == "plataforma")
					lista.incluir(Plataforma::carregarEnt(nomeArquivo));
				else if (id == "trampolim")
					lista.incluir(Trampolim::carregarEnt(nomeArquivo));
				else if (id == "Canhao") {
					Entidade* entidade = NULL;
					entidade=Canhao::carregarEnt(nomeArquivo);
					Canhao* canhao = NULL;
					canhao = static_cast<Canhao*>(entidade);
					int i;
					bool achoProjetil = false;
					for (i = lista.getTam()-1; i >= 0 && achoProjetil == false; i--)
					{
						if (lista.getEnt(i)->getId() == "projetil") {
							achoProjetil= 1;
							canhao->setProjetil(static_cast<Projetil*>(lista.getEnt(i)));
							lista.retirar(lista.getEnt(i));
						}
					}
					lista.incluir(static_cast<Entidade*>(canhao->getProjetil()));
					lista.incluir(entidade);
				}
				else if (id == "robo")
					lista.incluir(robo::carregarEnt(nomeArquivo));
				else if (id == "zoiudo") {
					Entidade* entidade = NULL;
					entidade=zoiudo::carregarEnt(nomeArquivo);
					zoiudo* jogador = NULL;
					jogador = static_cast<zoiudo*>(entidade);
					int i, tam;
					bool achoJogador = false;
					tam = lista.getTam();
					for (i = 0; i < tam; i++) {
						if (lista.getEnt(i)->getId() == "robo") {
							achoJogador = 1;
							jogador->setJogador(static_cast<robo*>(lista.getEnt(i)));
						}
					}
					if (achoJogador == false)
					{
						jogador->setJogador(NULL);
					}
					lista.incluir(entidade);
					
				}
				else if (id == "andomelo") {
					Entidade* entidade = NULL;
					entidade=andomelo::carregarEnt(nomeArquivo);
					andomelo* andomelo=NULL;
					andomelo = static_cast<Personagens::andomelo*>(entidade);
					int i, tam;
					bool achoJogador = false;
					tam = lista.getTam();
					for (i = 0; i < tam&&!achoJogador; i++) {
						if (lista.getEnt(i)->getId() == "robo"||lista.getEnt(i)->getId()=="zoiudo") {
							achoJogador = true;
							andomelo->setjogador(static_cast<Jogador*>(lista.getEnt(i)));
						}
					}
					lista.incluir(entidade);
				}
				else if (id == "saltitos")
					lista.incluir(saltitos::carregarEnt(nomeArquivo));
				else if (id == "projetil")
					lista.incluir(Projetil::carregarEnt(nomeArquivo));
				
			}
			Pgrafico->setLista(&lista);
			colisoes.setLista(&lista);
			carregasave.close();
		}
	}
	void Fase::verificaPerdeu()
	{
		Lista<Entidade>::Elemento<Entidade>* aux;
		aux = lista.getPrim();
		int i, tam = lista.getTam();
		perdeu=0;
		for (i = 0; i < tam; i++)
		{
			if (aux->getData()->getId() == "robo" || aux->getData()->getId() == "zoiudo")
			{
				if (aux->getData()->getVivo() == false)
					perdeu= 1;

			}
			aux = aux->getProx();
		}
	}
	const bool Fase::getPerdeu()
	{
		return perdeu;
	}
	

}