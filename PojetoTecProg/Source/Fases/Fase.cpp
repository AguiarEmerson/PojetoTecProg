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
		num_RoboPula = 2+rand()%6;
		num_Obstaculo = 2+rand()%6;
		j = 0;
		
	}
	Fase::~Fase()
	{
	}

	

	void Fase::criaJogador1(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador* jogador = 
			new Entidades::Personagens::Jogador1(sf::Vector2f(50.0,50.0),pos,sf::Vector2f(3.0, 0.0));
		if (jogador) {
			int i, tam;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "jogador1") {
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
	void Fase::criaJogador2(sf::Vector2f pos)
	{
		Entidades::Personagens::Jogador2* jogador =
			new Entidades::Personagens::Jogador2(sf::Vector2f(50.0, 50.0), pos, sf::Vector2f(3.0, 0.0));
		if (jogador) {
			int i, tam;
			bool achoJogador = false;
			tam = lista.getTam();
			for (i = 0; i < tam; i++) {
				if (lista.getEnt(i)->getId() == "jogador1") {
					achoJogador = 1;
					jogador->setJogador(static_cast<Jogador1*>(lista.getEnt(i)));
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

	void Fase::criaRoboPula(sf::Vector2f pos)
	{
		Entidades::Personagens::RoboPula* RoboPula = 
			new Entidades::Personagens::RoboPula(sf::Vector2f (50.0,50.0),pos);
		if (RoboPula&&i<num_RoboPula) {
			lista.incluir(static_cast<Entidade*>(RoboPula));
			i++;
		}
		else if(!RoboPula){
			std::cout << "ERROR::nao foi possivel criar um RoboPula" << std::endl;
			exit(1);
		}
	}
	void Fase::Executar()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			pMaquinadeEstados->incluir("Menu_pausa");
		}
		if (primeiroCiclo)
		{
			primeiroCiclo = false;
			Grafico::getgrafico()->setFundo(fundo);
		}
		//desenha o fundo
		Pgrafico->atualizaFundo();
		//executa todas as entidades
		lista.percorrer();
		//desenha todas as entidades
		lista.desenhar();
		//verifica as colisoes
		colisoes.executar();
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
			std::cout << "nao existe save" << std::endl;
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
				else if (id == "jogador1")
					lista.incluir(Jogador1::carregarEnt(nomeArquivo));
				else if (id == "jogador2") {
					Entidade* entidade = NULL;
					entidade=Jogador2::carregarEnt(nomeArquivo);
					Jogador2* jogador = NULL;
					jogador = static_cast<Jogador2*>(entidade);
					int i, tam;
					bool achoJogador = false;
					tam = lista.getTam();
					for (i = 0; i < tam; i++) {
						if (lista.getEnt(i)->getId() == "jogador1") {
							achoJogador = 1;
							jogador->setJogador(static_cast<Jogador1*>(lista.getEnt(i)));
						}
					}
					if (achoJogador == false)
					{
						jogador->setJogador(NULL);
					}
					lista.incluir(entidade);
					
				}
				else if (id == "RoboAnda") {
					Entidade* entidade = NULL;
					entidade=RoboAnda::carregarEnt(nomeArquivo);
					RoboAnda* roboAnda=NULL;
					roboAnda = static_cast<RoboAnda*>(entidade);
					int i, tam;
					bool achoJogador = false;
					tam = lista.getTam();
					for (i = 0; i < tam&&!achoJogador; i++) {
						if (lista.getEnt(i)->getId() == "jogador1"||lista.getEnt(i)->getId()=="Jogador2") {
							achoJogador = 1;
							roboAnda->setjogador(static_cast<Jogador*>(lista.getEnt(i)));
						}
					}
					lista.incluir(entidade);
				}
				else if (id == "RoboPula")
					lista.incluir(RoboPula::carregarEnt(nomeArquivo));
				else if (id == "projetil")
					lista.incluir(Projetil::carregarEnt(nomeArquivo));
				
			}
			Pgrafico->setLista(&lista);
			colisoes.setLista(&lista);
			carregasave.close();
		}
	}

}